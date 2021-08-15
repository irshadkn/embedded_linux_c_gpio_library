# Embedded Linux C GPIO Library

### Compile library files:
Step 1: Generate object file

    $ gcc -c gpio.c -o gpio.o

Step 2: Create static library. This step is to bundle multiple object files in one static library. Here, we have only one object file

    $ ar rcs gpio.a gpio.o 


### Compile application source code:

    $ gcc blink_led.c gpio.a -o blink_led
