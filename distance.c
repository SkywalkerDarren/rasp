#include<DHT11p7.h>
#include<stdio.h>
#include<sys/time.h>
#include<wiringPi.h>
#include<math.h>

#define ECHO 15
#define TRIG 16

float calcspeed()
{
	int temp;
	float speed;
	temp = dht11_read_val(1);
	if(temp == 255)
	{
		speed = 340;
	}
	speed = 1.402 * 287.14 * (273.15 + temp);
	speed = sqrtf(speed);
	
	return speed;
}

float dis(struct timeval tv1, struct timeval tv2){
	digitalWrite(TRIG,LOW);
	delayMicroseconds(5);
	digitalWrite(TRIG,HIGH);
	delayMicroseconds(15);
	digitalWrite(TRIG,LOW);

	while(digitalRead(ECHO) == LOW);
	gettimeofday(&tv1,NULL);
	while(digitalRead(ECHO) == HIGH);
	gettimeofday(&tv2,NULL);

	float speed = calcspeed();
	float distance = (float)((tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec) / 1000000 * speed / 2;
	
	return distance;
}

int main()
{
	struct timeval tv1;
	struct timeval tv2;
	float distance;

	printf("start\n");
	wiringPiSetup();
	pinMode(TRIG,OUTPUT);
	pinMode(ECHO,INPUT);
	for(;;)
	{
		
		distance = dis(tv1,tv2);
		
		printf("distance : %0.2f m\n",distance);

		delay(1000);
	}
	return 0;
}
