#include <xc.h>
#include <string.h>
#include <stdlib.h>
#include "configuration.h"
#include "UART.h"
void USART_Init(long BAUD){  
    TRISCbits.RC6 = 0;      
    TRISCbits.RC7 = 1;      
    

    SPBRG = (unsigned char)(((8000000/BAUD)/64)-1);//define el valor del baudaje

    TXSTAbits.BRGH = 0;     
    TXSTAbits.SYNC = 0;     
    RCSTAbits.SPEN = 1;     
    
    TXSTAbits.TX9 = 0;   
    TXSTAbits.TXEN = 1;     
    
    RCSTAbits.RC9 = 0;    
    RCSTAbits.CREN = 1;     
}

void USART_TxC(char data){
    while(!PIR1bits.TXIF);
    TXREG = data;
}

char USART_RxC(){
    while(!PIR1bits.RCIF);
    return RCREG; 
}
char USART_TxS(char str[]){
    for (int i=0;i<=(sizeof(str));i++){
    while(!PIR1bits.TXIF)   
    TXREG = str[i];
    }
}

void USART_TxSP(char Str[]){
    int Strindex = 0;
    while(Str[Strindex] != 0);
    USART_TxC(Str[Strindex]);
    Strindex++;
}

void USART_RxS (char length, char* pointer ){//funcion pa leer string
    for (int i = 0; i < length; i++) 
        {
            while (!RCIF);
            pointer[i] = RCREG;
        }
}
