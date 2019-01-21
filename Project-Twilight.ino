/* by Tortoise Knight 楼道灯
 * 平常红色指示灯亮，
 * 发声后绿色照明灯亮，红灯灭，蜂鸣提醒，
 * 五秒后恢复原状，两声蜂鸣提醒
 * <2.0版增加每10分钟自动校准基准噪音，5秒采集50次，红灯闪烁>
 */
 
int standard = 30;
int modify[10];
int time1 = 0;
int lasttime = 0;
int sound;
int greenled = 2;
int redled = 3;
int mic = A0;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(greenled,OUTPUT);
pinMode(redled,OUTPUT);
pinMode(buzzer,OUTPUT);
digitalWrite(redled,HIGH);
for(int i = 1;i <= 10;i++){
      Serial.println(analogRead(mic));
      standard += analogRead(mic);
      digitalWrite(redled,LOW);
      delay(500);
      digitalWrite(redled,HIGH);
    }
    standard = standard / 10;
    Serial.print("standard= ");
    Serial.println(standard);
}

void loop() {
  // put your main code here, to run repeatedly:
  time1 = millis();
  if (time1 - lasttime > 600000){
    lasttime = time1;
    for(int i = 1;i <= 10;i++){
      Serial.println(analogRead(mic));
      standard += analogRead(mic);
      digitalWrite(redled,LOW);
      delay(500);
      digitalWrite(redled,HIGH);
    }
    standard = standard / 10;
    Serial.print("standard= ");
    Serial.println(standard);
  }
  sound = analogRead(mic);
  if(sound>standard+5){
    Serial.println(sound);
    digitalWrite(redled,LOW);
    digitalWrite(greenled,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(300);
    digitalWrite(buzzer,LOW);
    delay(4400);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
  }
}
