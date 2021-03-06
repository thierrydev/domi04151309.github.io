#include <Notes.h>

Notes n;

void setup() {
  pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  Serial.begin(9600);
  n.speakerSetup(3,120);
  n.toneLEDSetup(6,7,8,9,10,11,12,13);
  blinkLED(6);
  blinkLED(7);
  blinkLED(8);
  blinkLED(9);
  blinkLED(10);
  blinkLED(11);
  blinkLED(12);
  blinkLED(13);
  digitalWrite(13,HIGH);
}

void loop() {
  if(digitalRead(1)==0){
    digitalWrite(13,LOW);
    turningHeads();
    digitalWrite(13,HIGH);
  }
  if(digitalRead(2)==0){
    digitalWrite(13,LOW);
    tetris();
    digitalWrite(13,HIGH);
  }
  if(digitalRead(4)==0){
    digitalWrite(13,LOW);
    imperialMarch();
    digitalWrite(13,HIGH);
  }
  if(digitalRead(5)==0){
    digitalWrite(13,LOW);
    allNight();
    digitalWrite(13,HIGH);
  }
}

void blinkLED(uint8_t pin){
  digitalWrite(pin, HIGH);
  delay(120);
  digitalWrite(pin, LOW);
}

void turningHeads() {
  //1
  n.note(NOTE_A3,4,false,false);
  n.note(NOTE_A4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_D5,4,false,false);
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_A4,8,false,true);
  //2
  n.note(NOTE_A3,8,false,false);
  n.note(NOTE_A4,8,false,true);
  n.note(NOTE_C5,4,false,false);
  n.note(NOTE_D5,8,false,false);
  n.note(NOTE_D5,8,false,true);
  n.note(NOTE_C5,4,false,false);
  //3
  n.note(NOTE_A3,4,false,false);
  n.note(NOTE_A4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_D5,4,false,false);
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_A4,8,false,true);
  //4
  n.note(NOTE_A3,8,false,false);
  n.note(NOTE_A4,8,false,true);
  n.note(NOTE_C5,4,false,false);
  n.note(NOTE_D5,8,false,false);
  n.note(NOTE_D5,8,false,true);
  n.note(NOTE_C5,4,false,false);
  //5
  n.note(NOTE_A3,8,false,false);
  n.note(NOTE_A3,4,false,true);
  n.note(NOTE_A4,8,false,true);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_G4,8,false,false);
  n.note(NOTE_G4,4,false,true);
  //6
  n.note(NOTE_E4,8,false,true);
  n.note(NOTE_E4,4,false,false);
  //7
  n.note(NOTE_G4,8,false,false);
  n.note(NOTE_E4,4,true,true);
  //8
  n.note(NOTE_A3,8,false,false);
  n.note(NOTE_A3,4,false,true);
  n.note(NOTE_A4,8,false,true);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_G4,8,false,false);
  n.note(NOTE_G4,4,false,true);
  //9
  n.note(NOTE_E4,8,false,true);
  n.note(NOTE_E4,4,false,false);
  //10
  n.note(NOTE_G4,8,false,false);
  n.note(NOTE_E4,4,true,true);
}

void tetris() {
  //1
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_B4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_D5,4,false,false);
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_B4,8,false,true);
  //2
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_A4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_D5,8,false,false);
  n.note(NOTE_C5,8,false,true);
  //3
  n.note(NOTE_B4,4,false,false);
  n.note(NOTE_B4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_D5,4,false,false);
  n.note(NOTE_E5,4,false,false);
  //4
  n.note(NOTE_C5,4,false,false);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_B4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  //5
  n.note(NOTE_D5,4,true,false);
  n.note(NOTE_F5,8,false,true);
  n.note(NOTE_A5,4,false,false);
  n.note(NOTE_G5,8,false,false);
  n.note(NOTE_F5,8,false,true);
  //6
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_E5,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_D5,8,false,false);
  n.note(NOTE_C5,8,false,true);
  //7
  n.note(NOTE_B4,4,false,false);
  n.note(NOTE_B4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_D5,4,false,false);
  n.note(NOTE_E5,4,false,false);
  //8
  n.note(NOTE_C5,4,false,false);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_A4,2,false,false);
}

