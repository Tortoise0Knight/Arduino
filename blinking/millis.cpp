int ledState = HIGH;
long lastTimer = 0;
int led = 13;
void setup () {
	pinMode(led,OUTPUT);
}

void loop () {
	if(Millis()-lastTimer>500){
		ledState = !ledState;
		lastTimer = Millis;
	}
	digitalWrite(led,ledState);
}

