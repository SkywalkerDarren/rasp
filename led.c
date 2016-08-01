#include <wiringPi.h>
#include <stdio.h>

#define LED1 5
#define LED2 6
#define LED3 24
#define LED4 25

int main()
{
    wiringPiSetup();
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(LED4,OUTPUT);
    int i;
    for(int cnt = 0; cnt < 50; cnt++)
    {
        digitalWrite(LED1,HIGH);
        delay(100);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,HIGH);
        delay(100);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,HIGH);
        delay(100);
        digitalWrite(LED4,LOW);
    }
    return 0;
}
