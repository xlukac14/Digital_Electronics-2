# Lab 5: Vladimír Lukáč

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs](https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs)


### 7-segment library

1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD -> Common Cathode connected to logical 0, controling segments via connecting logical 1
   * CA SSD -> Common Anode connected to logical 1, controling segments via connecting logical 0

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER0_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
    citac ++;
    
    digit0 = citac / 10;
    digit1 = citac % 10;
}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;
    
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
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![image1](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/05-segment/images/image1.jpg)


### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![image2](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/05-segment/images/image2.PNG)
