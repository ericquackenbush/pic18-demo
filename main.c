#include <xc.h>

/* WDT operating mode → WDT Disabled */
#pragma config WDTE = OFF

#define _XTAL_FREQ 1000000 // Fosc frequency for _delay()
#define LED_DELAY 50     // delay in ms

static void CLK_init(void);

static void CLK_init(void)
{   
    /* Set HFINTOSC as new oscillator source */
    OSCCON1bits.NOSC = 0b110;
    
    /* Set HFFRQ to 1 MHz */
    OSCFRQbits.HFFRQ = 0;
}

 void main(void)
 {
   CLK_init();

   /* setting all PORTC pins to output  */
   TRISC = 0x0;

   /* main program loop */
   while(1)
   {
      for (int i = 0; i < 8; i++) {
         /* turn on the next PORT C pin */
         LATC = 1 << i;

         __delay_ms(LED_DELAY);
      }

      for (int i = 7; i > 0; i--) {
         /* turn on the next PORT C pin */
         LATC = 1 << i;

         __delay_ms(LED_DELAY);
      }

    }
 }