
#ifndef GPIOSPARCA1_H
#define	GPIOSPARCA1_H

#include <xc.h>
#include <stdint.h>

void GPIO_init_PORTB(void);  //Check function to see pin assignment

#define GPIO_RB0_TRIS                 TRISBbits.TRISB0 
#define GPIO_RB0_LAT                  LATBbits.LATB0
#define GPIO_RB0_PORT                 PORTBbits.RB0
#define GPIO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define GPIO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define GPIO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define GPIO_RB0_GetValue()           PORTBbits.RB0
#define GPIO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define GPIO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0) 

#define GPIO_RB1_TRIS                 TRISBbits.TRISB1 
#define GPIO_RB1_LAT                  LATBbits.LATB1
#define GPIO_RB1_PORT                 PORTBbits.RB1
#define GPIO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define GPIO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define GPIO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define GPIO_RB1_GetValue()           PORTBbits.RB1
#define GPIO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define GPIO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0) 

#define GPIO_RB2_TRIS                 TRISBbits.TRISB2 
#define GPIO_RB2_LAT                  LATBbits.LATB2
#define GPIO_RB2_PORT                 PORTBbits.RB2
#define GPIO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define GPIO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define GPIO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define GPIO_RB2_GetValue()           PORTBbits.RB2
#define GPIO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define GPIO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0) 

#define GPIO_RB5_TRIS                 TRISBbits.TRISB5 
#define GPIO_RB5_LAT                  LATBbits.LATB5
#define GPIO_RB5_PORT                 PORTBbits.RB5
#define GPIO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define GPIO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define GPIO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define GPIO_RB5_GetValue()           PORTBbits.RB5
#define GPIO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define GPIO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0) 

#define GPIO_RB6_TRIS                 TRISBbits.TRISB6 
#define GPIO_RB6_LAT                  LATBbits.LATB6
#define GPIO_RB6_PORT                 PORTBbits.RB6
#define GPIO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define GPIO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define GPIO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define GPIO_RB6_GetValue()           PORTBbits.RB6
#define GPIO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define GPIO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0) 

#define GPIO_RB7_TRIS                 TRISBbits.TRISB7 
#define GPIO_RB7_LAT                  LATBbits.LATB7
#define GPIO_RB7_PORT                 PORTBbits.RB7
#define GPIO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define GPIO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define GPIO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define GPIO_RB7_GetValue()           PORTBbits.RB7
#define GPIO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define GPIO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0) 

void GPIO_init_PORTC(void);  //Check function to see pin assignment

#define GPIO_RC0_TRIS                 TRISCbits.TRISC0 
#define GPIO_RC0_LAT                  LATCbits.LATC0
#define GPIO_RC0_PORT                 PORTCbits.RC0
#define GPIO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define GPIO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define GPIO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define GPIO_RC0_GetValue()           PORTCbits.RC0
#define GPIO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define GPIO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0) 

#define GPIO_RC1_TRIS                 TRISCbits.TRISC1 
#define GPIO_RC1_LAT                  LATCbits.LATC1
#define GPIO_RC1_PORT                 PORTCbits.RC1
#define GPIO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define GPIO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define GPIO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define GPIO_RC1_GetValue()           PORTCbits.RC1
#define GPIO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define GPIO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0) 

#define GPIO_RC2_TRIS                 TRISCbits.TRISC2 
#define GPIO_RC2_LAT                  LATCbits.LATC2
#define GPIO_RC2_PORT                 PORTCbits.RC2
#define GPIO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define GPIO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define GPIO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define GPIO_RC2_GetValue()           PORTCbits.RC2
#define GPIO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define GPIO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0) 

//RC3 is unavailable

//RC4 is only used as input

#define GPIO_RC4_PORT                 PORTCbits.RC4
#define GPIO_RC4_GetValue()           PORTCbits.RC4

//RC5 is only used as input

#define GPIO_RC5_PORT                 PORTCbits.RC5
#define GPIO_RC5_GetValue()           PORTCbits.RC5

#define GPIO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define GPIO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define GPIO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define GPIO_RC6_GetValue()           PORTCbits.RC6
#define GPIO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define GPIO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define GPIO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define GPIO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

#define GPIO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define GPIO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define GPIO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define GPIO_RC7_GetValue()           PORTCbits.RC7
#define GPIO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define GPIO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define GPIO_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define GPIO_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

void GPIO_init_PORTD(void);  //Check function to see pin assignment

#define GPIO_RD0_TRIS                 TRISDbits.TRISD0 
#define GPIO_RD0_LAT                  LATDbits.LATD0
#define GPIO_RD0_PORT                 PORTDbits.RD0
#define GPIO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define GPIO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define GPIO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define GPIO_RD0_GetValue()           PORTDbits.RD0
#define GPIO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define GPIO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0) 

#define GPIO_RD1_TRIS                 TRISDbits.TRISD1 
#define GPIO_RD1_LAT                  LATDbits.LATD1
#define GPIO_RD1_PORT                 PORTDbits.RD1
#define GPIO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define GPIO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define GPIO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define GPIO_RD1_GetValue()           PORTDbits.RD1
#define GPIO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define GPIO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

#define GPIO_RD2_TRIS                 TRISDbits.TRISD2 
#define GPIO_RD2_LAT                  LATDbits.LATD2
#define GPIO_RD2_PORT                 PORTDbits.RD2
#define GPIO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define GPIO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define GPIO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define GPIO_RD2_GetValue()           PORTDbits.RD2
#define GPIO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define GPIO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

#define GPIO_RD3_TRIS                 TRISDbits.TRISD3 
#define GPIO_RD3_LAT                  LATDbits.LATD3
#define GPIO_RD3_PORT                 PORTDbits.RD3
#define GPIO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define GPIO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define GPIO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define GPIO_RD3_GetValue()           PORTDbits.RD3
#define GPIO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define GPIO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

#define GPIO_RD4_TRIS                 TRISDbits.TRISD4 
#define GPIO_RD4_LAT                  LATDbits.LATD4
#define GPIO_RD4_PORT                 PORTDbits.RD4
#define GPIO_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define GPIO_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define GPIO_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define GPIO_RD4_GetValue()           PORTDbits.RD4
#define GPIO_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define GPIO_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

#define GPIO_RD5_TRIS                 TRISDbits.TRISD5 
#define GPIO_RD5_LAT                  LATDbits.LATD5
#define GPIO_RD5_PORT                 PORTDbits.RD5
#define GPIO_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define GPIO_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define GPIO_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define GPIO_RD5_GetValue()           PORTDbits.RD5
#define GPIO_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define GPIO_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

#define GPIO_RD6_TRIS                 TRISDbits.TRISD6 
#define GPIO_RD6_LAT                  LATDbits.LATD6
#define GPIO_RD6_PORT                 PORTDbits.RD6
#define GPIO_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define GPIO_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define GPIO_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define GPIO_RD6_GetValue()           PORTDbits.RD6
#define GPIO_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define GPIO_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

#define GPIO_RD7_TRIS                 TRISDbits.TRISD7 
#define GPIO_RD7_LAT                  LATDbits.LATD7
#define GPIO_RD7_PORT                 PORTDbits.RD7
#define GPIO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define GPIO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define GPIO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define GPIO_RD7_GetValue()           PORTDbits.RD7
#define GPIO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define GPIO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

#endif	/* GPIOSPARCA1_H */

