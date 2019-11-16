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


/*
 * 
 */
void main() {
    USART_Init(9600);
    char Oupcode = 'N';
    switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
        case 'F':
            C = Coordenada(7); // LLamar a serial de decodificacion Coordenada, 7 digitos recibira
            //Decodificacion de coordenadas
            decodificacion(C); //Decodificacion de coordenadaS
            break;
        case 'S':
            C = Coordenada(7); // LLamar a serial de decodificacion Coordenada, 7 digitos recibira          
            decodificacion(C); //Decodificacion de coordenadas
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

int decodificacion(char coordenada[]) {
    char coordenadaX[3] = "000"; //
    char coordenadaY[3] = "000";
    strncpy(coordenadaX, &coordenada[0], 3);//Copia el valor de la coordenada x en otro arreglo, dejando solo los 3 numeros
    strncpy(coordenaday, &coordenada[4], 3);//Copia el valor de la coordenada y en otro arreglo, dejando solo los 3 numeros
    CX = atoi(coordenadaX);//Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    CY = atoi(coordenaday);//Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return(CX,CY);
}

