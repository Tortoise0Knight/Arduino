//程序没有问题，已用led检验，但可能对蜂鸣器的硬件原理不是很清楚。
int buzzer = 2;
char sentence[60];
int time1 =100;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
int sa = Serial.available();
dark();
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
      morse(sentence[i]);
      Serial.print(i);  
      delay(time1*3);
    }
  delay(time1*10);
}

void morse(char j){
  j=toupper(j);
  switch(j){
    case ('A'):
    dark();deep();deep();deep();
         break;
    case ('C'):
    dark();deep();dark();deep();
         break;
    case ('D'):
    dark();deep();deep();
         break;
    case ('E'):
    deep();
         break;
    case ('F'):
    deep();deep();dark();deep();
         break;
    case ('G'):
    dark();dark();deep();
         break;
    case ('H'):
    deep();deep();deep();deep();
         break;
    case ('I'):
    deep();deep();
         break;
    case ('J'):
    deep();dark();dark();dark();
         break;
    case ('K'):
    dark();deep();dark();
         break;
    case ('L'):
    deep();dark();deep();deep();
         break;
    case ('M'):
    dark();dark();
         break;
    case ('N'):
    dark();deep();
         break;
    case ('O'):
    dark();dark();dark();
         break;
    case ('P'):
    deep();dark();dark();deep();
         break;
    case ('Q'):
    dark();dark();deep();dark();
         break;
    case ('R'):
    deep();dark();deep();
         break;
    case ('S'):
    deep();deep();deep();
         break;
    case ('T'):
    dark();
         break;
    case ('U'):
    deep();deep();dark();
         break;
    case ('V'):
    deep();deep();deep();dark();
         break;
    case ('W'):
    deep();dark();dark();
         break;
    case ('X'):
    dark();deep();deep();dark();
         break;
    case ('Y'):
    dark();deep();dark();dark();
         break;
    case ('Z'):
    dark();dark();deep();
         break;
    case (' '):
    delay(time1*3);
      break;
  }
  Serial.print(j);
}

void deep(){
  digitalWrite(buzzer,HIGH);
  delay(time1);
  digitalWrite(buzzer,LOW);
  delay(time1);
}

void dark(){
  digitalWrite(buzzer,HIGH);
  delay(time1*3);
  digitalWrite(buzzer,LOW);
  delay(time1);
}
