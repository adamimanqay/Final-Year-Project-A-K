// We now create a URI for the request
url = "/rfidattendance/manage_users_up.php/rfid/insert?id_device=";
url += id_device;
url += "&rfid=";
url += UIDcard;

Serial.print("Requesting URL: ");
Serial.println(url);

// This will send the request to the server
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Connection: close\r\n\r\n");
timeout = millis();
while (client.available() == 0)
{
if (millis() - timeout > 1000)
{
Serial.println(">>> Client Timeout !");
client.stop();
return;
}
}
