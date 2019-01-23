#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int IN1 = 4;
int EN1 = 5;
int IN2 = 6;
int EN2 = 7;
int irPin = 10;
unsigned long time1; 
IRrecv ir (irPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  time1 = millis();
  ir.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-time1 > 300){
    Serial.println(time1/1000);
    time1 = millis();
    if(ir.decode(&results)){
      Serial.println(results.value,HEX);
      ir.resume();
      switch(results.value){
        case 0xA3C8EDDB :
          ir.resume();
          forward();
          Serial.println("hhhhhhhhhhhhhhhhhhhhh");
          break;
        case 0xFFFFFFFF :
          ir.resume();
          break;
      }
            
    }
    else{stop1();}
  }
}

void forward(){
  analogWrite(EN1,240);
  analogWrite(EN2,180);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
}

void stop1(){
  analogWrite(EN1,0);
  analogWrite(EN2,0);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}
