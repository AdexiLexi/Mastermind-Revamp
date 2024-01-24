#ifndef RickSoundFiles
#define RickSoundFiles

#include "Arduino.h"

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define REST      0

//int buzzer = 2;

int melody[] = {
  NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_D5, //13
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A4,
  REST, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4,
  REST, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,

  NOTE_E5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, //18
  NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, 
  NOTE_E5, NOTE_D5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
  NOTE_A5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
  NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4,  //23
  NOTE_E5, NOTE_D5, REST,
};
int duration[] = {
  2, 8, 8, 8,
  8, 8, 8, 8, 4, 4,
  2, 8, 8, 8, 8, 
  8, 8, 8, -4, 16, 16, 16, 16,
  -8, -8, -4, 16, 16, 16, 16,

  -8, -8, -8, 16, -8, 16, 16, 16, 16,
  4, 8, -8, 16, 8, 8, 8, 
  4, 2, 16, 16, 16, 16, 
  -8, -8, -4, 16, 16, 16, 16, 
  4, 8, -8, 16, 8, 16, 16, 16, 16, 
  4, 8, -8, 16, 4, 8, 
  4, 2, 4,
  };

  #endif
