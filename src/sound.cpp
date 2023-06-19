#include "Arduino.h"
#include "pitches.h"
#include "sound.h"

//PWM PIN 3!

// notes in the melody:
int melodyIndicator[] = {
  NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0
};

// // note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDur_Ind[] = {
  3, 2, 2, 4, 3, 2, 2, 4
};

int melody[] = {
  NOTE_GS4, NOTE_G4, NOTE_FS4, NOTE_E4 
};

int noteDurations[] = {
  3, 3, 3, 3
};

void playIndicator(bool enable){
  if(enable){
     for (int thisNote = 0; thisNote < 8; thisNote++) {
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

      int dura = noteDur_Ind[thisNote];

      int noteDur_Ind = 1000 / dura;
      tone(3, melodyIndicator[thisNote], noteDur_Ind);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:

      int pause = noteDur_Ind * 1.30;
      delay(pause);

      // stop the tone playing:
      noTone(3);
   }
  }else{
    noTone(3);
  }
}


void playLowBatt(bool enable){
  if(enable){
     for (int thisNote = 0; thisNote < 4; thisNote++) {

      int noteDuration = 1000 / noteDurations[thisNote];

      tone(3, melody[thisNote], noteDuration);

      int pause = noteDuration * 1.30;

      delay(pause);

      noTone(3);
    }
  }else{
    noTone(3);
  }
}
