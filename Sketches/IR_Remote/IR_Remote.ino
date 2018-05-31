/*
IR LED - 9
IR RECEIVER - 2
POWER BUTTON - 3
VOLUME + BUTTON - 5
Volume - BUTTON - 7

 */

#include <IRremote.h> 
#define IR_USE_TIMER1

IRsend irsend;

const int  PowerButton = 3;
const int VolumeUp = 5;
const int VolumeDown = 7;
int PowerButtonState = 0;     // previous state of the button
int VolumeUpState = 0;
int VolumeDownState = 0;

void setup()
{
  Serial.begin(9600); 
  pinMode(PowerButton, INPUT);
  pinMode(VolumeUp, INPUT);
  pinMode(VolumeDown, INPUT);
}
void loop() {
PowerButtonState = digitalRead(PowerButton);
//Serial.println(PowerButtonState);
while (PowerButtonState == 1) {
  Serial.println("Power Pressed");
  irsend.sendSAMSUNG(0xE0E040BF,32); // SAMSUNG - POWER
  delay(1000);
  PowerButtonState = digitalRead(PowerButton);
}
VolumeUpState = digitalRead(VolumeUp);
//Serial.println(VolumeUpState);
while (VolumeUpState == 1) {
  Serial.println("Volume Up Pressed");
  irsend.sendSAMSUNG(0xE0E0E01F,32); // SAMSUNG - Vol Up
  delay(100);
  VolumeUpState = digitalRead(VolumeUp);
}
VolumeDownState = digitalRead(VolumeDown);
//Serial.println(VolumeDownState);
while (VolumeDownState == 1) {
  Serial.println("Volume Down Pressed");
  irsend.sendSAMSUNG(0xE0E0D02F,32); // SAMSUNG - Vol Down
  delay(100);
  VolumeDownState = digitalRead(VolumeDown);
}

}
