/***********************************************************************
 * 
 * Decimal counter with 7-segment output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "segment.h"        // Seven-segment display library for AVR-GCC

#define volatile uint8_t digit0;
.
.
.

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Display decimal counter values on SSD (Seven-segment 
 *           display) when 16-bit Timer/Counter1 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Configure SSD signals
    SEG_init();

    // Test of SSD: display number '3' at position 0
    //SEG_update_shift_regs(0b00001101, 0b00010000);
    SEG_update_shift_regs(3,0);
    
    // Configure 16-bit Timer/Counter1 for Decimal counter
    // Set the overflow prescaler to 262 ms and enable interrupt
    
    TIM1_overflow_262ms();
    
    // Enables interrupts by setting the global interrupt mask
    TIM1_overflow_interrupt_enable();
    sei();
    
    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment decimal counter value and display it on SSD.
 **********************************************************************/

ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
    citac ++;
    
    digit0 = citac / 10;
    digit1 = citac % 10;
}

ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;
    // doplnit reset po dosiahnuti 59... 60 -> 0
    if(pos == 0)
    {
        SEG_update_shift_regs(digit0,0);
        pos++;
    }
    else
    {
        SEG_update_shift_regs(digit1,1);
        pos = 0;
    }

}