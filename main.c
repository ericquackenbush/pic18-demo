 #include <xc.h>

/* WDT operating mode → WDT Disabled */
#pragma config WDTE = OFF

#define _XTAL_FREQ 1000000 // Fosc frequency for _delay()
#define LED_DELAY 2000     // delay in ms

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

   /* setting pin RC0 and RC2 as output (LED) */
   TRISCbits.TRISC0 = 0;
   TRISCbits.TRISC2 = 0;

   /* main program loop */
   while(1)
   {
     /* turn on the LED (pin RC0 high) */
     LATCbits.LATC0 = 1;
     /* turn off the LED (pin RC2 low) */
     LATCbits.LATC2 = 0;

     __delay_ms(LED_DELAY);

     /* turn on the LED (pin RC0 low) */
     LATCbits.LATC0 = 0;
     /* turn off the LED (pin RC2 high) */
     LATCbits.LATC2 = 1;

     __delay_ms(LED_DELAY);
    }
 }