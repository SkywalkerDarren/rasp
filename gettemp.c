#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#include <sys/type.h>
//#include <sys/stat.h>
#include <fcntl.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_SIZE 32
int main ()
{
    int fp;
    double temp;
    char text[MAX_SIZE];
    char jud = 0;

    fp = open(TEMP_PATH, O_RDONLY);
    if(fp < 0)
    {
        fprintf(stderr,"open fail");
        return -1;
    };

    if(read(fp, text, MAX_SIZE) < 0)
    {
        fprintf(stderr,"read fail");
        return -2;
    }

    for(;;)
    {
        temp = atoi(text) / 1000.0;
        printf("temp: %.2lf\n", temp);
        read(fp, text, MAX_SIZE);
        sleep(1);
//        jud = getch();
//        if(jud == ' ')break;
    }
    close(fp);

    return 0;
}
