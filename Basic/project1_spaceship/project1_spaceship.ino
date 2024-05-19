
int switchState = 0;
// these are globel varriables
int butt = 5;
int green_light = 4;
int yellow_light = 3;
int red_light = 2;
int p = 0;
bool pressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Traffic lights");

  pinMode(butt,INPUT);  
  pinMode(green_light,INPUT); 
  pinMode(yellow_light,INPUT);
  pinMode(red_light,INPUT);
  digitalWrite(red_light, LOW);
  digitalWrite(yellow_light, LOW);
  digitalWrite(green_light, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(butt);

  
  //onOff();
  traffic();

  delay(250);// 250 1/4 of second 1000 is second

}

void onOff(){
   if(switchState == HIGH){
    pressed = !pressed;

    if(pressed == true){
      digitalWrite(green_light, HIGH); //turn LED ON
      Serial.print("ON\n");
    }
    else{
      digitalWrite(green_light, LOW); //turn LED OFF
      Serial.print("OFF\n");
    }
   }
}
void traffic(){
  if(switchState == HIGH){

    Serial.println("Button has been pressed \n");

    //red light
      if(p == 2){
        p++;
        Serial.println("Traffic light: RED");
        digitalWrite(red_light, HIGH);
        digitalWrite(yellow_light, LOW);
        digitalWrite(green_light, LOW);

      //yellow light
      } else if(p ==1){
        p++;
        Serial.println("Traffic light: YELLOW");
        digitalWrite(red_light, LOW);
        digitalWrite(yellow_light, HIGH);
        digitalWrite(green_light, LOW);
      //off
      }else if( p == 3){
        p = 0;
        Serial.println("Traffic light: OFF");
        digitalWrite(red_light, LOW);
        digitalWrite(yellow_light, LOW);
        digitalWrite(green_light, LOW);

      //after red light turn off
      }else{
        //p =1
        p++;
        Serial.println("Traffic light: Green");
        digitalWrite(red_light, LOW);
        digitalWrite(yellow_light, LOW);
        digitalWrite(green_light, HIGH);
      
      }

  }
}


