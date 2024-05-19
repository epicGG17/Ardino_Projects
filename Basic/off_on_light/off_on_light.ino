
const int LED = 8;
const int BUTTON = 2;
int val = 0; 
boolean pressed = false;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input

}

void loop() {
  // put your main code here, to run repeatedly:
  
  val = digitalRead(BUTTON); // read input value and store it
  // check whether the input is HIGH (button pressed)

  if(val == HIGH){
    pressed = !pressed;

    if(pressed == true){
      digitalWrite(LED, HIGH); //turn LED ON
      Serial.print("ON\n");
    }
    else{
      digitalWrite(LED, LOW); //turn LED OFF
      Serial.print("OFF\n");
    }
     delay(1000);
  }

 
}
