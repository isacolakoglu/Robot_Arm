#include<Servo.h>

Servo servo1, servo2, servo3, servo4;

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequency = 0;

void setup() {
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);

  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
  
}
void loop() {

  servo1.write(00);
  servo2.write(00);
  servo3.write(90);
  servo4.write(90);
  delay(500);

  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);

  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;

  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(1000);

  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);

  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;

  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(1000);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);

  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;

  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(1000);

  if(R<100 & G>100 & B>100){
    
    Serial.println("Red");
    delay(1000);
    
    servo2.write(60);
    delay(500);
    servo3.write(45);
    delay(500);
    servo4.write(00);
    delay(500);

    servo2.write(00);
    delay(500);
    servo3.write(90);
    delay(500);
    servo1.write(90);
    delay(1000);
    servo4.write(90);
    delay(1000);
    
  }
  if(R>100 & G<100 & B>100){
    
    Serial.println("Green");
    delay(1000);

    servo2.write(60);
    delay(500);
    servo3.write(45);
    delay(500);
    servo4.write(00);
    delay(500);

    servo2.write(00);
    delay(500);
    servo3.write(90);
    delay(500);
    servo1.write(135);
    delay(1000);
    servo4.write(90);
    delay(1000);
    
  }
  if (R<150 & G<100 & B<50 || R>100 & G>100 & B<100){
    
    Serial.println("Blue");
    delay(1000);

    servo2.write(60);
    delay(500);
    servo3.write(45);
    delay(500);
    servo4.write(00);
    delay(500);

    servo2.write(00);
    delay(500);
    servo3.write(90);
    delay(500);
    servo1.write(180);
    delay(1000);
    servo4.write(90);
    delay(1000);
    
  }
}
