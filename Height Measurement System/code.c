
// Innova8  Arduino Starter Kit  
// HIght Measurment System
   
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,6,5,4);  // (RS-12,EN-11,D4,D5,D6,D7)address, 16 columns, 2 rows
const int trigPin = 9;  // Trigger pin of HC-SR04
const int echoPin = 10; // Echo pin of HC-SR04

void setup() {
  lcd.begin(16,2);// Initialize the LCD
  lcd.clear();
  lcd.print("Innova8");                 // Turn on the backlight
  pinMode(trigPin, OUTPUT);        // Set the trigger pin as an output
  pinMode(echoPin, INPUT);         // Set the echo pin as an input
  Serial.begin(9600);              // Initialize serial communication
}

void loop() {
  long duration;
  int height;
  
  // Send a pulse to trigger the HC-SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the height in centimeters (you can adjust the formula)
  height = duration / 58.2;

  // Display the height on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Height: ");
  lcd.print(height);
  lcd.print(" cm");

  // Display the height on the serial monitor for debugging
  Serial.print("Height: ");
  Serial.print(height);
  Serial.println(" cm");

  delay(1000); // Wait for a moment before taking the next measurement
}
