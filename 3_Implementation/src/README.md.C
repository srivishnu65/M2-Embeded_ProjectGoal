the
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