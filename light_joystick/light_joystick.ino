//joystick
int swPin = 13;
int xPin = A1;
int yPin = A2;

//buzzer
int buzz = 10;

//lights
int b_LED = 5;
int y_LED = 4;
int g_LED = 3;
int r_LED = 2;

void setup() {
  Serial.begin(9600);
  pinMode(swPin, INPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(buzz, OUTPUT);

  pinMode(b_LED, OUTPUT);
  pinMode(y_LED, OUTPUT);
  pinMode(g_LED, OUTPUT);
  pinMode(r_LED, OUTPUT);


}
 int sw = 0;
 int x = 0;
 int y = 0;
void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(xPin);
  y = analogRead(yPin);

  sw = digitalRead(swPin);

  if(sw == HIGH){
    Serial.println("BUZZ BUZZ");
    digitalWrite(buzz, HIGH);
  }else{
    //Serial.println("NO BUZZ");
    digitalWrite(buzz,LOW);
  }
  
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("  Y: ");
  Serial.println(y);
  delay(1000);
  //if strick is center
  if((x >= 520 && x <= 530) && (y >= 500 && y <= 510) ){
    makeLight(LOW, LOW, LOW, LOW);
  }else if((x >= 0 && x <= 20) && (y >= 500 && y <= 510) ){         //blue
    makeLight(HIGH, LOW, LOW, LOW);
  } else if((x >= 520 && x <= 530) && (y >= 1020 && y <= 1030) ){   //yellow
    makeLight(LOW, HIGH, LOW, LOW);
  } else if((x >= 520 && x <= 530) && (y >= 0 && y <= 20) ){     //green
    makeLight(LOW, LOW, HIGH, LOW);
  } else if((x >= 1020 && x <= 1030) && (y >= 500 && y <= 510) ){     //red
    makeLight(LOW, LOW, LOW, HIGH);
  }

  delay(250);

}

void makeLight(int b, int y, int g, int r){
  digitalWrite(b_LED, b);
  digitalWrite(y_LED, y);
  digitalWrite(g_LED, g);
  digitalWrite(r_LED, r);

}


