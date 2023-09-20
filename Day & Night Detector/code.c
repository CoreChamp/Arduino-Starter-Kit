// innova8 || Arduino starter kit || day and night detector

int led = 13; // Attach led at pin number 13
int ldr = 12; // Attach  ldr pin at pin number 12
int buzzer = 11;// Attach buzzer at pin number 11
void setup(){
  pinMode (led,OUTPUT);// initialize led work as a output 
  pinMode(ldr,INPUT);// initialize ldr work as a input
  pinMode(buzzer,OUTPUT);// initialize buzzer work as a output
  Serial.begin(9600);
}
void loop(){
  int x=digitalRead(ldr);
  if(x==0){
    digitalWrite(led,HIGH);  
    digitalWrite(buzzer,LOW);
  }
  else{
    digitalWrite(led,LOW);
    digitalWrite(buzzer,HIGH);
  }
  
}
