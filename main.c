 #include <xc.h>

 void main(void)
 {
    /* setting pin RE0 as output (LED) */
    TRISEbits.TRISE0 = 0;
    /* setting pin RE2 as input (button) */
    TRISEbits.TRISE2 = 1;
    /* enable digital input buffer for pin RE2 (button) */
    ANSELEbits.ANSELE2 = 0;
    /* enable internal pull-up for pin RE2 (button) */
    WPUEbits.WPUE2 = 1;
    
    /* main program loop */
    while(1)
    {
        /* if button is pressed (pin RE2 high) */
        if(PORTEbits.RE2)
        {
            /* turn on the LED (pin RE0 high) */
            LATEbits.LATE0 = 1;
        }
        else
        {
            /* turn off the LED (pin RE0 low) */
            LATEbits.LATE0 = 0;
        }
    }
 }