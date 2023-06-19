// #include "Arduino.h"
// #include "input.h"
// #include "potentiometer.h"
// #include "volume.h"

// int prev_a;
// int prev_b;
// int volume;


// void encoderInterrupt() {
//   int a = digitalRead(ENCODER_A);
//   int b = digitalRead(ENCODER_B);

//   // Check that the values actually are different
//   if (a != prev_a || b != prev_b) {
//     // Check that the move isn't illegal (we ignore the move in this case)
//     if (a != prev_a && b != prev_b) {
//       // This is illegal so update the values and return
//       prev_a = a;
//       prev_b = b;
//       return;
//     }

//     // Here we only consider legal moves only
//     if (prev_b ^ a) {
//       // CCW
//       volume--;
//     } else {
//       // CW
//       volume++;
//     }

//     // volume capping

//     if(volume < 0){
//       volume = 0;
//     }else if (volume > 500){
//       volume = 500;
//     }

//   }

//   prev_a = a;
//   prev_b = b;
// }

// void volPot(){
//     int vol = volume;
//     int pot;

//     if (volume < 1){
//       pot = 0;
//     }else if(volume > 499){
//       pot = 129;
//     }else{
//       pot = vol >> 2;
//     }

//     set_potentiometer(pot);
// }

// void setupPotVol(){ 
//    // Initialize the encoder
//   pinMode(ENCODER_A, INPUT_PULLUP);
//   pinMode(ENCODER_B, INPUT_PULLUP);
//   prev_a = digitalRead(ENCODER_A);
//   prev_b = digitalRead(ENCODER_B);

//   // Really we should disable interrupts until both of them are set up.
//   // But as far as I can tell it doesn't really matter.
//   attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoderInterrupt, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(ENCODER_B), encoderInterrupt, CHANGE);

//   volume = 10;
//   init_potentiometer();
// }

// // void setup() {
// //   // Initialize the encoder
// //   pinMode(ENCODER_A, INPUT_PULLUP);
// //   pinMode(ENCODER_B, INPUT_PULLUP);
// //   prev_a = digitalRead(ENCODER_A);
// //   prev_b = digitalRead(ENCODER_B);

// //   // Really we should disable interrupts until both of them are set up.
// //   // But as far as I can tell it doesn't really matter.
// //   attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoderInterrupt, CHANGE);
// //   attachInterrupt(digitalPinToInterrupt(ENCODER_B), encoderInterrupt, CHANGE);

// //   volume = 10;
// //   init_potentiometer();
// // }

// // void loop() {
// //   setMux(1);

// //   int vol = volume;
// //   int pot;

// //   if (volume < 1){
// //     pot = 0;
// //   }else if(volume > 499){
// //     pot = 129;
// //   }else{
// //     pot = vol >> 2;
// //   }

// //   set_potentiometer(pot);

// //   printf("Volume: %d\r\n", volume);
// //   printf("POT: %d\r\n", pot);
// // }
