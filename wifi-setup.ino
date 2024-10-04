#include <SPI.h>
#include <RFID.h>

#define SS_PIN D4
#define RST_PIN D3
#define RELAY_PIN D2 // Pin connected to the relay

RFID rfid(SS_PIN, RST_PIN);

// Setup variables:
const int MAX_REGISTERED_CARDS = 3;
const String registeredUIDs[MAX_REGISTERED_CARDS] = {
"93-94-17-a3-b3", //keychain : blue
"89-c8-b0-b2-43", // card RFID  
"11-22-33-FF-EE" // available 
};

code rfid

void loop()
{
if (rfid.isCard())
{
if (rfid.readCardSerial())
{
Serial.println(" ");
Serial.println("Card found");

String UIDcard = String(rfid.serNum[0], HEX) + "-" + String(rfid.serNum[1], HEX) + "-" + String(rfid.serNum[2], HEX) + "-" + String(rfid.serNum[3], HEX) + "-" + String(rfid.serNum[4], HEX);

if (isRegisteredUID(UIDcard))
{
Serial.println("Registered card detected: " + UIDcard);

Serial.print("connecting to ");
Serial.println(host);

if (!client.connect(host, httpPort))
{
Serial.println("connection failed");
return;
}