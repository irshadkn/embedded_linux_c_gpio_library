//LIBRARY: EMBEDDED LINUX GPIO LIBRARY
//VERSION: 1.0
//AUTHOR: MUHAMMED IRSHAD
//MAIL: irshad.kn@gmail.com
//USAGE:
//1.Initialise the GPIO Pin:
//      gpio_init(18);  <-- Here 18 is the GPIO Number
//2.Release the GPIO Pin:
//      gpio_release(18);
//3.Set Input or Output Mode:
//      gpio_mode(18, "out"); or gpio_mode(18, "in");
//4.Set High or Low Status:
//      gpio_set(18, 1); or gpio_set(18,0);
//5.Read Pin Status:
//      gpio_read(18);  <-- Return either 0 or 1;

#include"gpio.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void gpio_init(int pin)
{
        char command1[35] = "echo ";
        char command2[29];
        sprintf(command2, "%d", pin);
        char command3[26] = " > /sys/class/gpio/export";
        system(strcat(command1, strcat(command2, command3)));
}

void gpio_release(int pin)
{
        char command1[37] = "echo ";
        char command2[31];
        sprintf(command2, "%d", pin);
        char command3[28] = " > /sys/class/gpio/unexport";
        system(strcat(command1, strcat(command2, command3)));
}

void gpio_mode(int pin, char* direction)
{
        char command1[48] = "echo ";
        char command2[42];
        sprintf(command2, "%s", direction);
        char command3[38] = " > /sys/class/gpio/gpio";
        char command4[14];
        sprintf(command4, "%d", pin);
        char command5[11] = "/direction";
        system(strcat(command1, strcat(command2, strcat(command3, strcat(command4, command5)))));
}

void gpio_set(int pin, int value)
{
        char command1[46] = "echo ";
        char command2[40];
        sprintf(command2, "%d", value);
        char command3[38] = " > /sys/class/gpio/gpio";
        char command4[14];
        sprintf(command4, "%d", pin);
        char command5[11] = "/value";
        system(strcat(command1, strcat(command2, strcat(command3, strcat(command4, command5)))));
}

int gpio_read(int pin)
{
	FILE *fp;
	int status;
        char path1[31] = "/sys/class/gpio/gpio" ;
	char path2[10] ="";
	sprintf(path2, "%d", pin);
	char path3[7] = "/value"; 
	fp = fopen(strcat(path1, strcat(path2, path3)), "r");
        fscanf(fp, "%d", &status);
        fclose(fp);
	return status;
}

