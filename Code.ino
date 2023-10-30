#include "MIDIUSB.h"

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

const int delaytime = 10;
 
void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  Serial.begin(9600);
 
}
 
void loop() {
rB1();
rB2();
rB3();
rB4();
}

void act1(){
    noteOn(0, 51, 127);
    noteOn(0, 51, 0);
    MidiUSB.flush();
}
void act2(){
    noteOn(0, 52, 127);
    noteOn(0, 52, 0);
    MidiUSB.flush();
}
void act3(){
    noteOn(0, 53, 127);
    noteOn(0, 53, 0);
    MidiUSB.flush();
}
void act4(){
    noteOn(0, 54, 127);
    noteOn(0, 54, 0);
    MidiUSB.flush();
}

 
void rB1(){
  int buttonState1 = (digitalRead(button1));
  if (buttonState1 == 0){
    act1();
    delay(1);
    while (buttonState1 == 0){
      buttonState1 = (digitalRead(button1));
      if(buttonState1==1){
        delay(delaytime);
        break;
      }
    }
  }
}
 
void rB2(){
  int buttonState2 = (digitalRead(button2));
  if (buttonState2 == 0){
    act2();
    delay(1);
    while (buttonState2 == 0){
      buttonState2 = (digitalRead(button2));
      if(buttonState2==1){
        delay(delaytime);
        break;
      }
    }
  }
 
}
 
void rB3(){
  int buttonState3 = (digitalRead(button3));
  if (buttonState3 == 0){
    act3();
    delay(1);
        while (buttonState3 == 0){
      buttonState3 = (digitalRead(button3));
      if(buttonState3==1){
        delay(delaytime);
        break;
      }
    }
  }
 
}
 
void rB4(){
  int buttonState4 = (digitalRead(button4));
  if (buttonState4 == 0){
    act4();
    delay(1);
        while (buttonState4 == 0){
      buttonState4 = (digitalRead(button4));
      if(buttonState4==1){
        delay(delaytime);
        break;
      }
    }
  }
 
}


void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
