/* 
 * File:   serial.c
 * Author: saenz
 *
 * Created on November 16, 2019, 11:24 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>
#include "configuration.h"
#include "UART.h"
#include "serial.h"
#include "PWM.h"
#include "motor.h"

void main() {
    USART_Init(9600);
    while (1) {
        char Oupcode = USART_Rx();
        switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
            case 'F':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                Serial_DecodificacionX(coordenada_array, &CX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Motor_Movimiento(CX,CY);
                break;
            case 'S':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                Serial_DecodificacionX(coordenada_array, &CX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                break;
            case 'T':
                // LLamar a la funcion touch
                break;
            case 'H':
                // LLamar a la funcion Hold
                break;
            case 'R':
                // LLamar a la funcion retraer
                break;
            case 'O':
                // LLamar a la funcion setup aun por definir
                break;
        }
    }

}

void Serial_DecodificacionX(char string_coordenada[], int *pointerCX) {
    char coordenadaX[3]; //
    for (int i = 0; i < 3; i++) {
        coordenadaX[i] = string_coordenada[i];
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x

}

void Serial_DecodificacionY(char string_coordenada[], int *pointerCY) {
    char coordenadaY[3];
    for (int i = 0; i < 3; i++) {
        coordenadaY[i] = string_coordenada[4 + i];
    }
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
}