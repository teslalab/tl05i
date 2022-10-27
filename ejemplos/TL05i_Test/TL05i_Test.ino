/*************************************************** 
Ejemplo para el uso del sensor TL05i por Angel Isidro - Tesla Lab Utilizando la libreria "Adafruit SHT31"
El TL05i es un sensor de temperatura basado en el sensor SHT30 de la serie SHT3x 
del fabricante SENSIRION.
Este sensor funciona por el protocolo de comunicación I2C y su dirección I2C es 0x44
Puede verificar el DataSheet en el siguiente LINK -->
 https://github.com/teslalab/tl05i/blob/main/Sensirion_Humidity_Sensors_SHT3x_Datasheet.pdf
♥♥♥ Open source Hardaware / Software para todos ♥♥♥ 
****************************************************/
 
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

bool enableHeater = false;
uint8_t loopCnt = 0;

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(9600);

  while (!Serial)
    delay(10);     //Preparamos el Puerto serial 
  Serial.println("TL05i test");
  if (! sht31.begin(0x44)) {   // Si la dirección I2C esta ocupada verique el DataSheet para el uso de la dirección alternativa 0x45
    Serial.println("No se puede encontrar el TL05i");
    while (1) delay(1);
  }

  Serial.print("EStadi de activación del calentador: ");
  if (sht31.isHeaterEnabled())
    Serial.println("Habilitado");
  else
    Serial.println("Deshabilitado");
}


void loop() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  if (! isnan(t)) {  // Revisamos si esto no es un número
    Serial.print("Temp *C = "); Serial.print(t); Serial.print("\t\t");
  } else { 
    Serial.println("No se puede leer la Temperatura");
  }
  
  if (! isnan(h)) {  // Revisamos si esto no es un número
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println("No se puede leer la Humedad");
  }

  delay(1000);

  // Toggle heater enabled state every 30 seconds
  // An ~3.0 degC temperature increase can be noted when heater is enabled
  if (++loopCnt == 30) {
    enableHeater = !enableHeater;
    sht31.heater(enableHeater);
    Serial.print("Heater Enabled State: ");
    if (sht31.isHeaterEnabled())
      Serial.println("ENABLED");
    else
      Serial.println("DISABLED");

    loopCnt = 0;
  }
}