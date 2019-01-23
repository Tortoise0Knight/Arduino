int IN1 = 4;
int EN1 = 5;
int IN2 = 6;
int EN2 = 7;
int irPin = 10;

void setup() {
  // put your setup code here, to run once:
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
delay(1000);
analogWrite(EN1,240);
  analogWrite(EN2,180);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
delay(3000);
analogWrite(EN1,0);
  analogWrite(EN2,0);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
