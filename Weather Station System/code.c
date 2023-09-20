#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2        // Define the pin for the DHT11 sensor
#define DHTTYPE DHT11   // Specify the type of DHT sensor (DHT11)

const int smokeSensorPin = A0;  // Analog pin for smoke sensor
//const int switch1Pin = 3;       // Pin for switch 1
//const int switch2Pin = 4;       // Pin for switch 2

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Initialize LCD display

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  dht.begin();          // Initialize DHT sensor

  lcd.begin(16, 2);    // Initialize LCD display

  pinMode(smokeSensorPin, INPUT);       // Set smoke sensor pin as input
//  pinMode(switch1Pin, INPUT_PULLUP);    // Set switch 1 pin as input with pull-up resistor
//  pinMode(switch2Pin, INPUT_PULLUP);    // Set switch 2 pin as input with pull-up resistor
}

void loop() {
  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read smoke sensor value
  int smokeValue = analogRead(smokeSensorPin);

  // Read the state of switch 1 and switch 2
//  bool switch1State = digitalRead(switch1Pin);
//  bool switch2State = digitalRead(switch2Pin);

  // Print sensor values and switch states to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Smoke Value: ");
  Serial.println(smokeValue);
 

  // Display sensor values on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  lcd.setCursor(1, 1);
  lcd.print("SMOKE: ");
  lcd.print(smokeValue);
  

//  // Add your control logic for switches here
//  if (switch1State == LOW) {
//
//
//  }
//
//  if (switch2State == LOW) {
//    // Do something when switch 2 is pressed
//  }

  delay(2000);  // Delay for 2 seconds before taking readings again
}
