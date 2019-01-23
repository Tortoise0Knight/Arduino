#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int irPin = 10;
int time1;

IRrecv ir(irPin);
  decode_results results;

void setup() {
  // put your setup code here, to run once:
  ir.enableIRIn();
  Serial.begin(9600);
  time1 = millis();
}

void loop() {
  // put your main code here, to run repeatedly
  if(ir.decode(&results)){
    Serial.println(results.value,HEX);
    Serial.println(millis()-time1);
    time1 = millis();
    ir.resume();
  }
 // delay(100);
}
