
// innova8 || Arduino Starter Kit || Air Quality System

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // (RS-12,EN-11,D5,D4,D3,D2)Initialize the LCD library with the appropriate pins

const int airQualityPin = A0; // Analog pin connected to the air quality sensor
int airQualityValue; // Variable to store air quality value

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(" Innova8");
  lcd.clear();
  lcd.print("Air Quality:");

  pinMode(airQualityPin, INPUT); // Set the air quality sensor pin as an input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the air quality value from the sensor
  airQualityValue = analogRead(airQualityPin);

  // Display the air quality value on the LCD
  lcd.setCursor(0, 1);
  lcd.print("AQI: ");
  lcd.print(airQualityValue);

  // Display the air quality value on the serial monitor
  Serial.print("Air Quality Value: ");
  Serial.println(airQualityValue);

  delay(1000); // Delay for readability (adjust as needed)
}
