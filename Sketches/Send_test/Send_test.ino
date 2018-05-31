#include <IRremote.h> 
IRsend irsend;
#define IR_USE_TIMER1
void setup()
{
  Serial.begin(9600); 
}
void loop() {
  /*irsend.sendSAMSUNG(0xE0E040BF,32); // SAMSUNG - POWER
  Serial.println("Sending...");
  Serial.println(SEND_PIN);
//  Serial.println(timer);
  delay(2000); // Wait 1/10 of a Second
*/
  irsend.sendSAMSUNG(0xE0E0E01F,32); // SAMSUNG - Vol Up
  Serial.println("Sending...");
  Serial.println(SEND_PIN);
//  Serial.println(timer);
  delay(2000); // Wait 1/10 of a Second

    irsend.sendSAMSUNG(0xE0E0D02F,32); // SAMSUNG - Vol Down
  Serial.println("Sending...");
  Serial.println(SEND_PIN);
//  Serial.println(timer);
  delay(2000); // Wait 1/10 of a Second
  
 
}
