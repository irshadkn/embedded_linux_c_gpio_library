#include <stdio.h>
#include "gpio.h"

void delay(int n) 
{ 
	for(int i=0; i<=5000; i++)
		for(int j=0; j<=25000;j++); 
}

int main()
{
	gpio_init(18);
        gpio_mode(18, "out");
	printf("Blinking...\n");
	while(1)
	{
		gpio_set(18, 1);
		printf("%d\n", gpio_read(18));
		delay(1);
		gpio_set(18, 0);
		printf("%d\n", gpio_read(18));
		delay(1);
	}
}
