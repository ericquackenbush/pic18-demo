#include <xc.h>
#include <stdint.h>
#include <string.h>

/* WDT operating mode → WDT Disabled */
#pragma config WDTE = OFF

#define _XTAL_FREQ 1000000 // Fosc frequency for _delay()
#define LED_DELAY 500     // delay in ms

static void CLK_init(void);
static void EUSART2_init(void);
static void PPS_init(void);
static void PORT_init(void);
static void EUSART2_write(uint8_t txData);

static void CLK_init(void)
{   
    /* Set HFINTOSC as new oscillator source */
    OSCCON1bits.NOSC = 0b110;
    
    /* Set HFFRQ to 1 MHz */
    OSCFRQbits.HFFRQ = 0;
}

static void EUSART2_init(void)
{
    /* Transmit Enable */
    TX2STAbits.TXEN = 1;
    /* High Baud Rate Select */
    TX2STAbits.BRGH = 1;
    
    /* 16-bit Baud Rate Generator is used */
    BAUD2CONbits.BRG16 = 1;
    
    /* Baud rate 9600 */
    SP2BRGL = 25;
    SP2BRGH = 0;
    
    /* Serial Port Enable */
    RC2STAbits.SPEN = 1;
}

static void PPS_init(void) 
{
    /* RD0 is TX2 */
    RD0PPS = 0x0B;
}

static void PORT_init(void)
{
    /* Configure RD0 as output. */
    TRISDbits.TRISD0 = 0;
}

static void EUSART2_write(uint8_t txData)
{
    while(0 == PIR3bits.TX2IF)
    {
        ;
    }

    TX2REG = txData;
}


 void main(void)
 {
    char msg[] = "Hello world!\r\n";

    CLK_init();
    EUSART2_init();  
    PPS_init();   
    PORT_init();

    /* setting all PORTC pins to output  */
    TRISC = 0x0;

    /* main program loop */
    while(1)
    {
        for(uint8_t i = 0; i < strlen(msg); i++) 
        {
            EUSART2_write(msg[i]);
            LATC = msg[i];
            __delay_ms(LED_DELAY);
        }

    }
 }