int i = 0;
int LED = 13;
int time = 500;
void setup() {
  // put your setup code here, to run once:
pinMode ( LED , OUTPUT);
attachInterrupt(0 , change , RISING);
Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED , HIGH);
delay (time);
digitalWrite(LED , LOW);
delay (time); 
}

void change () {
	for (int j = 1 , j <= 50 , j++) {
	delay ( 1 );
	if(digitalRead(2)){
		i =  0;
	}
  i++;
  if (i % 3 == 0){
    time = 500;
    Serial.print("Fast");
  }
  else if (i % 3 == 1){
    time = 1000;  
    Serial.print("Normal");
  }
  else if (i % 3 == 2){
    time = 2000;
	Serial.print("Slow");  
  }
}

