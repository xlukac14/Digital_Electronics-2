/*
 * LAB02_LED-Button.c
 *
 * Created: 30.09.2021 11:49:25
 * Author : Lukac Vladimir
 */ 


#define LED_BLUE    PB5     // AVR pin where green LED is connected
#define LED_GREEN   PC0
#define BUTTON      PD0
#define BLINK_DELAY 500
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h>
/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
     // Green LED at port B
     // Set pin as output in Data Direction Register...
     DDRB = DDRB | (1<<LED_GREEN);
     // ...and turn LED off in Data Register
     PORTB = PORTB & ~(1<<LED_GREEN);

     // Configure the second LED at port C
     DDRC = DDRC | (1<<LED_BLUE);
     
     PORTC = PORTC & ~(1<<LED_BLUE);
     // Configure Push button at port D and enable internal pull-up resistor
    
     DDRD =  DDRD & ~(1<<BUTTON);
     
     PORTD = PORTD | (1<<BUTTON);

     // Infinite loop
     while (1)
     {
         // Pause several milliseconds
         //_delay_ms(BLINK_DELAY);

         //PORTB = PORTB ^ (1<<LED_GREEN);      
         
         //PORTC = PORTC ^ (1<<LED_BLUE);
         
         if(bit_is_clear(PIND,BUTTON))
         {
             PORTB = PORTB ^ (1<<LED_GREEN);
             
             PORTC = PORTC ^ (1<<LED_BLUE);
             
             loop_until_bit_is_set(PIND,BUTTON);
         }
         
     }


    // Will never reach this
    return 0;
}