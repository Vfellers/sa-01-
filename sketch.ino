
#include "DHTesp.h"

#define sensorDHT 15
#define tempLed 13
#define umiLed 12

DHTesp sensor;

void setup() {
  Serial.begin(115200);
  pinMode(tempLed, OUTPUT);
  pinMode(umiLed, OUTPUT);

  sensor.setup(sensorDHT, DHTesp::DHT22);
}

void loop() {
  
  delay(5000); 

  float temperatura = sensor.getTemperature();
  float umidade = sensor.getHumidity();
 
  
  Serial.println("Temperatura: " + String(temperatura) + "C°");
  Serial.println("Umidade: " + String(umidade) + "%");

  if(temperatura > 35){
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }

  if(umidade > 70 ) {
    digitalWrite(12, HIGH); 
  }
  else {
    digitalWrite(12, LOW);
  }
}
