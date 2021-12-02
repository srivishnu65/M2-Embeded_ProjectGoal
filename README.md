# Building stopwatch using Atmega328 and Maxim MAX7219 chip
# INTRODUCTION
One of the basic usage of the TIMER peripheral on every microcontroller is to provide the accurate timing mechanism. Using the TIMER peripheral as the basic timing, easily developed a stopwatch and display it to the 8-Digit seven segment numeric LED display.

we also used Maxim MAX7219 chip which enable us to interface this 8-Digit seven segment LED display much easier using just three wires of the SPI (serial peripheral interface) to display the hour, minute, second, and hundredth of seconds to the 8-Digit seven segments LED display.

Atmel AVR ATMega328P microcontroller SPI peripheral to communicate with the Maxim MAX7219 chip is used. The AVR ATmega328P SPI peripheral will be configured as a master and Maxim MAX7219 as the SPI device slave.




## Features
- Stopwatch counting up to hundredth of second when the SW1 is pressed
- Pressing the SW1 once will freeze the counting display while continuing counting in the background, pressing the SW1  again will continue to display the stopwatch counting
- Adjust the intensity of the 8-Digits seven segment LED display using the trimmer potentiometer (TP).
- Reset the stopwatch counting by pressing the SW0.



# Badges
[![cppcheck-action-test](https://github.com/srivishnu65/M2-Embeded_ProjectGoal/actions/workflows/cpp.yml/badge.svg)](https://github.com/srivishnu65/M2-Embeded_ProjectGoal/actions/workflows/cpp.yml)
![](https://api.codiga.io/project/29841/score/svg)
![](https://api.codiga.io/project/29841/status/svg)
