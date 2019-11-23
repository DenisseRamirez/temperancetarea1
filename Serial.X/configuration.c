#pragma config FOSC = INTOSCIO_EC // define el oscilador interno
#pragma config FCMEN = OFF //Cambia el oscilador externo en caso de que no funcione por uno interno automaticamente
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config MCLRE = ON      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config CPB = OFF
#pragma config CPD = OFF
#define XTAL_FREQ 8000000