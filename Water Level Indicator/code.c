
// Innova8  Arduino Starter Kit  
// Project:- Smart Hand Wash System


#include <Servo.h>
Servo myservo;  // Create a servo object
const int trigPin = 9;  // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor
long duration;
int distance;

void setup() {
  myservo.attach(11);  // Attach the servo to pin 11
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Rotate the servo based on the distance
  if (distance >= 5 && distance <= 15) {
    myservo.write(90);  // Rotate the servo to 90 degrees (e.g., indicating "Wash Hands")
    delay(2000);  // Keep the servo in this position for 2 seconds
    myservo.write(0);  // Rotate the servo back to 0 degrees (e.g., indicating "Done")
    delay(1000);  // Keep the servo in this position for 1 second
  }
  else {
    myservo.write(0);  // Rotate the servo to 0 degrees (e.g., indicating "Not Washing Hands")
  }

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);  // Delay for readability (adjust as needed)
}
