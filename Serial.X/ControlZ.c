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
    GPIO_RD4_SetLow(); //Puente H activado enable
   GPIO_RD5_SetLow(); //Inputs de puente H en sto
    GPIO_RD6_SetLow(); //Input puente 
    while (controlZ < 10) {
        LecturaFiltro = ADC_LecturaFiltro(50);
         ADC_ConvertirDistancia(LecturaFiltro);
        if (Referencia > Distancia) {
            error = Referencia - Distancia;
            GPIO_RD4_SetLow(); //Puente H activado
           GPIO_RD5_SetHigh(); //Inputs de puente H con direccion hacia arriba
            GPIO_RD6_SetLow(); //Input puente H
        } else if (Referencia < Distancia) {
              error = Referencia - Distancia;
            GPIO_RD5_SetLow(); //Inputs de puente H con direccion hacia abajo
            GPIO_RD6_SetHigh(); //Input puente H
        }  
        if (((fabs(error))>0) &&((fabs(error))<2)) {//Si la platamorma se encuentra en rangos favorables
            controlZ++;
        }
         __delay_ms(5);//Tiempo de control
         
    }
            GPIO_RD5_SetHigh(); //Inputs de puente H en stop Fuerte
            GPIO_RD6_SetLow(); //Input puente H
            __delay_ms(100);
            GPIO_RD5_SetLow(); //Inputs de puente H en stop 
            GPIO_RD6_SetLow(); //Input puente H
            GPIO_RD4_SetHigh(); //Puente H desactivado
          __delay_ms(50);
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