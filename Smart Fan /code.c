// Innova8  Arduino Starter Kit  
// Project:- Smart Fan

#include <DHT.h>
#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // Type of DHT sensor

DHT dht(DHTPIN, DHTTYPE);

const int fanPin = 9; // Digital pin connected to the fan

const float temperatureThreshold = 25.0; // Set your desired temperature threshold here in Celsius

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(fanPin, OUTPUT);
}

void loop() {
  // Read temperature and humidity from the DHT sensor
  float temperature = dht.readTemperature();
  
  // Check if the DHT sensor reading was successful
  if (!isnan(temperature)) {
    // Print temperature to serial monitor
    Serial.print("Temperature: ");
    Serial.println(temperature);
    
    // Check if temperature exceeds the threshold
    if (temperature > temperatureThreshold) {
      // Turn on the fan
      digitalWrite(fanPin, HIGH);
      Serial.println("Fan is ON");
    } else {
      // Turn off the fan
      digitalWrite(fanPin, LOW);
      Serial.println("Fan is OFF");
    }
  } else {
    Serial.println("Failed to read from DHT sensor");
  }
  
  delay(2000); // Delay for 2 seconds before taking the next reading
}
