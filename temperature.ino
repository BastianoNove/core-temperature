#include <stdio.h>
#include <unistd.h>

#include "pb_encode.h"
#include "pb_decode.h"
#include "temperature.pb.h"

#include <inttypes.h>

#define aref_voltage 3.3

temperature_Temperature measurement(float celsius);
void readTemperature(double &celsius);

//Temperature sensor (TMP36) definitions.
int tempPin = A7;
double voltage;
double celsius;
int tempReading;


// Raspberry Pi
IPAddress server(10,0,1,5);
int port = 5000;
TCPClient client;

// Used to send temperature data
uint8_t buffer[512];
size_t temp_length;
bool status;

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

  readTemperature(celsius);
  temperature_Temperature current_temperature = measurement(celsius);
  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
  status = pb_encode(&stream, temperature_Temperature_fields,
                       &current_temperature);
  temp_length = stream.bytes_written;

  if (!status) {
    Serial.print("Encoding failed: ");
    Serial.println(PB_GET_ERROR(&stream));
   }
   else {
     Serial.print("Sending temperature data: ");
     Serial.print(current_temperature.celsius);
     Serial.print(", ");
     Serial.printf("%lld \n", current_temperature.timestamp);
     client.write(buffer, temp_length);
   }

  client.flush();

}

temperature_Temperature measurement(float celsius) {
  temperature_Temperature datapoint = temperature_Temperature_init_zero;
  // This does not work at the moment - no hardware clock. Placeholder until
  // I get an external clock.
  datapoint.timestamp = (unsigned)time(NULL);
  datapoint.celsius = celsius;
  return datapoint;
}

void readTemperature(double &celsius) {
  tempReading = analogRead(tempPin);
  voltage = tempReading * aref_voltage;
  voltage /= 4095.0;
  celsius = (voltage - 0.5) * 100;
}
