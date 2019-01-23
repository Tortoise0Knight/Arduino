#define a 262
#define b 294
#define c 330
#define d 349
#define e 392
#define f 440
#define g 494
#define A 523
#define B 587
#define C 659
#define D 698
#define E 784
#define F 880
#define G 988

int buzzer = 2;
char sentence[60];
int time1 =300;

void setup() {
  // put your setup code here, to run once:
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
int sa = Serial.available();
while(sa==0){Serial.print("check");delay(1000);sa = Serial.available();}
}

void loop() {
  // put your main code here, to run repeatedly:
 int s = 0;
  s = Serial.available(); 
  if(s>0){
    for(int i = 1 ; i <=s ; i++){
      sentence[i]=Serial.read();
    }
  }
 for(int i = 1 ; i <=s ; i++){
     tone(buzzer,sentence[i]);
     delay(time1*2);
     noTone(buzzer);
     delay(time1);
      Serial.print(i);
 }  
}
