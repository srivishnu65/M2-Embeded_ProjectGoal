/ Initial 16-bit TIMER1
// TCNT1 Counter Increment Period: 1 / (Fclk/8)
// Period = 1 / (16000000/8) = 0.0000005 Seconds
// For 10 millisecond: 20,000 x 0.0000005 = 0.01 Seconds
TCCR1A=0; // Normal Mode
TCCR1B=(1<<CS11); // Use prescaler of 8
TCNT1=0; // Start TIMER1 counter from 0 
OCR1A=20000; // The Hundredth Second

TIFR1=(1<<OCF1A); // Clear any pending Compare A Interrupt
TIMSK1=0; // Disable Compare A Interrupt