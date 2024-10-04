Serial.println();
Serial.println("closing connection");
Serial.println();

// Control the relay to unlock the door
digitalWrite(RELAY_PIN, LOW); // Turn on the relay to unlock the door
delay(1000);                  // Keep the relay on for 1 second
digitalWrite(RELAY_PIN, HIGH); // Turn off the relay
}
else
{
Serial.println("Unregistered card detected: " + UIDcard);
}
}
}

rfid.halt();
}

bool isRegisteredUID(String UID)
{
for (int i = 0; i < MAX_REGISTERED_CARDS; i++)
{
if (UID.equals(registeredUIDs[i]))
{
return true;
}
}
return false;
}