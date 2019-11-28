/* 
 * File:   ADC.c
 * Author: saenz
 *
 * Created on November 22, 2019, 12:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>
#include <math.h>
#include "ADC.h"

//1/8Mhz= .125us
//8Tosc= 1us=TAD
//2.45us<xTAD  
//X=4 4us


void ADC_ConvertirDistancia(int Volts) {
    Distancia = 3143 * pow(Volts, -1.0610) + .3;
}

int ADC_InsertBits(char Bmenos, char Bmas) {
    Bmas &= ~(0xC); //PONE EN 0 LOS 6 BITS MAS SIGNIFICATIVOS 
    Lectura = Bmenos; // AGREGA LOS BITS MENOS SIGNIFICATIVOS A LA VARIABLE
    Lectura &= ~(0xFFFFFF << 8); // LIMPIA LOS 6 BYTES MAS SIGNIFICATIVOS PARA POSTERIOR ESCRITURA
    Lectura |= ((Bmas & 0x3) << 8); //Agrega los 2 bits mas significativos
    return Lectura;
}

int ADC_LecturaFiltro(int n) {
    int lectura = 0;
    Suma=0;
    ADCON0bits.GO_DONE = 1; //Inicia la COnversió AD.
    for (int i = 0; i < n; i++) {
       while (ADCON0bits.GO_DONE); 
            bites_menosS = ADRESL; //Guardas los 8 bits menos significativos de la lectura
            bites_masS = ADRESH; //Guardas los 2 bits mas significativos de la lectura
        lectura = ADC_InsertBits(bites_menosS, bites_masS);
        Suma = Suma + lectura;
    }
    return (Suma / n);
}
void ADC_Init() {  
    TRISAbits.RA0=1;//RA0 COMO ENTRADA
    ADCON1bits.PCFG = 0b1110; //  Configura el Puerto como Entrada Analógica.
    ADCON1bits.VCFG = 0b00; //  Selecciona Voltajes de Referencia (5v-0v).
    ADCON0bits.CHS = 0b0000; //  Selecciona el Canal Analógico.
   ADCON2bits.ACQT = 4; //TADQ =X DE 8
    ADCON2bits.ADCS = 4; //4TOSC
    ADCON2bits.ADFM = 1; //  Justificación derecha (modo-10bits).
    ADCON0bits.ADON = 1; //  Habilita el Módulo AD.
}
  /* while (ADCON0bits.GO_DONE); //  Espera a que termine la conversión AD.
            value_adc = ADRESH; //  Lectura de valor AD.
            value_adc = (value_adc & 0x03); 
            value_adc = (value_adc << 8) + ADRESL;
            adcre1 = (value_adc*0.249266862);
            adcsend = adcre1;*/

