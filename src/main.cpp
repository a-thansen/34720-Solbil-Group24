
#include "Arduino.h"
#include "led.h"
#include <arduino-timer.h>
#include "input.h"
#include "potentiometer.h"
#include "sound.h"


#define ENCODER_A D7
#define ENCODER_B D6
#define CARALERT_PIN D15

auto timer = timer_create_default(); // create a timer with default settings using arduino-timer library

int prev_a;
int prev_b;
int volume;
char car_alert = 5 ; // due to lack of CANBUS, this variable can be changed to 0 = indicator disable, 1 = indicator enable, 3 = low battery notification.

int primaryInput[50];
// int secondaryInput[50];
int std1;
// int std2;

struct aux
{
  int STD[8];
  bool playing;
  /* data */
}aux1, aux2;

bool readAuxAlert(void *){
  int i;
  int count = 0;
   for (i = 0; i < 50; i++) {
      primaryInput[i] = analogRead(A0);
      // secondaryInput[i] = analogRead(SECONDARY_INPUT_PIN);
    }

    std1 = findStandardDeviation(primaryInput, 50);
    // std2 = findStandardDeviation(secondaryInput, 50);

    pushToBack(aux1.STD, 8, std1);
    // pushToBack(aux2.STD, 8, std2);

   if(car_alert != 5){
    digitalWrite(CARALERT_PIN, HIGH);
  }else{
    digitalWrite(CARALERT_PIN, LOW);
   }

  return true;
}

bool checkInput(void *){
  int i;
  int count1 = 0;
  int count2 = 0;

  for(i=0; i < 8; i++){
    if(aux1.STD[i] > 20){
      count1++;
    }
    if(aux2.STD[i] > 20){
      count2++;
    }
  }

  if(count1 > 2){
    aux1.playing = true;
  }else{
    aux1.playing = false;
  }
  if(count2 > 2){
    aux2.playing = true;
  }else{
    aux2.playing = false;
  }

  return true;
}

void encoderInterrupt() {
  int a = digitalRead(ENCODER_A);
  int b = digitalRead(ENCODER_B);

  // Check that the values actually are different
  if (a != prev_a || b != prev_b) {
    // Check that the move isn't illegal (we ignore the move in this case)
    if (a != prev_a && b != prev_b) {
      // This is illegal so update the values and return
      prev_a = a;
      prev_b = b;
      return;
    }

    // Here we only consider legal moves only
    if (prev_b ^ a) {
      // CCW
      volume--;
    } else {
      // CW
      volume++;
    }

    // volume capping

    if(volume < 0){
      volume = 0;
    }else if (volume > 100){
      volume = 100;
    }

  }

  prev_a = a;
  prev_b = b;
}

void vol2Pot(){
    int vol = volume;
    int pot;

    if(vol > 90){
      pot = 0;
    }else if(vol > 80 && vol < 90){
      pot = 13;
    }else if(vol > 70 && vol < 80){
      pot = 26;
    }else if(vol > 60 && vol < 70){
      pot = 39;
    }else if(vol > 50 && vol < 60){
      pot = 42;
    }else if(vol > 40 && vol < 50){
      pot = 55;
    }else if(vol > 30 && vol < 40){
      pot = 68;
    }else if(vol > 20 && vol < 30){
      pot = 81;
    }else if (vol > 9 && vol < 20){
      pot = 94;
    }else if (vol > 5 && vol < 9){
      pot = 108;
    }else if(vol < 5){
      pot = 129;
    }

  
  set_potentiometer(pot);
}

void carAlertInterrupt(){
   if(car_alert = 1){
      playIndicator(1);
      digitalWrite(CARALERT_PIN, LOW);
      //turn down vol
    }else if(car_alert = 0){
       //turn up vol
      playIndicator(0);
      digitalWrite(CARALERT_PIN, LOW);
      return;
    }else if(car_alert = 3){
      //turn down vol
      playLowBatt(1);
      digitalWrite(CARALERT_PIN, LOW);
      return;
    }
  }

void setupPotVol(){ 
 //  Initialize the encoder
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  prev_a = digitalRead(ENCODER_A);
  prev_b = digitalRead(ENCODER_B);

  attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoderInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), encoderInterrupt, CHANGE);

 // attachInterrupt(digitalPinToInterrupt(CARALERT_PIN), carAlertInterrupt, HIGH);

  volume = 10;
  init_potentiometer();
}

void prioritize(){

  if(aux1.playing){
    setMux(1);
   // volume = ?
    switchLED(1);
  }else{
    setMux(2);
    switchLED(2);
  }
}

void setup()
{
  setupPotVol();
  setupJack();
  setupLED();

  timer.every(250, readAuxAlert);
  timer.every(2000, checkInput);


}


void loop(){

  timer.tick();
  prioritize();
  vol2Pot();

  printf("Volume: %d\r\n", volume);
  
}

// 0 3.3 V = > vol = 100
// 13 => vol = 90
// 30 2.56 = 
// 60 1.78
// 90 1 V
// 120 0.24 V => vol =
// ..
// 129 0,.-134 V => vol = 0

