
#include "Arduino.h"
#include "led.h"


void setupLED()
{
  pinMode(LED1_PIN, OUTPUT); // initialize LED digital pin as an output.
  pinMode(LED2_PIN, OUTPUT);

//   pinMode(LED3_PIN, OUTPUT);
//   pinMode(USER_BTN, INPUT_PULLDOWN); // initialize userbutton

}
//debug tool :)
int userbuttonCount(){

    int clicks = 0;

     if(!digitalRead(USER_BTN) == 1){

        delay(1000);

        if(!digitalRead(USER_BTN) == 1){
            clicks++;
        }
  }
  return clicks; 
}

void switchLED(int input){

    int inputState = input;

        switch(inputState){
        case 1:
            digitalWrite(LED1_PIN, HIGH);
            digitalWrite(LED2_PIN, LOW);
            // digitalWrite(LED3_PIN, LOW);
            break;
        case 2:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, HIGH);
            // digitalWrite(LED3_PIN, LOW);
            break;
        case 3:
            digitalWrite(LED1_PIN, HIGH);
            digitalWrite(LED2_PIN, HIGH);
            // digitalWrite(LED3_PIN, HIGH);
            break;
        default:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, LOW);
            // digitalWrite(LED3_PIN, LOW);
            break;
    }
}
