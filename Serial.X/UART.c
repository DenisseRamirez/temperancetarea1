#include <xc.h>
#include <string.h>
#include <stdlib.h>
#include "configuration.h"
#include "UART.h"
char C[7]="000,000";
int CX;
int CY;
void USART_Init(long BAUD){
      OSCCON= 0x72;// Defines el valor del oscilador interno
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

void USART_Tx(char data){
    while(!PIR1bits.TXIF);
    TXREG = data;
}

char USART_Rx(){
    while(!PIR1bits.RCIF);
    return RCREG; 
}


void USART_SPrint(char Str[]){
    int Strindex = 0;
    while(Str[Strindex] != 0);
    USART_Tx(Str[Strindex]);
    Strindex++;
}

char* Coordenada (char lenght){
    char coordenadaX[3] = "000"; //
    char coordenadaY[3] = "000";
     for (int i = 0; i < lenght; i++) //funcion pa leer string
        {
            while (!RCIF);
            C[i] = RCREG;
            while (RCIF);
        }
    strncpy(coordenadaX, &C[0], 3);//Copia el valor de la coordenada x en otro arreglo, dejando solo los 3 numeros
    strncpy(coordenaday, &C[4], 3);//Copia el valor de la coordenada y en otro arreglo, dejando solo los 3 numeros
    CX = atoi(coordenadaX);//Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    CY = atoi(coordenaday);//Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
     return CX,CY;
}
