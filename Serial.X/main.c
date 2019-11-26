/* 
 * File:   main.c
 * Author: saenz
 *
 * Created on November 25, 2019, 11:05 PM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void maain_interrrupt(){
  OSCCON= 0x72;
  Int_Ext();
    while(1){
        if ((cont%2)==1){
            PORTDbits.RD0=1;
        }else {
        PORTDbits.RD0=0;}
    }
  return;
}
void Int_Ext(){
     TRISD=0;
    TRISBbits.RB2=1;  
    RCONbits.IPEN=1;
   // INTCONbits.PEIE=1;
     INTCONbits.GIE=1;//Habilitar INTERRUPCIONES GLOBALES
   //  INTCONbits.GIEH=1;//Habilitar INTERRUPCIONES GLOBALES
    INTCON3bits.INT2P=1;
     INTCON2bits.INTEDG2=0;// INTERRUPT RISING EDGE  RCONbits.IPEN=1;
     INTCON3bits.INT2IF=0;//FLAG INT0 APAGADA
      INTCON3bits.INT2IE=1;//Habilitar INT0
      return;
}
void __interrupt() INT_isr (void){
    PORTDbits.RD1=1;
    if (PORTBbits.RB2==0){
            Oneshot();
        INTCON3bits.INT2IF=0;
    }
    oneshot=0;
    PORTDbits.RD1=0;
    INTCON3bits.INT2IF=0;
    return;
}

void Oneshot() {
    if (PORTBbits.RB2 == 0 & oneshot == 0) {
        cont++;
        oneshot = 1;
    }
}

