/* 
 * File:   ControlZ.c
 * Author: saenz
 *
 * Created on November 24, 2019, 10:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ADC.h"
#include "ControlZ.h"
#include <xc.h>
#include "configuration.h"
#include "math.h"
#include "GPIOsparcA1.h"
#include "UART.h"

/*
 * 
 */
void Control_Z (int Referencia){
    USART_TxS("W\n", sizeof ("W\n") - 1);
     ADC_Init();
     Referencia=Referencia+47;
     controlZ=0;
    ENABLE_Z_SetLow(); //Puente H activado enable
   INPUT_A_SetLow(); //Inputs de puente H en sto
    INPUT_B_SetLow(); //Input puente 
    while (controlZ < 10) {
        LecturaFiltro = Control_LecturaFiltro(50);
         Control_ConvertirDistancia(LecturaFiltro);
        if (Referencia > Distancia) {
            error = Referencia - Distancia;
            ENABLE_Z_SetLow(); //Puente H activado
           INPUT_A_SetHigh(); //Inputs de puente H con direccion hacia arriba
            INPUT_B_SetLow(); //Input puente H
        } else if (Referencia < Distancia) {
              error = Referencia - Distancia;
            INPUT_A_SetLow(); //Inputs de puente H con direccion hacia abajo
            INPUT_B_SetHigh(); //Input puente H
        }  
        if (((fabs(error))>0) &&((fabs(error))<2)) {//Si la platamorma se encuentra en rangos favorables
            controlZ++;
        }
         __delay_ms(5);//Tiempo de control
         
    }
            INPUT_A_SetHigh(); //Inputs de puente H en stop Fuerte
            INPUT_B_SetLow(); //Input puente H
            __delay_ms(100);
            INPUT_A_SetLow(); //Inputs de puente H en stop 
            INPUT_B_SetLow(); //Input puente H
            ENABLE_Z_SetHigh(); //Puente H desactivado
          __delay_ms(50);
}



void Control_ConvertirDistancia(int Volts) {
    Distancia = 3143 * pow(Volts, -1.0610) + .3;
    Distancia = Distancia * 10; // COnvertir cm a mm
}

int Control_InsertBits(char Bmenos, char Bmas) {
    Bmas &= ~(0xC); //PONE EN 0 LOS 6 BITS MAS SIGNIFICATIVOS 
    Lectura = Bmenos; // AGREGA LOS BITS MENOS SIGNIFICATIVOS A LA VARIABLE
    Lectura &= ~(0xFFFFFF << 8); // LIMPIA LOS 6 BYTES MAS SIGNIFICATIVOS PARA POSTERIOR ESCRITURA
    Lectura |= ((Bmas & 0x3) << 8); //Agrega los 2 bits mas significativos
    return Lectura;
}

int Control_LecturaFiltro(int n) {
    int lectura = 0;
    Suma = 0;
    for (int i = 0; i < n; i++) {
        ADC_Lectura();
        lectura = Control_InsertBits(bites_menosS, bites_masS);
        Suma = Suma + lectura;
    }
    return (Suma / n);
}
/*Referencia = 150
Sensor = read_ADC()
Error = Sensor - Referencia
Proporcional = Error * Kp
Integral = Integral + Error * Ki * T
Derivativo = (Error - Error_0) * Kd / T
Error_0 = Error
Control = Proporcional + Integral + Derivativo
write_DAC(Control)
*/