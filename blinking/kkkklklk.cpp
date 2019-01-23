int ledState = HIGH;
long lastTimer = 0;
int led = 13;
void setup () {
	pinMode(led,OUTPUT);
}

void loop () {
	if(millis()-lastTimer>500){
		ledState = !ledState;
		lastTimer = millis;
	}
	digitalWrite(led,ledState);
}

