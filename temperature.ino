#include <stdio.h>
#include <unistd.h>

TCPClient client;
IPAddress server(10,0,1,5);
int port = 5000;

void setup()
{
  Serial.begin(9600);

  for (int i = 10; i > 0; i--) {
    Serial.println("Starting in " + String(i, DEC));
    delay(1000);
  }

}

void loop()
{
  delay(5000);

  while (!client.connected()) {

    delay(2000);
    Serial.println("Attempting connection");
    if (client.connect(server, port))
    {
      Serial.println("Connected!");
    } else {
      Serial.println("Failed to connect");
    }
  }

  Serial.println("Sending data");

  client.println('Hello Coo chee');
  
}
