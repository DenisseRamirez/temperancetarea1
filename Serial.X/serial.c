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

int CX;//Coordenada en x, global ya que sera usada en varias funciones
int CY;//Cooordenada en y
 
void main() {
    USART_Init(9600);
    char Oupcode = 'N';
    switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
        case 'F':
            Coordenada(7,&CX,&CY); // LLamar a serial de decodificacion Coordenada, 7 digitos recibira, LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
            break;
        case 'S':
             Coordenada(7,&CX,&CY); // LLamar a serial de decodificacion Coordenada, 7 digitos recibira,LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES       
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
    //Decodificacion de coordenadas
}

