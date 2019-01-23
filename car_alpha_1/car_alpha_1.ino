/* 现在最大的问题是controlMode，
 * 如何收取红外信号而不终止该模式
 * 解决方案？：直接把controlMode整合到loop函数里去！
 */
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <NewPing.h>

int irPin = 
int IN1 = 
int IN2 = 
int PWMA = 
int IN3 = 
int IN4 = 
int PWMB = 
int trigPin1 =
int echoPin1 = 
int trigPin2 =
int echoPin2 =
int trackPin1 = 
int trackPin2 = 
int buzzerPin = 
int speed1 =
int baseTime =
boolean powerState = true;
unsigned long lastTime;
String mode;
NewPing SR04[2]={
  NewPing(trigPin1,echoPin1,450),
  NewPing(trigPin2,echoPin1,450),
}

IRrecv ir(irPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,runAway,LOW);
  Serial.begin(9600);
  ir.enableIRIn();
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  pinMode(trackPin1,INPUT);
  pinMode(trackPin2,INPUT);
  pinMode(irPin,INPUT);
  
  while(ir.decode(&results) == 0){}
}

void loop() {
  // put your main code here, to run repeatedly:
  mode = "control";
  if(millis()- time1 > 100){
    time1 = millis();
    switch(results.value){
      case 0x :
        ir.resume();
        digitalWrite(buzzerPin,HIGH);
        delay(200);
        digitalWrite(buzzerPin,LOW);
        avoidanceMode();
        break;
      case 0x :
        ir.resume();
        digitalWrite(buzzerPin,HIGH);
        delay(200);
        digitalWrite(buzzerPin,LOW);
        trackingMode();
        break;
      case 0x :
        ir.resume();
        digitalWrite(buzzerPin,HIGH);
        delay(200);
        digitalWrite(buzzerPin,LOW);
        controlMode();
        break;
      case 0x :
        ir.resume();
        digitalWrite(buzzerPin,HIGH);
        delay(200);
        digitalWrite(buzzerPin,LOW);
        stopMode();
        break;
      default :
        ir.resume();
        break;
    }
  }
}

void avoidanceMode(){
  mode = "avoidance";
  powerState = true；
  lastTime = millis();
  while(ir.decode(&results) == 0){
    forward();
    if(millis() - lastTime > 150){
      lastTime = millis();
      int distances[2];
      for (int i = 0; i < 2; i ++){
          delay(50);
          distances[i] = SR04[i].ping_cm();
      }
      if (distaces[0] < 10 || distances[1] < 10){
        switch(distances[0] - distances[1]){
          case >= 0 :
            leftForward();
            delay(baseTime);
            break;
          case < 0;
            rightForwrd();
            delay(basetime);
            break;
        }
      }
    }
  }
}


void stopMode(){
  powerState = !powerState;
  if (powerState == true){
    if (mode == "avoidance"){
      avoidanceMode();
    }
    else if (mode == "tracking"){}
    else if (mode == "control"){
      controlMode();
    }
  }
  else {
    stop1();
  }
}

void trackingMode(){
  mode = "tracking";
  powerState = true；
  while(ir.decode(&results) == 0){
    if(digitalRead(trackPin1) == HIGH && digitalRead(trackPin2) = HIGH){
      forward();
    }
    else if(digitalRead(trackPin1) == HIGH && digitalRead(trackPin2) = LOW){
      rightForward();
    }
    else if(digitalRead(trackPin1) == LOW && digitalRead(trackPin2) = HIGH){
      leftForward();
    }
  }
}

void controlMode(){
  mode = "control";
  lastTime = millis();
  while(ir.decode(&results) == 0)){
    if(millis()-time1 > 100){ //接收红外的时长大概是100零几秒所以设定100延时
      time1 = millis();
      if(ir.decode(&results)){
        switch(results.value){
          case 0xFFA857 ://这个红外编码不是最终确定的
            ir.resume();
            forward();
            break;
          case 0xFFFFFFFF ://代表一直按下的红外编码
            ir.resume();
            break;
        }      
      }
      else{stop1();}
    }
  }
}


void forward(){
  analogWrite(PWMA,speed1);
  analogWrite(PWMB,speed1);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void backward(){
  analogWrite(PWMA,speed1);
  analogWrite(PWMB,speed1);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void leftForward(){
  analogWrite(PWMB,speed1);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void rightForward(){
  analogWrite(PWMA,speed1);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void leftBackward(){
  analogWrite(PWMB,speed1);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void rightBackward(){
  analogWrite(PWMA,speed1);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void stop1(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void runAway (){
  digitalWrite(buzzerPin,HIGH);
  backward();
  delay()//具体时间和速度实测后再确定
  leftBackward();
  delay();
  digitalWrite(buzzerPin,LOW);
  forward();
}


/*void motor(int pin1,int pin2,int pwm,int speed1, boolean forward){
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  analogWrite(pwm,speed1);
  digitalWrite(pin1,forward);
  digitalWrite(pin2,!forward);
}

void turnLeft(int speed1){
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  analogWrite(PWMB,speed1);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}*/
