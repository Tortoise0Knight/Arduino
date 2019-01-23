const int led = 3,mac = A0;
int voice,light;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
voice = analogRead(mac);
light =(voice - 35)*3;
analogWrite(led,light);
analogWrite(led,0);
}
