#include "Arduino.h"
#include "input.h"
#include "tools.h"

// int primaryInput[50];
// int secondaryInput[50];
// int std1, std2;

// struct aux
// {
//   int STD[8];
//   bool playing;
//   /* data */
// }aux1, aux2;

void setupJack(){
    pinMode(PIN_A0,INPUT);
 //   pinMode(PIN_A2,INPUT);

    pinMode(2, OUTPUT); // A0
    pinMode(9, OUTPUT); // A1
    pinMode(4, OUTPUT);  // ENABLE
}

void inputDetect(){

    int rightChannelSignal;
    int leftChannelSignal;

    rightChannelSignal = analogRead(PIN_A0);
    leftChannelSignal = analogRead(PIN_A1);
        
   // printf("L Channel = %d mV\n", leftChannelSignal);
   // printf("%d\n", rightChannelSignal);
}

void setMux(int mode){

    // mode 0 = none, mode 1 = output A, mode 2 = output B
    // A0 = pin 2, A1 = pin 9

    switch(mode){
        case 0:
            digitalWrite(4, HIGH);
            //silence
            break;
        case 2:
            digitalWrite(4, LOW);
            digitalWrite(9, LOW);
            digitalWrite(2, LOW);
            // output A orange
            break;
        case 1:
            digitalWrite(4, LOW);
            digitalWrite(9, LOW);
            digitalWrite(2, HIGH);
            // output B
            break;
        case 3:
            digitalWrite(4, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(2, LOW);
            // output B
            break;  
        default:
            printf("IDKKKK"); // debug text
    }

}

