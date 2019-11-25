/* 
 * File:   EEPROM.c
 * Author: saenz
 *
 * Created on November 23, 2019, 7:20 PM
 */

#include <xc.h>
#include "EEPROM.h"

void EEPROM_Init(){
    EECON1bits.CFGS=0;
    EECON1bits.EEPGD=0;//SELECCIONAR DATA EEPROM
    EECON1bits.WREN=1;//PERMITIR WRITE OPERATION
}
char EEPROM_Rx(char direccion){
    EEADR=direccion;//DIRECCION A LEER
    EECON1bits.EEPGD=0;//SELECCIONAR DATA EEPROM
      EECON1bits.CFGS=0;// //DATA EEPROM
      EECON1bits.RD=1;// HABILITAR LECTURA
      data=EEDATA;//LEER DATO Y GUARDARLO EN VARIABLE
      return data;
}
void EEPROM_Tx(char direccion, char dato){
    EEADR=direccion;//DIRECCION A ESCRIBIR
    EEDATA=data;//DATO A GUARDAR
     EECON1bits.EEPGD=0;//SELECCIONAR DATA EEPROM
      EECON1bits.CFGS=0;// //DATA EEPROM
      EECON1bits.WREN=1;// ENABLE WRITES
      INTCONbits.GIE=0;//DISABLE INTERRUPTS
      //PASOS NECESARIOS POR LA DATASHEET PARA ESCRIBIR
      EECON2=0x55;
      EECON2=0x0AA;
      EECON1bits.WR=1;//ENABLE WRITE
      INTCONbits.GIE=1;//ENABLE INTERRUPTS
      EECON1bits.WREN=0 ;// DISABLE WRITES
      
      //APAGAR BANDERA EEIF
}



//void Write(char direccion, char coordenadaX[], char coordenadaY[], char coordenadaY[]){