#include <stdio.h>
#include <wiringPi.h>
#include <ctype.h>

#define LED 6
#define LED2 5

void dit();
void dah();
void space();
void solve(char c);
char* strlwr(char *str);

char ch[36][8] = {
	{'.','-'},//a
	{'-','.','.','.'},//b
	{'-','.','-','.'},//c
	{'-','.','.'},//d
	{'.'},//e
	{'.','.','-','.'},//f
	{'-','-','.'},//g
	{'.','.','.','.'},//h
	{'.','.'},//i
	{'.','-','-','-'},//j
	{'-','.','-'},//k
	{'.','-','.','.'},//l
	{'-','-'},//m
	{'-','.'},//n
	{'-','-','-'},//o
	{'.','-','-','.'},//p
	{'-','-','.','-'},//q
	{'.','-','.'},//r
	{'.','.','.'},//s
	{'-'},//t
	{'.','.','-'},//u
	{'.','.','.','-'},//v
	{'.','-','-'},//w
	{'-','.','.','-'},//x
	{'-','.','-','-'},//y
	{'-','-','.','.'}//z
}; 
char num[10][8] = {
	{'-','-','-','-','-'},//0
	{'.','-','-','-','-'},//1
	{'.','.','-','-','-'},//2
	{'.','.','.','-','-'},//3
	{'.','.','.','.','-'},//4
	{'.','.','.','.','.'},//5
	{'-','.','.','.','.'},//6
	{'-','-','.','.','.'},//7
	{'-','-','-','.','.'},//8
	{'-','-','-','-','.'},//9
};

int main()
{
	wiringPiSetup();
	pinMode(LED,OUTPUT);
	pinMode(LED2,OUTPUT);

	char str[100];
	gets(str);
	strlwr(str);

	for(int i = 0; str[i]; i++)
	{
//		printf("%c",str[i]);
		solve(str[i]);
	}
	printf("\n");
	return 0;
}

void dit(){
	digitalWrite(LED,HIGH);
	delay(100);
	digitalWrite(LED,LOW);
	delay(200);
}

void dah(){
	digitalWrite(LED,HIGH);
	delay(500);
	digitalWrite(LED,LOW);
	delay(200);
}

void space(){
	delay(200);
	digitalWrite(LED2,HIGH);
	delay(200);
	digitalWrite(LED2,LOW);
	delay(200);
}

char* strlwr(char *str)
{
    if(str == NULL)
        return NULL;
         
    char *p = str;
    while (*p != '\0')
    {
        if(*p >= 'A' && *p <= 'Z')
            *p = (*p) + 0x20;
        p++;
    }
    return str;
}

void solve(char c){
	int i,t;
	if(c>=97 && c<=122){
		t = c - 97;
		for(i = 0; ch[t][i]; i++){
			if(ch[t][i] == '.'){
				dit();
				printf(".");
			}
			if(ch[t][i] == '-'){
				dah();
				printf("-");
			}
		}
		space();
		printf("/");
	}else if(c>=48 && c<=57){
		t = c - 48;
		for(i = 0; ch[t][i]; i++){
			if(ch[t][i] == '.'){
				dit();
				printf(".");
			}
			if(ch[t][i] == '-'){
				dah();
				printf("-");
			}
		}
		space();
		printf("/");
	}else{
		space();
		printf("/");
	}
}

