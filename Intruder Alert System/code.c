
// Innova8  Arduino Starter Kit  
// Project:- Intruder Detector System

// Pin configuration
const int irPin = 2; // Connect the PIR sensor's signal pin to digital pin 2
const int buzzerPin = 3; // Connect a buzzer or an LED to digital pin 3

void setup() {
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int pirValue = digitalRead(irPin);

  if (pirValue == HIGH) {
    // Motion detected, trigger the alarm
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Intruder detected!");
    delay(1000); // Delay to avoid continuous alarms
  } else {
    // No motion, turn off the alarm
    digitalWrite(buzzerPin, LOW);
  }
}
