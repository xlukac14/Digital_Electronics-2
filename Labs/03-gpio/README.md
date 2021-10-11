# Lab 3: Vladimír Lukáč

Link to my `Digital-electronics-2` GitHub repository:

   [https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs](https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs)


### Data types in C

1. Complete table.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | -128 to 127 | 8-bit integer |
| `uint16_t` | 16 | 0 to 65 535 | Unsigned 16-bit integer |
| `int16_t`  | 16 | -32768 to 32767 | 16-bit integer |
| `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | 0 | 0 | Won't return any value |


### GPIO library

1. In your words, describe the difference between the declaration and the definition of the function in C.

   * Function declaration -> set names and data types only for function and their inputs (file suffix -> .h)
   * Function definition -> write function body (file suffix -> .c)

2. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Use function from your GPIO library. Let the push button is connected to port D:

```c
    // Green LED at port B
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write_low(&PORTB, LED_GREEN);

    // Configure the second LED at port C
    GPIO_config_output(&DDRC, LED_BLUE);
    GPIO_write_low(&PORTC, LED_BLUE);
    
    // Configure Push button at port D and enable internal pull-up resistor
    GPIO_config_input_pullup(&DDRD, BUTTON);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        //_delay_ms(BLINK_DELAY);
        // WRITE YOUR CODE HERE
	if(GPIO_read(&PIND,0))
	{
		GPIO_toggle(&PORTB, LED_GREEN);
		GPIO_toggle(&PORTC, LED_BLUE);
		_delay_ms(BLINK_DELAY);
	}
		
    }

```


### Traffic light

1. Scheme of traffic light application with one red/yellow/green light for cars and one red/green light for pedestrians. Connect AVR device, LEDs, resistors, one push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![Traffic light](https://github.com/xlukac14/Digital_Electronics-2/tree/main/Labs/03-gpio/images/image1.PNG)
