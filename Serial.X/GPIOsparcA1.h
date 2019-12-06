
#ifndef GPIOSPARCA1_H
#define	GPIOSPARCA1_H

#include <xc.h>
#include <stdint.h>

void GPIO_init_PORTA(void); //Check function to see pin assignment

#define SENSOR_READ_TRIS                 TRISAbits.TRISA0 
#define SENSOR_READ_LAT                  LATAbits.LATA0
#define SENSOR_READ                      PORTAbits.RA0
#define GPIO_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define GPIO_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define GPIO_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define GPIO_RA0_GetValue()           PORTAbits.RA0
#define GPIO_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define GPIO_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0) 

#define GPIO_RA1_TRIS                 TRISAbits.TRISA1 
#define GPIO_RA1_LAT                  LATAbits.LATA1
#define GPIO_RA1_PORT                 PORTAbits.RA1
#define GPIO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define GPIO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define GPIO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define GPIO_RA1_GetValue()           PORTAbits.RA1
#define GPIO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define GPIO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0) 

#define GPIO_RA2_TRIS                 TRISAbits.TRISA2 
#define GPIO_RA2_LAT                  LATAbits.LATA2
#define GPIO_RA2_PORT                 PORTAbits.RA2
#define GPIO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define GPIO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define GPIO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define GPIO_RA2_GetValue()           PORTAbits.RA2
#define GPIO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define GPIO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0) 

#define GPIO_RA3_TRIS                 TRISAbits.TRISA3 
#define GPIO_RA3_LAT                  LATAbits.LATA3
#define GPIO_RA3_PORT                 PORTAbits.RA3
#define GPIO_RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define GPIO_RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define GPIO_RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define GPIO_RA3_GetValue()           PORTAbits.RA3
#define GPIO_RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define GPIO_RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0) 

#define GPIO_RA4_TRIS                 TRISAbits.TRISA4 
#define GPIO_RA4_LAT                  LATAbits.LATA4
#define GPIO_RA4_PORT                 PORTAbits.RA4
#define GPIO_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define GPIO_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define GPIO_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define GPIO_RA4_GetValue()           PORTAbits.RA4
#define GPIO_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define GPIO_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0) 

#define BOTON_OK_TRIS                 TRISAbits.TRISA5 
#define BOTON_OK_LAT                  LATAbits.LATA5
#define BOTON_OK                 PORTAbits.RA5
#define BOTON_OK_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define BOTON_OK_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define BOTON_OK_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define BOTON_OK_GetValue()           PORTAbits.RA5
#define BOTON_OK_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define BOTON_OK_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0) 

#define GPIO_RA6_TRIS                 TRISAbits.TRISA6 
#define GPIO_RA6_LAT                  LATAbits.LATA6
#define GPIO_RA6_PORT                 PORTAbits.RA6
#define GPIO_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define GPIO_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define GPIO_RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define GPIO_RA6_GetValue()           PORTAbits.RA6
#define GPIO_RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define GPIO_RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0) 

void GPIO_init_PORTB(void); //Check function to see pin assignment

#define SWITCH_OR_TRIS                 TRISBbits.TRISB0 
#define SWITCH_OR_LAT                  LATBbits.LATB0
#define SWITCH_OR                 PORTBbits.RB0
#define SWITCH_OR_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SWITCH_OR_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SWITCH_OR_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SWITCH_OR_GetValue()           PORTBbits.RB0
#define SWITCH_OR_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SWITCH_OR_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0) 

#define HOME_X_TRIS                 TRISBbits.TRISB1 
#define HOME_X_LAT                  LATBbits.LATB1
#define HOME_X                 PORTBbits.RB1
#define HOME_X_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define HOME_X_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define HOME_X_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define HOME_X_GetValue()           PORTBbits.RB1
#define HOME_X_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define HOME_X_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0) 

#define HOME_Y_TRIS                 TRISBbits.TRISB2 
#define HOME_Y_LAT                  LATBbits.LATB2
#define HOME_Y                 PORTBbits.RB2
#define HOME_Y_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define HOME_Y_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define HOME_Y_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define HOME_Y_GetValue()           PORTBbits.RB2
#define HOME_Y_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define HOME_Y_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0) 

#define LED_R_TRIS                 TRISBbits.TRISB5 
#define LED_R_LAT                  LATBbits.LATB5
#define LED_R                 PORTBbits.RB5
#define LED_R_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LED_R_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LED_R_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LED_R_GetValue()           PORTBbits.RB5
#define LED_R_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LED_R_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0) 

#define LED_G_TRIS                 TRISBbits.TRISB6 
#define LED_G_LAT                  LATBbits.LATB6
#define LED_G                 PORTBbits.RB6
#define LED_G_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LED_G_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LED_G_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LED_G_GetValue()           PORTBbits.RB6
#define LED_G_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LED_G_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0) 

#define LED_B_TRIS                 TRISBbits.TRISB7 
#define LED_B_LAT                  LATBbits.LATB7
#define LED_B_PORT                 PORTBbits.RB7
#define LED_B_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define LED_B_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define LED_B_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define LED_B_GetValue()           PORTBbits.RB7
#define LED_B_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define LED_B_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0) 

void GPIO_init_PORTC(void); //Check function to see pin assignment

#define GPIO_RC0_TRIS                 TRISCbits.TRISC0 
#define GPIO_RC0_LAT                  LATCbits.LATC0
#define GPIO_RC0_PORT                 PORTCbits.RC0
#define GPIO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define GPIO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define GPIO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define GPIO_RC0_GetValue()           PORTCbits.RC0
#define GPIO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define GPIO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0) 

