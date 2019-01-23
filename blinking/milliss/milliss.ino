int ledState = HIGH;
long lastTimer = 0;
int led = 13;
void setup () {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop () {
  if(millis()-lastTimer>500){
    ledState = !ledState;
    lastTimer = millis();
    Serial.println(lastTimer);
  }
  digitalWrite(led,ledState);
  
}

