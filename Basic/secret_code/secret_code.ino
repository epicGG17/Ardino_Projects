
#include <Keypad.h>

//Constants for rows and colums sizes
const byte ROWS = 4;
const byte COLS = 4;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
const int code = 4;
const int in   = 2;
char codeInputs[in][code] ={
  {'2', '0', '1', '9'}, //final code
  {'0', '0', '0', '0'} //input code
};
int wrongLED = 13;
int rightLED = 12;
int i =0;

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Test");
  Serial.println("Enter 4 digit code");
  Serial.println(code);
  pinMode(wrongLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

};

void loop() {
  // put your main code here, to run repeatedly:
  char key = customKeypad.getKey();

  if(key){
    Serial.print("You press: ");
    Serial.println(key);
    if(i < code){
      codeInputs[1][i] = key;
      i++;
    }
    if(i >= code){
      //check code it right or wrong
      for(i = 0; i < code; i++){
          Serial.print("Compare: ");
          Serial.print(codeInputs[0][i]);
          Serial.print(" :: ");
          Serial.println(codeInputs[1][i]);

          if(codeInputs[0][i] != codeInputs[1][i]){
            
            digitalWrite(wrongLED, HIGH);
            
          }else{
            digitalWrite(rightLED, HIGH);
          }
          delay(250);
          digitalWrite(rightLED, LOW);
          digitalWrite(wrongLED, LOW);
          delay(250);
        }
        i = 0;

    }
    
  }

}
