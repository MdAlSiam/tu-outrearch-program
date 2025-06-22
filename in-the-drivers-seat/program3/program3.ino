#include "pitches.h"

int melody[] = {
  NOTE_E7, NOTE_E7, NOTE_E7, NOTE_C7, NOTE_E7, NOTE_G7, NOTE_G6
};

int duration = 500;
int buzzer = 13;

void setup() {

}

void loop() {
  for (int thisNote = 0; thisNote < 7; thisNote++) {
    tone(buzzer, melody[thisNote], duration);
    delay(500);
  }
  delay(2000);
}