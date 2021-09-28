# Lab 02-Git version-control system, AVR tools

## My GitHub repository

https://github.com/xlukac14/Digital_electronics-2

## Task1: AVR development tools - Microchip Studio

![Uninstall/Repair](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/01-Tools/LED/images/image1.PNG)

![main.c](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/01-Tools/LED/images/image2.PNG)

## Task2: Morse code with LED

```c
/***********************************************************************
 * 
 * Blink a LED and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
/* The preprocessor will process directives that are inserted into the C
 * source code. These directives allow additional actions to be taken on
 * the C source code before it is compiled into object code. Directives
 * are not part of the C language itself.
 *
 * Preprocessor directives begin with a pound (#) symbol and may have 
 * several arguments. Do NOT put a semicolon character at the end of 
 * directives. This is a common mistake.
 */
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define SHORT_DELAY1 100    // Delay for dot
#define SHORT_DELAY2 300   // Delay for underline
#define SHORT_DELAY3 1000   // Delay between letters
#ifndef F_CPU               // Preprocessor directive allows for conditional
                            // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif                      // The #ifndef directive must be closed by #endif

/* Includes ----------------------------------------------------------*/
/* Include another C language file into the current file at the location
 * of the #include statement prior to compiling the source code.
 */
#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY2);        // D

        // Invert LED in Data Register
        // PORTB = PORTB xor 0010 0000
        PORTB = PORTB ^ (1<<LED_GREEN);
       
        _delay_ms(SHORT_DELAY1);
        PORTB = PORTB ^ (1<<LED_GREEN);  // D
       
        _delay_ms(SHORT_DELAY1);
        PORTB = PORTB ^ (1<<LED_GREEN);  // D
        
        _delay_ms(SHORT_DELAY3);
        PORTB = PORTB ^ (1<<LED_GREEN);  // space
        
         _delay_ms(SHORT_DELAY1);
        PORTB = PORTB ^ (1<<LED_GREEN);  //E
        
        _delay_ms(SHORT_DELAY3);
        PORTB = PORTB ^ (1<<LED_GREEN);  // space

        _delay_ms(SHORT_DELAY1);
        PORTB = PORTB ^ (1<<LED_GREEN);  // 2
        
        _delay_ms(SHORT_DELAY1);
        PORTB = PORTB ^ (1<<LED_GREEN);  // 2
        
        _delay_ms(SHORT_DELAY2);
        PORTB = PORTB ^ (1<<LED_GREEN);  // 2
        
        _delay_ms(SHORT_DELAY2);
        PORTB = PORTB ^ (1<<LED_GREEN);  // 2

        _delay_ms(SHORT_DELAY2);
        PORTB = PORTB ^ (1<<LED_GREEN);  // 2

        _delay_ms(SHORT_DELAY3);         // space
    }

    // Will never reach this
    return 0;
}
```

## Task3: Simulation of Morse code application in SimulIDE

### Circuit with ATmega328 AVR microcontroller

![circuit](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/01-Tools/LED/images/image3.PNG)

### LED Morse code

![mcode](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/01-Tools/LED/images/image4.PNG)

![mcode](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/01-Tools/LED/images/image5.PNG)

