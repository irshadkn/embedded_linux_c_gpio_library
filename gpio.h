//LIBRARY: EMBEDDED LINUX GPIO LIBRARY
//VERSION: 1.0
//AUTHOR: MUHAMMED IRSHAD
//MAIL: irshad.kn@gmail.com
//USAGE:
//1.Initialise the GPIO Pin:
//	gpio_init(18);	<-- 18 is the GPIO Number
//2.Release the GPIO Pin:
//	gpio_release(18); 
//3.Set Input or Output Mode:
//	gpio_mode(18, "out"); or gpio_mode(18, "in");
//4.Set Pin High or Low:
//	gpio_set(18, 1); or gpio_set(18,0);
//5.Read Pin Status:
//	gpio_read(18);	<-- Returns either 0 or 1;

#ifndef __GPIO_H__
#define __GPIO_H__

void gpio_init(int);
void gpio_release(int);
void gpio_mode(int, char*);
void gpio_set(int, int);
int gpio_read(int);

#endif
