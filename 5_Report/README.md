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

The stopwatch project that we are going to build has these following features:

- Stopwatch counting up to hundredth of second when the SW1 is pressed
- Pressing the SW1 once will freeze the counting display while continuing counting in the background, pressing the SW1  again will continue to display the stopwatch counting
- Adjust the intensity of the 8-Digits seven segment LED display using the trimmer potentiometer (TP).
- Reset the stopwatch counting by pressing the SW0.
