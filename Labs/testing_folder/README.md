| **Program address** | **Source** | **Vector name** | **Description** |
| :-: | :-- | :-- | :-- |
| 0x000 | RESET | -- | Reset of the system |
| 0x002 | INT0  | `INT0_vect`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | External interrupt request number 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
| 0x003 | INT1 |  |  |
|  | PCINT0 |  |  |
|  | PCINT1 |  |  |
|  | PCINT2 |  |  |
|  | WDT |  |  |
|  | TIMER2_OVF |  |  |
| 0x0018 | TIMER1_COMPB | `TIMER1_COMPB_vect` | Compare match between Timer/Counter1 value and channel B compare value |
| 0x001A | TIMER1_OVF | `TIMER1_OVF_vect` | Overflow of Timer/Counter1 value |
|  | TIMER0_OVF |  |  |
|  | USART_RX |  |  |
|  | ADC |  |  |
|  | TWI |  |  |


| **Module** | **Description** | **MCU pin** | **Arduino pin** |
| :-: | :-: | :-: | :-: |
| Timer/Counter0 | OC0A | PD6 | 6 |
| Timer/Counter0 | OC0B | PD5 | 24? |
| Timer/Counter1 | OC1A | PB1 | 9|
| Timer/Counter1 | OC1B | PB2 | 10 |
| Timer/Counter2 | OC2A | PB3 | 11 |
| Timer/Counter2 | OC2B | PD3 | 3 |