int i = 0;
int LED = 13;
int time1 = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode ( LED,OUTPUT);
  Serial.begin(9600);  
}
 void loop() {
  // put your main code here, to run repeatedly:
  while(!digitalRead(2)){
    digitalWrite(LED , HIGH);
    delay (time1);
    digitalWrite(LED , LOW);
    delay (time1); 
  }
   for (int j = 1 ; j <= 50 ; j ++){
    delay(1);
    if (digitalRead(2)){
      j = 0;
    }
  }
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
  }
}
