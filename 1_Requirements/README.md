
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



# Software Used
1. SimulIDE
2. Visual Studio

## Folder Structure
|Folder             | Description |
|-------------------| -----------------------------------------|
| `1_Requirements`   | Documents detailing requirements and research|
| `2_Design`         | Documents specifying design details|
| `3_Implementation` | All code and documentation|
| `4_TestplanAnd Output`      | Documents with test plans and procedures

## SWOT- Strengths, and Weakness, Opportunities Threats
### Strengths
- User Friendly
- Modular Approach
- Low cost and Robust system.
## Threats
1. Cannot use stop watch for longtime.

# 4W's and 1 H's
## Why:
1. To record the exact time of submittion.
2. It can be used at one place.

## Where:
1. This can be used in sports,home.
2. We can use it in the  Industries, Shopping Malls etc.

## Who:
 This Device can be used by anyone, It is easy to use .

## When:
 This project is used for recording time in sports.

## How:
 Atmel AVR ATMega328P microcontroller SPI peripheral to communicate with the Maxim MAX7219 chip is used. The AVR ATmega328P SPI peripheral will be configured as a master and Maxim MAX7219 as the SPI device slave.

## Detail requirements
### High Level Requirements
| High Level Requirements      | Description |
| ----------- | ----------- |
| HLR1      |  Maxim MAX7219: Serially Interfaced, 8-Digit LED Display Drivers  |
| HLR2   | Two common cathode 4-Digits seven segment LED display|
| HLR3   |AVRJazz 28PIN development board from ermicro which is based on the AVR ATmega328P microcontroller|
| HLR4   | Display|
| HLR5   | Software used|

### Low Level Requirements
| Low Level Requirements      | Description |
| ----------- | ----------- |
| LLR1      | ATmega328     |
| LLR2   |  AVR ATmega328P 16-bit TIMER2||
| LLR3   | ADC peripheral|
| LLR4   |Atmel AVR ATmega328 and Maxim MAX7219 Datasheet|
| LLR5   | Resistor |
| LLR6  |  Capacitors |

