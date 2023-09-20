//innova8 || Arduino Starter kit || touch based led ON and OFF
int touchPin = 2; // Attach signal pin of touch sensor at pin number 2
int ledPin   = 3;// Attach led at pin number 3
int val = 0;
int lightON = 0;
int touched = 0;
void setup() {
  Serial.begin(9600);
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT); }
void loop() {
  val = digitalRead(touchPin);
  if (val == HIGH && lightON == LOW) {
    touched = 1 - touched;
    delay(100); }
  lightON = val;
  if (touched == HIGH) {
    Serial.println("Light ON");

    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("Light OFF");
    
    digitalWrite(ledPin, LOW); }
  delay(100); }
