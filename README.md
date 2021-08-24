# TL05i Sensor de Temperatura / Humedad

![](/img/tl05i.png)


Sensor de temperatura y Humedads diseñado por Ángel Isidro, diseñador de dispostivos electrónicos en el laboratorio de investigación y desarrollo Tesla Lab de Universidad Galileo.

Este dispositivo está basado en el sensor de temperatura SHT30 de la marca sensirion, fue diseñado para ser utilizado en el Encuentro Nacional de Robótica BALAM en su edición 2021.

# ¿En donde puedo adquirir el sensor TL05i?

El sensor TL05i se encuentra disponible en Guatemala en la tienda de Electrónica Tettsa, para más información acerca de costos y existencias visite el siguiente [LINK][tienda.tettsa].

[tienda.tettsa]: https://www.tienda.tettsa.gt/

# ¿Cómo funciona?

El sensor TL05i funciona por medio del protocolo de comunicación I2C para cualquier dispositivo que soporte este protocolo de comunicación.

# Dispositivos compatibles

A continuación detallamos un listado de tarjetas con las cuales ya fue probado el dispositivo TL05i y funciona correctamente.

- ESP32
- ESP8266
- Feather 32u4


# Descripción de pines 

### Temperatura, humedad - Comunicación I2C
TL05i | PIN
--- | ---
VCC | 3V3 - 5V
GND | GND
SCL | Serial Clock
SDA | Serial Data 

# Licencia

Hardware License: CERN OHL v1.0 para más información visitar el siguiente [Link][CERN_v1].

[CERN_v1]: https://ohwr.org/project/cernohl/wikis/Documents/CERN-OHL-version-1.2

Software License: GPL v3

Documentation License: CC BY 4.0 International
