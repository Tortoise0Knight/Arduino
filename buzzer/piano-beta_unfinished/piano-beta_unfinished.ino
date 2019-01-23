int buzzer = 2;
char sentence[60];
int time1 =300;
char lyric[5];

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
    if(sentenc[i]=' '){
      piano(lyric);
      lyric =   //啊啊啊如何清空一个数组？
    }
    lyric[i]=sentence[i];
    //当一个元素为空的时候它会读出什么？
  }
}

void piano( ){
  
}
