const int led = 2,mac = A0;
int voice;
inline void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
Serial.begin(9600);
}

inline void loop() {
  // put your main code here, to run repeatedly:
voice = analogRead(mac);
  if(voice>35){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
  }
}
