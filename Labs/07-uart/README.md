# Lab 7: Vladimír Lukáč

Link to this file in your GitHub repository:

[https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs/07-uart](https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs/07-uart)


### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 100 |
   | Down   | 1.2&nbsp;V | 246 | 245 |
   | Left   | 1.97&nbsp;V | 403 | 402 |
   | Select | 3.18&nbsp;V | 651 | 650 |
   | none   | 5&nbsp;V | 1023 | 1022 |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/

ISR(ADC_vect)
{
    // WRITE YOUR CODE HERE
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);  // Convert decimal value to string
    
    lcd_clrscr();
 
    lcd_gotoxy(1, 0); lcd_puts("value:");
    lcd_gotoxy(3, 1); lcd_puts("key:");
 

    if(value > 1023)
    {
	lcd_gotoxy(8, 0);
	lcd_puts(lcd_string);
	itoa(value, lcd_string, 16);
	lcd_gotoxy(8, 1);
	lcd_puts("non");
	lcd_gotoxy(13,0);
	lcd_puts(lcd_string);
	uart_puts(lcd_string);
	uart_puts("\n\r");
    }
	
    else if(value > 640)
    {
	lcd_gotoxy(8, 0);
	lcd_puts(lcd_string);
	itoa(value, lcd_string, 16);
	lcd_gotoxy(8, 1);
	lcd_puts("select");
	lcd_gotoxy(13,0);
	lcd_puts(lcd_string);
	uart_puts(lcd_string);
	uart_puts("\n\r");
		
    else if(value > 409)
    {
	lcd_gotoxy(8, 0);
	lcd_puts(lcd_string);
	itoa(value, lcd_string, 16);
	lcd_gotoxy(8, 1);
	lcd_puts("left");
	lcd_gotoxy(13,0);
	lcd_puts(lcd_string);
	uart_puts(lcd_string);
	uart_puts("\n\r");
    }
			
    else if(value > 257)
    {
         lcd_gotoxy(8, 0);
	 lcd_puts(lcd_string);
	 itoa(value, lcd_string, 16);
	 lcd_gotoxy(8, 1);
	 lcd_puts("Down");
	 lcd_gotoxy(13,0);
	 lcd_puts(lcd_string);
	 uart_puts(lcd_string);
	 uart_puts("\n\r");
    }
	
    else if(value > 99)
    {
	lcd_gotoxy(8, 0);
	lcd_puts(lcd_string);
	itoa(value, lcd_string, 16);
	lcd_gotoxy(8, 1);
	lcd_puts("Up");
	lcd_gotoxy(13,0);
	lcd_puts(lcd_string);
	uart_puts(lcd_string);
	uart_puts("\n\r");
    }
	
    else if(value > 0)
    {
	lcd_gotoxy(8, 0);
	lcd_puts(lcd_string);
	itoa(value, lcd_string, 16);
	lcd_gotoxy(8, 1);
	lcd_puts("Right");
	lcd_gotoxy(13,0);
	lcd_puts(lcd_string);
	uart_puts(lcd_string);
	uart_puts("\n\r");
    }
		
}
```

### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![image1](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/07-uart/images/image1.jpg)

2. Flowchart figure for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![image2](https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs/07-uart/images)


### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![image3](https://github.com/xlukac14/Digital_Electronics-2/blob/main/Labs/07-uart/images/image3.jpg)