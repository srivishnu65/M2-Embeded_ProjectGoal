# INTRODUCTION
One of the basic usage of the TIMER peripheral on every microcontroller is to provide the accurate timing mechanism. Using the TIMER peripheral as the basic timing, easily developed a stopwatch and display it to the 8-Digit seven segment numeric LED display.

we also used Maxim MAX7219 chip which enable us to interface this 8-Digit seven segment LED display much easier using just three wires of the SPI (serial peripheral interface) to display the hour, minute, second, and hundredth of seconds to the 8-Digit seven segments LED display.

Atmel AVR ATMega328P microcontroller SPI peripheral to communicate with the Maxim MAX7219 chip is used. The AVR ATmega328P SPI peripheral will be configured as a master and Maxim MAX7219 as the SPI device slave.


# Components used
1. One Maxim MAX7219: Serially Interfaced, 8-Digit LED Display Drivers
2. Two common cathode 4-Digits seven segment LED display
3. One Resistor: 10K Ohm
4. One Capacitors 0.1uF
5. AVRJazz 28PIN development board from ermicro which is based on the AVR ATmega328P microcontroller.
6. Atmel AVR ATmega328 and Maxim MAX7219 Datasheet

## Features
- Stopwatch counting up to hundredth of second when the SW1 is pressed
- Pressing the SW1 once will freeze the counting display while continuing counting in the background, pressing the SW1  again will continue to display the stopwatch counting
- Adjust the intensity of the 8-Digits seven segment LED display using the trimmer potentiometer (TP).
- Reset the stopwatch counting by pressing the SW0.

![image](https://user-images.githubusercontent.com/94337426/144262139-2b94a331-ff4c-422c-a1cc-fc9f0e6f6e27.png)

The stopwatch project that build has these following features:

- Stopwatch counting up to hundredth of second when the SW1 is pressed
- Pressing the SW1 once will freeze the counting display while continuing counting in the background, pressing the SW1  again will continue to display the stopwatch counting
- Adjust the intensity of the 8-Digits seven segment LED display using the trimmer potentiometer (TP).
- Reset the stopwatch counting by pressing the SW0.

# The Maxim MAX7219
The MAX7219 chip from maxim is a powerful serial input/output common-cathode display driver that interfaces microcontroller to 7-segment numeric LED displays of up to 8 digits. It has a build-in BCD (binary code decimal) decoder and a brightness control. Although the main function is to drive the 8-Digits seven segment LED display but because it also capable to drive an individual LED segment i.e. segment A to segment G and DP (decimal point), therefore you could also use this chip to drive the individual LED, the LED bar-graph, or the 8×8 LED matrix display. The MAX7219 could easily be daisy-chained (cascaded) to another MAX7219 chip using the DOUT pin which is useful when you want to drive 16-Digits LED display or several LED matrix display.
![image](https://user-images.githubusercontent.com/94337426/144263154-2118805d-7b43-4b3e-975a-6769706c0674.png)
# The AVR ATmega328P TIMER1 Peripheral
The 16-bits TIMER1 peripheral is the heart beat of this stopwatch project. We used this 16-bit TIMER1 as it give more flexibility to implement the stopwatch, because of the 16-bit counter length, therefore it could counting up to 65.536 before overflow. We will use TIMER1 16-bit output compare register OCR1A  as the base of our hundredth of seconds counter.
![Diagram A](https://user-images.githubusercontent.com/94337426/144263530-896bc14a-0d9e-4dc9-a532-a9e58cb522c7.jpg)

The Output Compare Register A (OCR1A) will be the maximum value of TCNT1 register counter before it generate an interrupt. Using the AVRJazz 28PIN development board 16 Mhz external crystal resonator with prescaler of 8, we could calculate the TIMER1 clock period as follow:

TIMER1 Clock Period = 1 / (16000000 / 8) = 0.0000005 seconds

To get a hundredth of seconds period, the TIMER1 digital counter TCNT1 register will need to count up to value of 20,000:

The hundredth of seconds = 20000 x 0.0000005 seconds = 0.01 seconds.

By assigning this value to the OCR1A register and activate the output compare register A interrupt, the compare match interrupt will be generated every 0.01 seconds.
# The AVR ATmega328P External Interrupt
![Diagram a e](https://user-images.githubusercontent.com/94337426/144264214-108af777-95f5-4d0a-b991-c401febde066.jpg)
# Result

Hence,Stop watch is bulid with Atmega328 and The Maxim MAX7219