void imperialMarch(){
  //1
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_F4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  //2
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_F4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_A4,2,false,false);
  //3
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_E5,4,false,false);
  n.note(NOTE_F5,8,false,false);
  n.note(NOTE_C5,8,false,true);
  //4
  n.note(NOTE_GS4,4,false,false);
  n.note(NOTE_F4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_A4,2,false,false);
  //5
  n.note(NOTE_A5,4,false,false);
  n.note(NOTE_A4,8,false,false);
  n.note(NOTE_A4,8,false,true);
  n.note(NOTE_A5,4,false,false);
  n.note(NOTE_GS5,8,false,false);
  n.note(NOTE_G5,8,false,true);
  //6
  n.note(NOTE_FS5,8,false,false);
  n.note(NOTE_F5,8,false,true);
  n.note(NOTE_FS5,8,false,false);
  n.note(NOTE_AS4,8,false,true);
  n.note(NOTE_DS5,4,false,false);
  n.note(NOTE_D5,8,false,false);
  n.note(NOTE_CS5,8,false,true);
  //7
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_B4,8,false,true);
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_F4,8,false,true);
  n.note(NOTE_GS4,4,false,false);
  n.note(NOTE_F4,8,false,false);
  n.note(NOTE_GS4,8,false,true);
  //8
  n.note(NOTE_C5,4,false,false);
  n.note(NOTE_A4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_E5,2,false,false);
  //9
  n.note(NOTE_A5,4,false,false);
  n.note(NOTE_A4,8,false,false);
  n.note(NOTE_A4,8,false,true);
  n.note(NOTE_A5,4,false,false);
  n.note(NOTE_GS5,8,false,false);
  n.note(NOTE_G5,8,false,true);
  //10
  n.note(NOTE_FS5,8,false,false);
  n.note(NOTE_F5,8,false,true);
  n.note(NOTE_FS5,8,false,false);
  n.note(NOTE_AS4,8,false,true);
  n.note(NOTE_DS5,4,false,false);
  n.note(NOTE_D5,8,false,false);
  n.note(NOTE_CS5,8,false,true);
  //11
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_B4,8,false,true);
  n.note(NOTE_C5,8,false,false);
  n.note(NOTE_F4,8,false,true);
  n.note(NOTE_GS4,4,false,false);
  n.note(NOTE_F4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  //12
  n.note(NOTE_A4,4,false,false);
  n.note(NOTE_F4,8,false,false);
  n.note(NOTE_C5,8,false,true);
  n.note(NOTE_A4,2,false,false);
}

void allNight() {
  //1
  n.note(NOTE_DS5,8,false,false);
  n.note(NOTE_B5,8,false,true);
  n.note(NOTE_DS5,8,false,false);
  n.note(NOTE_B5,4,false,true);
  n.note(NOTE_C4,8,false,true);
  n.note(NOTE_CS4,8,false,false);
  n.note(NOTE_D4,8,false,true);
  //2
  n.note(NOTE_DS4,8,false,false);
  n.note(NOTE_DS6,8,false,true);
  n.note(NOTE_CS6,8,false,false);
  n.note(NOTE_B5,8,false,true);
  n.note(NOTE_CS6,8,false,false);
  n.note(NOTE_B5,8,false,true);
  n.note(NOTE_GS5,8,false,false);
  n.note(NOTE_FS5,8,false,true);
  //3
  n.note(NOTE_DS5,8,false,false);
  n.note(NOTE_B5,8,false,true);
  n.note(NOTE_DS5,8,false,false);
  n.note(NOTE_B5,4,false,true);
  n.note(NOTE_G3,8,false,true);
  n.note(NOTE_FS3,8,false,false);
  n.note(NOTE_F3,8,false,true);
  //4
  n.note(NOTE_E3,8,false,false);
  n.note(NOTE_GS5,8,false,true);
  n.note(NOTE_FS5,8,false,false);
  n.note(NOTE_GS5,8,false,true);
  n.note(NOTE_B5,8,false,false);
  n.note(NOTE_GS5,8,false,true);
  n.note(NOTE_FS5,8,false,false);
  n.note(NOTE_GS5,8,false,true);
}

