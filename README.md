WiFi, RFID, Server, and Door Unlock System:

This project enables secure door unlocking using an RFID reader connected to a WiFi-enabled microcontroller (ESP8266/ESP32). The system reads RFID tags, sends the data to a server for authentication, and triggers a relay to unlock the door when access is granted. The microcontroller connects to a WiFi network, and the server can be hosted locally or in the cloud to handle RFID verification. To set up, wire the RFID reader to the microcontroller’s SPI pins and the relay to a digital pin. After configuring the code with your WiFi credentials and server URL, upload it via the Arduino IDE. When an authorized RFID tag is scanned, the door unlocks briefly, allowing access.

Components:
ESP8266/ESP32
MFRC522 RFID reader
Relay module
Server (locally hosted or cloud)
Door lock mechanism

Libraries needed:
ESP8266WiFi or WiFi.h (for ESP32)
MFRC522 (RFID reader)
SPI (for RFID communication)
HTTPClient (for HTTP requests to the server)
