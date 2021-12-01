#define F_CPU 16000000UL          // AVRJazz28PIN Board Used 16MHz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SPI_PORT PORTB
#define SPI_DDR  DDRB
#define SPI_CS   PB2

static volatile uint8_t hours,minutes,seconds,hdseconds;
static volatile uint8_t keystate;

void SPI_Write(uint8_t addr, uint8_t dataout)
{        
  // Enable CS Pin
  SPI_PORT &= ~(1<<SPI_CS);

  // Start Address transmission (MOSI)    
  SPDR = addr;

  // Wait for transmission complete
  while(!(SPSR & (1<<SPIF)));    

  // Start Data transmission (MOSI)
  SPDR = dataout;

  // Wait for transmission complete
  while(!(SPSR & (1<<SPIF)));

  // Disable CS Pin
  SPI_PORT |= (1<<SPI_CS);    
}

void disp_digit(uint8_t dindex,uint8_t number,uint8_t nmax) {
  uint8_t digit[2];      

  if (keystate == 2) return;  

  digit[0]=0;
  digit[1]=0;

  if (number <= nmax) {
    if (number < 10) {      
     digit[0] = number;
    } else {
     digit[1] = number / 10;
     digit[0] = number - (digit[1] * 10);
    }
  }      

  SPI_Write(dindex,digit[0] | 0x80); // Enable DP (Decimal Point)
  SPI_Write((dindex + 1),digit[1]);
}

ISR(TIMER1_COMPA_vect)
{
  // Increase the Hundred Seconds
  hdseconds++;            // Count-up Hundredth of Seconds
  disp_digit(1,hdseconds,99);
  if (hdseconds > 99) {      
    hdseconds=0;
    seconds++;            // Count-up Seconds
    disp_digit(3,seconds,59);
    if (seconds > 59) {
      seconds=0;
      minutes++;          // Count-up Minutes
      disp_digit(5,minutes,59);
      if (minutes > 59) {
        minutes=0;
     hours++;          // Count-up Hours
     disp_digit(7,hours,23);
     if (hours > 23) hours=0;
      }
    }
  }  
  TCNT1=0;                // Reset TIMER1 Counter
}

ISR(PCINT0_vect)
{        
  if (PINB & (1<<PB0)) {       // Check PB0 if is Pressed or Logical 0    
    if (keystate == 0) {
      TCNT1=0;    
      TIMSK1=(1<<OCIE1A);      // Enable Compare A Interrupt                
      keystate=1;
    } else {
    keystate++;
    if (keystate > 2) {
      keystate=1;
      disp_digit(1,hdseconds,99);
      disp_digit(3,seconds,59);
      disp_digit(5,minutes,59);
      disp_digit(7,hours,23);
    }          
    }        
  }
  PCIFR=(1<<PCIF0);                 // Clear Pin Change Interrupt Flag
}

uint8_t adc_map(uint8_t adc)
{
  return ((adc * 15) / 255);
}

int main(void)
{    
  uint8_t cnt,ADCRead;

  // Set the PORTD as Output:
  DDRD=0xFF;
  PORTD=0x00;

  // Initial 16-bit TIMER1
  // TCNT1 Counter Increment Period: 1 / (Fclk/8)
  //                         Period = 1 / (16000000/8) = 0.0000005 Seconds
  // For 10 millisecond: 20,000 x 0.0000005 = 0.01 Seconds    
  TCCR1A=0;                         // Normal Mode
  TCCR1B=(1<<CS11);                 // Use prescaler of 8
  TCNT1=0;                          // Start TIMER1 counter from 0

  OCR1A=20000;                      // The Hundredth Second    
  TIFR1=(1<<OCF1A);                 // Clear any pending Compare A Interrupt
  TIMSK1=0;                         // Disable Compare A Interrupt

  // Initial ATmega328P Pin Change Interrupt on PB0 (PCINT0)
  PCMSK0 |= (1<<PCINT0);              // Activate PCINT0 Pin Change Interrupt
  PCICR |= (1<<PCIE0);                 // Enable PCIE0 Pin Change Interrupt
  keystate=0;                       // Key State

  // Set ADCSRA Register on ATmega328P
  // ADEN=1 - Enable the ADC Peripheral
  // ADPS2=1, ADPS1=1, and ADPS0=1 we used prescale of 128
  ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
  ADCSRB = 0b00000000;          // Free Running Mode
  DIDR0  = 0b00000000;          // Use analog input for Channel 0 to 5

  // Set ADMUX Register on ATmega328P
  // Use External Voltage Reference, Left Adjust, and select the ADC channel 0
  ADMUX=0b01100000;

  // Initial the AVR ATMega328P SPI Peripheral
  // Set MOSI and SCK as output, others as input
  SPI_DDR = (1<<PB3)|(1<<PB5)|(1<<PB2);

  // Disable (RCK Low)
  SPI_PORT |= (1<<SPI_CS);

  // Enable SPI, Master, set clock rate fck/2 (maximum)
  SPCR = (1<<SPE)|(1<<MSTR);
  SPSR = (1<<SPI2X);

  // Set the MAX7219        
  SPI_Write(0x0C,0x01);        // Normal Operation
  SPI_Write(0x09,0xFF);        // Code B Decode for Digit 7 to 0
  SPI_Write(0x0B,0x07);        // Scan digit 7 to 0
  SPI_Write(0x0A,0x0F);        // Set Default Intensity to Max

  // Reset all Digit and set the Decimal Point
  for(cnt=1;cnt <= 8;cnt=cnt+2) {
    SPI_Write(cnt,0 | 0x80);
    SPI_Write(cnt + 1,0);
  }        

  sei();                           // Enable Global Interrupt               

  for(;;) {     
   // Start ADC conversion by setting ADSC on ADCSRA Register
   ADCSRA |= (1<<ADSC);

   // wait until conversion complete ADSC=0 -> Complete
   while (ADCSRA & (1<<ADSC));

   // Get the 8-bit ADC the Result 
   ADCRead=ADCH;

   // Set the MAX7219 Intensity
   SPI_Write(0x0A,adc_map(ADCRead));        

   // Put Some Delay Here
   _delay_ms(100);
  }            
  return 0;
}

/* EOF: SSegMAX7219.c */
