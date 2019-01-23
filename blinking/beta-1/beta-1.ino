/*
---按钮改变小灯闪烁频率---
by Tortoise Knight
2018.11.15
 */
int ledState = HIGH;
long lastTimer = 0;
int i = 0;
int led = 13;
int time1 = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode ( led,OUTPUT);
  Serial.begin(9600);  
}
 void loop() {
  // put your main code here, to run repeatedly:
  while(!digitalRead(2)){     //等待按钮变化
    if(millis()-lastTimer>time1){
    ledState = !ledState;
    lastTimer = millis();     //使用millis实现闪烁
    //Serial.println(lastTimer);
  }
  digitalWrite(led,ledState);
  }
   for (int j = 1 ; j <= 50 ; j ++){
    delay(1);
    if (digitalRead(2)){
      j = 0;
    }
  }//去抖。。.这个方法比较逊
  i++;
  switch (i%3) {
    case (0):
      time1 = 200;
      Serial.println("FAST");
      break;
    case (1):
      time1 = 500;
      Serial.println("NORMAL");
      break;
    case (2):
      time1 = 1000;
      Serial.println("SLOW");
      break;
  }//三种闪烁频率变化
}
