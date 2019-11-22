/* 
 * File:   ADC.c
 * Author: saenz
 *
 * Created on November 22, 2019, 12:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

//1/8Mhz= .125us
//8Tosc= 1us=TAD
//2.45us<xTAD  
//X=4 4us
void ADC_Init(){
    TRISAbits.RA0=1;//RA0 COMO ENTRADA
     TRISAbits.RA1=1;//RA0 COMO ENTRADA
    ADCON1bits.PCFG=0xD;//Puerto RA0 Y RA1 COMO ANALOGICO A0/A1
    ADCON1bits.VCFG=0;// VREF VSS/VDD
    ADCON0=0;// A0 SELECCIONADO Y CONERTIDOR APAGADO
    ADCON2bits.ACQT=0x2;//TADQ =X DE 4
    ADCON2bits.ADCS=0x1;//8TOSC
    ADCON2bits.ADFM=1;// JUSTIFICADO DERECHA
    while(1){
        ADCON0bits.GO_DONE==1;
        while(ADCON0bits.GO_DONE==1);
        //ADRESL
        //ADRESH
    }
}


