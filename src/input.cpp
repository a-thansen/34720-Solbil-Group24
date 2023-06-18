#include "Arduino.h"
#include "input.h"

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

void pushToBack(int* array, int length, int value) {
    for (int i = 0; i < length-1; i++) {
        array[i] = array[i+1];
    }

    array[length-1] = value;
}

void print_array(int* array, int length) {
    printf("[");
    printf("%d", array[0]);
    for (int i = 1; i < length; i++) {
        printf(", %d", array[i]);
    }
    printf("]");
}

int findStandardDeviation(int *array, int count) {
    int sum = 0.0, sDeviation = 0.0, mean;
    int i;
 
    for(i = 0; i < count; i++) {
        sum += array[i];
    }
    // Calculating mean 
    mean = sum/count;
 
    for(i = 0; i < count; ++i) {
        sDeviation += (array[i] - mean)*(array[i] - mean);
    }

    return sDeviation/count; // returns STD^2 
}

    // pinMode(2, OUTPUT); // A0
    // pinMode(9, OUTPUT); // A1
    // pinMode(4, OUTPUT);  // ENABLE

void setMux(int mode){

    // mode 0 = none, mode 1 = output A, mode 2 = output B

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
            printf("IDKKKK");
    }

}





// MAIN FOR THIS

// #include "Arduino.h"
// #include "led.h"
// // #include "sound.h"
// #include <arduino-timer.h>
// #include "input.h"

// auto timer = timer_create_default(); // create a timer with default settings
// int count = 0;

// int primaryInput[50];
// int secondaryInput[50];
// int std1, std2;

// struct aux
// {
//   int STD[8];
//   bool playing;
//   /* data */
// }aux1, aux2;

// bool readAux(void *){
//   int i;
//   int count = 0;
//    for (i = 0; i < 50; i++) {
//       primaryInput[i] = analogRead(A1);
//       // secondaryInput[i] = analogRead(A2);
//     }

//     std1 = findStandardDeviation(primaryInput, 50);
//     // std2 = findStandardDeviation(secondaryInput, 50);

//     pushToBack(aux1.STD, 8, std1);
//     // pushToBack(aux2.STD, 8, std2);

//   return true;
// }

// bool probNoInput(void *){
//   int i;
//   int count1 = 0;
//   int count2 = 0;

//   for(i=0; i < 8; i++){
//     if(aux1.STD[i] > 20){
//       count1++;
//     }
//     if(aux2.STD[i] > 20){
//       count2++;
//     }
//   }

//   if(count1 > 2){
//     aux1.playing = true;
//   }else{
//     aux1.playing = false;
//   }
//   if(count2 > 2){
//     aux2.playing = true;
//   }else{
//     aux2.playing = false;
//   }

//   return true;
// }

// void prioritize(){

//   if(aux1.playing){
//     setMux(1);
//     switchLED(1);
//   }else{
//     setMux(2);
//     switchLED(2);
//   }

// }

// void setup()
// {
//  // printf("yee");
//   setupJack();
//   setupLED();

//   pinMode(USER_BTN, INPUT_PULLDOWN); // initialize userbutton

//   timer.every(250, readAux);
//   timer.every(2000, probNoInput);
// }

// void loop(){

//   timer.tick(); // tick the timer

//   prioritize();

//   }