#define STEP_X_TRIS                 TRISCbits.TRISC1 
#define STEP_X_LAT                  LATCbits.LATC1
#define STEP_X                 PORTCbits.RC1
#define STEP_X_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define STEP_X_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define STEP_X_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define STEP_X_GetValue()           PORTCbits.RC1
#define STEP_X_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define STEP_X_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0) 

#define STEP_Y_TRIS                 TRISCbits.TRISC2 
#define STEP_Y_LAT                  LATCbits.LATC2
#define STEP_Y                 PORTCbits.RC2
#define STEP_Y_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define STEP_Y_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define STEP_Y_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define STEP_Y_GetValue()           PORTCbits.RC2
#define STEP_Y_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define STEP_Y_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0) 

//RC3 is unavailable

//RC4 is only used as input

#define BOTON_UP                 PORTCbits.RC4
#define BOTON_UP_GetValue()           PORTCbits.RC4

//RC5 is only used as input

#define BOTON_DOWN                 PORTCbits.RC5
#define BOTON_DOWN_GetValue()           PORTCbits.RC5

#define TX_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define TX_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define TX_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define TX_GetValue()           PORTCbits.RC6
#define TX_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define TX_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

#define RX_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RX_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RX_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RX_GetValue()           PORTCbits.RC7
#define RX_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RX_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

void GPIO_init_PORTD(void); //Check function to see pin assignment

#define ENABLE_X_TRIS                 TRISDbits.TRISD0 
#define ENABLE_X_LAT                  LATDbits.LATD0
#define ENABLE_X                 PORTDbits.RD0
#define ENABLE_X_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define ENABLE_X_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define ENABLE_X_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define ENABLE_X_GetValue()           PORTDbits.RD0
#define ENABLE_X_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define ENABLE_X_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0) 

#define DIRECCION_X_TRIS                 TRISDbits.TRISD1 
#define DIRECCION_X_LAT                  LATDbits.LATD1
#define DIRECCION_X                 PORTDbits.RD1
#define DIRECCION_X_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define DIRECCION_X_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define DIRECCION_X_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define DIRECCION_X_GetValue()           PORTDbits.RD1
#define DIRECCION_X_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define DIRECCION_X_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

#define ENABLE_Y_TRIS                 TRISDbits.TRISD2 
#define ENABLE_Y_LAT                  LATDbits.LATD2
#define ENABLE_Y                 PORTDbits.RD2
#define ENABLE_Y_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define ENABLE_Y_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define ENABLE_Y_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define ENABLE_Y_GetValue()           PORTDbits.RD2
#define ENABLE_Y_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define ENABLE_Y_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

#define DIRECCION_Y_TRIS                 TRISDbits.TRISD3 
#define DIRECCION_YLAT                  LATDbits.LATD3
#define DIRECCION_Y                 PORTDbits.RD3
#define DIRECCION_Y_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define DIRECCION_Y_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define DIRECCION_Y_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define DIRECCION_Y_GetValue()           PORTDbits.RD3
#define DIRECCION_Y_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define DIRECCION_Y_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

#define ENABLE_Z_TRIS                 TRISDbits.TRISD4 
#define ENABLE_Z_LAT                  LATDbits.LATD4
#define ENABLE_Z                 PORTDbits.RD4
#define ENABLE_Z_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define ENABLE_Z_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define ENABLE_Z_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define ENABLE_Z_GetValue()           PORTDbits.RD4
#define ENABLE_Z_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define ENABLE_Z_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

#define INPUT_A_TRIS                 TRISDbits.TRISD5 
#define INPUT_A_LAT                  LATDbits.LATD5
#define INPUT_A                 PORTDbits.RD5
#define INPUT_A_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define INPUT_A_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define INPUT_A_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define INPUT_A_GetValue()           PORTDbits.RD5
#define INPUT_A_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define INPUT_A_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

#define INPUT_B_TRIS                 TRISDbits.TRISD6 
#define INPUT_B_LAT                  LATDbits.LATD6
#define INPUT_B                 PORTDbits.RD6
#define INPUT_B_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define INPUT_B_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define INPUT_B_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define INPUT_B_GetValue()           PORTDbits.RD6
#define INPUT_B_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define INPUT_B_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

#define GPIO_RD7_TRIS                 TRISDbits.TRISD7 
#define GPIO_RD7_LAT                  LATDbits.LATD7
#define GPIO_RD7_PORT                 PORTDbits.RD7
#define GPIO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define GPIO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define GPIO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define GPIO_RD7_GetValue()           PORTDbits.RD7
#define GPIO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define GPIO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

void GPIO_init_PORTE(void); //Check function to see pin assignment

#define ACTUADOR_TRIS                 TRISEbits.TRISE0 
#define ACTUADOR_LAT                  LATEbits.LATE0
#define ACTUADOR                 PORTEbits.RE0
#define ACTUADOR_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define ACTUADOR_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define ACTUADOR_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define ACTUADOR_GetValue()           PORTEbits.RE0
#define ACTUADOR_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define ACTUADOR_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0) 

#define GPIO_RE1_TRIS                 TRISEbits.TRISE1 
#define GPIO_RE1_LAT                  LATEbits.LATE1
#define GPIO_RE1_PORT                 PORTEbits.RE1
#define GPIO_RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define GPIO_RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define GPIO_RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define GPIO_RE1_GetValue()           PORTEbits.RE1
#define GPIO_RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define GPIO_RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0) 

#define GPIO_RE2_TRIS                 TRISEbits.TRISE2 
#define GPIO_RE2_LAT                  LATEbits.LATE2
#define GPIO_RE2_PORT                 PORTEbits.RE2
#define GPIO_RE2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define GPIO_RE2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define GPIO_RE2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define GPIO_RE2_GetValue()           PORTEbits.RE2
#define GPIO_RE2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define GPIO_RE2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0) 


#endif	/* GPIOSPARCA1_H */

