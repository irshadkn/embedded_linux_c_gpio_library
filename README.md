# embedded_linux_c_gpio_library

Compile library files:

Step 1: Generate object file

gcc -c gpio.c -o gpio.o
 
Step 2: Create static library. This step is to bundle multiple object files in one static library. Here, we have only one object file

ar rcs gpio.a gpio.o 
 
