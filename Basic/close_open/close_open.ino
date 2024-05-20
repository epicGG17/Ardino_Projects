#define trigPin 2
#define echoPin 3

#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 20 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
    servo.write(0);
    delay(500);
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    servo.write(360);
    
    delay(500);
  }


}
