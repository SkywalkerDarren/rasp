#include <stdio.h>
#include <wiringPi.h>
#define PIN 29
#define LED 28
int main()
{
	wiringPiSetup();
	pinMode(PIN,INPUT);
	pinMode(LED,OUTPUT);
	digitalWrite(LED,LOW);
	for(;;){
		if(digitalRead(PIN) == HIGH)
		{
			//printf("1\n");
			digitalWrite(LED,HIGH);
		}else if (digitalRead(PIN) == LOW)
		{
			//printf("no body\n");
			digitalWrite(LED,LOW);
		}
		delay(1000);
	}
	return 0;
}
