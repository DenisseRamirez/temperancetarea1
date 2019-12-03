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
#include <pic18f4550.h>
#include "configuration.h"
#include "UART.h"
#include "serial.h"
#include "PWM.h"
#include "motor.h"
#include "Actuator.h"
#include "EEPROM.h"
#include "GPIOsparcA1.h"

void Serial_Oupcode() {
    //OSCCON = 0x72; // Defines el valor del oscilador interno
    GPIO_RD0_TRIS = 0;
    GPIO_RD2_TRIS = 0;
    GPIO_RD1_TRIS = 0;
    GPIO_RD3_TRIS = 0;
    Enable_DriverX = 1;
    Enable_DriverX = 1;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    PORTCbits.RC1 = 0;
    char instruction_counter = 0;
    USART_TxS("PLEASE INSERT THE INSTRUCTION OF SETPOINT\n", sizeof ("PLEASE INSERT THE INSTRUCTION OF SETPOINT\n") - 1);
    while (1) {
        if (instruction_counter == 0) {
            USART_TxS("WAITING FOR INSTRUCTION\n", sizeof ("WAITING FOR INSTRUCTION\n") - 1);
            instruction_counter = 1;
        }
        char Oupcode = USART_RxC(); //Variable que indica la instruccion
        switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
            case 'F'://Movimiento a coordenada rapido 
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE...") - 1);
                Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_RangosCoordenadas(CoordenadaX);
                Serial_RangosCoordenadas(CoordenadaY);
                if (Coordenadas_fuera == 1 ) {//En caso de Coordenada ingresada fuera del rango no comenzar
                     USART_TxS("ERROR CORDINATES OUTSIDE THE RANGE\n", sizeof ("ERROR CORDINATES OUTSIDE THE RANGE\n") - 1);
                    Coordenadas_fuera = 0;
                }else if (Coordenadas_mal==1){
                    USART_TxS("ERROR CARACTERS INGRESED WRONG\n", sizeof ("ERROR CARACTERS INGRESED WRONG\n") - 1);
                    Coordenadas_mal=0;
                } else {
                    Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                }
                break;
            case 'S':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE...") - 1);
                Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_RangosCoordenadas(CoordenadaX); //Checar las coordenadas
                Serial_RangosCoordenadas(CoordenadaY); //Checar las coordenadas
               if (Coordenadas_fuera == 1 ) {//En caso de Coordenada ingresada fuera del rango no comenzar
                     USART_TxS("ERROR CORDINATES OUTSIDE THE RANGE\n", sizeof ("ERROR CORDINATES OUTSIDE THE RANGE\n") - 1);
                    Coordenadas_fuera = 0;
                }else if (Coordenadas_mal==1){
                    USART_TxS("ERROR CARACTERS INGRESED WRONG\n", sizeof ("ERROR CARACTERS INGRESED WRONG\n") - 1);
                    Coordenadas_mal=0;
                } else {
                    Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                }
                break;
            case 'T':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE...") - 1);
                Actuator_Touch();
                break;
            case 'H':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE...") - 1);
                Actuator_Hold();
                break;
            case 'R':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE...") - 1);
                Actuator_Retract();
                break;
            case 'O':
                USART_TxS("WAIT UNTIL COMPLETE...\n", sizeof ("WAIT UNTIL COMPLETE...\n") - 1);
                Direccion_Memoria = USART_RxC();
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Lectura_MemoriaX(Direccion_Memoria,&CoordenadaX);
                Serial_Lectura_MemoriaY(Direccion_Memoria,&CoordenadaY);
                Serial_Lectura_MemoriaZ(Direccion_Memoria,&CoordenadaZ);
                if (Coordenadas_fuera == 1 ) {//En caso de Coordenada ingresada fuera del rango no comenzar
                     USART_TxS("ERROR CORDINATES OUTSIDE THE RANGE\n", sizeof ("ERROR CORDINATES OUTSIDE THE RANGE\n") - 1);
                    USART_TxS("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n", sizeof ("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n") - 1);
                    Coordenadas_fuera = 0;
                }else if (Coordenadas_mal==1){
                    USART_TxS("ERROR CARACTERS INGRESED WRONG\n", sizeof ("ERROR CARACTERS INGRESED WRONG\n") - 1);
                     USART_TxS("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n", sizeof ("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n") - 1);
                    Coordenadas_mal=0;
                } else {
                    //Iniciar control Manadando Variable CZ
                    Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                    //APAGAR AZUL
                    //PRENDER VERDE
                }
                break;
            case 'M':
                Direccion_Memoria = USART_RxC();
                USART_RxS(11, coordenada_setpoint); //Lectura de las coordenadas
                USART_TxS("WAIT UNTIL COMPLETE...\n", sizeof ("WAIT UNTIL COMPLETE...\n") - 1);
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Escritura_Memoria(Direccion_Memoria, coordenada_setpoint);
                break;
             case 'A'://Movimiento con botones 
                 USART_TxC('A');
                 while(GPIO_RA5_GetValue() ==0){
                     Motor_MovimientoZ();
                 }
                  USART_TxC('E');
                  break;
        }
    }
}

void Serial_DecodificacionX(char string_coordenada[], int *pointerCX) { //Convierte la coordenada en str a int
    char coordenadaX[3];
    for (int i = 0; i < 3; i++) {
        coordenadaX[i] = string_coordenada[i];
    }
    for (int i=0;i<3;i++){
    if (!(coordenadaX[i] >= 48 && coordenadaX[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    return;
}

void Serial_DecodificacionY(char string_coordenada[], int *pointerCY) {//Convierte la coordenada en str a int
   char coordenadaY[3];
    for (int i = 0; i < 3; i++) {
        coordenadaY[i] = string_coordenada[4 + i];
    }
   for (int i=0;i<3;i++){
    if (!(coordenadaY[i] >= 48 && coordenadaY[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return;
}

void Serial_DecodificacionZ(char string_coordenada[], int *pointerCZ) {//Convierte la coordenada en str a int
    char coordenadaZ[3];
    for (int i = 0; i < 3; i++) {
        coordenadaZ[i] = string_coordenada[8 + i];
    }
    for (int i=0;i<3;i++){
    if (!(coordenadaZ[i] >= 48 && coordenadaZ[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return;
}
void Serial_RangosCoordenadas(int C) {//Funcion que checa que las coordenadas se encuentren dentro del rango
    if (C > 300 || C < 0) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_fuera = 1;
    }
    return;
}

char Seria_Decodificacion_Memoria(char direccion) {
    switch (direccion) {
        case '0':
            direccion = 0x00;
            USART_TxS("COORDINATE OF SETPOINT 0:\n", sizeof ("COORDINATE OF SETPOINT 0:\n") - 1);
            break;
        case '1':
            direccion = 0x10;
            USART_TxS("COORDINATE OF SETPOINT 1:\n", sizeof ("COORDINATE OF SETPOINT 1\n") - 1);
            break;
        case '2':
            direccion = 0x20;
            USART_TxS("COORDINATE OF SETPOINT 2:\n", sizeof ("COORDINATE OF SETPOINT 2:\n") - 1);
            break;
        case '3':
            direccion = 0x30;
            USART_TxS("COORDINATE OF SETPOINT 3:\n", sizeof ("COORDINATE OF SETPOINT 3:\n") - 1);
            break;
        case '4':
            direccion = 0x40;
            USART_TxS("COORDINATE OF SETPOINT 4:\n", sizeof ("COORDINATE OF SETPOINT 4:\n") - 1);
            break;
        case '5':
            direccion = 0x50;
            USART_TxS("COORDINATE OF SETPOINT 5:\n", sizeof ("COORDINATE OF SETPOINT 5:\n") - 1);
            break;
        case '6':
            direccion = 0x60;
            USART_TxS("COORDINATE OF SETPOINT 6:\n", sizeof ("COORDINATE OF SETPOINT 6:\n") - 1);
            break;
        case '7':
            direccion = 0x70;
            USART_TxS("COORDINATE OF SETPOINT 7:\n", sizeof ("COORDINATE OF SETPOINT 7:\n") - 1);
            break;
        case '8':
            direccion = 0x80;
            USART_TxS("COORDINATE OF SETPOINT 8:\n", sizeof ("COORDINATE OF SETPOINT 8:\n") - 1);
            break;
        case '9':
            direccion = 0x90;
            USART_TxS("COORDINATE OF SETPOINT 9:\n", sizeof ("COORDINATE OF SETPOINT 9:\n") - 1);
            break;
        case 'A':
            direccion = 0xA0;
            USART_TxS("COORDINATE OF SETPOINT 10:\n", sizeof ("COORDINATE OF SETPOINT 10:\n") - 1);
            break;
        case 'B':
            direccion = 0xB0;
            USART_TxS("COORDINATE OF SETPOINT 11:\n", sizeof ("COORDINATE OF SETPOINT 11:\n") - 1);
            break;
        case 'C':
            direccion = 0xC0;
            USART_TxS("COORDINATE OF SETPOINT 12:\n", sizeof ("COORDINATE OF SETPOINT 12:\n") - 1);
            break;
        case 'D':
            direccion = 0xD0;
            USART_TxS("COORDINATE OF SETPOINT 13:\n", sizeof ("COORDINATE OF SETPOINT 13:\n") - 1);
            break;
        case 'E':
            direccion = 0xE0;
            USART_TxS("COORDINATE OF SETPOINT 14:\n", sizeof ("COORDINATE OF SETPOINT 14:\n") - 1);
            break;
        case 'F':
            direccion = 0xF0;
            USART_TxS("COORDINATE OF SETPOINT 15:\n", sizeof ("COORDINATE OF SETPOINT 15:\n") - 1);
            break;
    }
    return direccion;
}

void Serial_Lectura_MemoriaX(char direccion, int *pointerCX) {
    char coordenadaX[3];
    char direccionX;
    for (int i = 0; i < 3; i++) {
        direccionX = direccion + i;
        coordenadaX[i] = EEPROM_Rx(direccionX); //Guardar datos de le EEPROM en string
    }
   for (int i=0;i<3;i++){
    if (!(coordenadaX[i] >= 48 && coordenadaX[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    USART_TxS("COORDINATE X:", sizeof ("COORDINATE X:") - 1);
    USART_TxS(coordenadaX, sizeof (coordenadaX));
    Serial_RangosCoordenadas(CoordenadaX);
    return;
}

void Serial_Lectura_MemoriaY(char direccion, int *pointerCY) {
    char coordenadaY[3];
    char direccionY;
    for (int i = 0; i < 3; i++) {
        direccionY = direccion + i + 3;
        coordenadaY[i] = EEPROM_Rx(direccionY); //Guardar datos de le EEPROM en string
    }
    for (int i=0;i<3;i++){
    if (!(coordenadaY[i] >= 48 && coordenadaY[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    USART_TxS("\nCOORDINATE Y:", sizeof ("\nCOORDINATE Y:") - 1);
    USART_TxS(coordenadaY, sizeof (coordenadaY));
    Serial_RangosCoordenadas(CoordenadaY);
    return;
}

void Serial_Lectura_MemoriaZ(char direccion, int *pointerCZ) {
    char coordenadaZ[3];
    char direccionZ;
    for (int i = 0; i < 3; i++) {
        direccionZ = direccion + i + 6;
        coordenadaZ[i] = EEPROM_Rx(direccionZ); //Guardar datos de le EEPROM en string
    }
   for (int i=0;i<3;i++){
    if (!(coordenadaZ[i] >= 48 && coordenadaZ[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    USART_TxS("\nCOORDINATE Z:", sizeof ("\nCOORDINATE Z:") - 1);
    USART_TxS(coordenadaZ, sizeof (coordenadaZ));
    Serial_RangosCoordenadas(CoordenadaZ);
    return;
}

void Serial_Escritura_Memoria(char direccion, char string_setpoint[]) {
    char direccionFinal;
    for (int i = 0; i < 3; i++) {
        direccionFinal = direccion + i;
        EEPROM_Tx(direccionFinal, string_setpoint[i]);
    }
    USART_TxS("COORDINATE X SAVED\n", sizeof ("COORDINATE X SAVED\n") - 1);
    for (int i = 0; i < 3; i++) {
        direccionFinal = direccion + i + 3;
        EEPROM_Tx(direccionFinal, string_setpoint[i + 4]);
    }
    USART_TxS("COORDINATE Y SAVED\n", sizeof ("COORDINATE Y SAVED\n") - 1);
    for (int i = 0; i < 3; i++) {
        direccionFinal = direccion + i + 6;
        EEPROM_Tx(direccionFinal, string_setpoint[i + 8]);
    }
    USART_TxS("COORDINATE Z SAVED\n", sizeof ("COORDINATE Z SAVED\n") - 1);
    return;
}

/*
 void Serial_Lectura_Memoria(char direccion, int *pointerCX, int *pointerCY, int *pointerCZ) {
    char coordenadaX[3];
    char coordenadaY[3];
    char coordenadaZ[3];
    char direccionX;
    char direccionY;
    char direccionZ;
    for (int i = 0; i < 3; i++) {
        direccionX = direccion + i;
        coordenadaX[i] = EEPROM_Rx(direccionX); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < 3; i++) {
        direccionY = direccion + i + 3;
        coordenadaY[i] = EEPROM_Rx(direccionY); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < 3; i++) {
        direccionZ = direccion + i + 6;
        coordenadaZ[i] = EEPROM_Rx(direccionZ); //Guardar datos de le EEPROM en string
    }

 *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
 *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
 *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada z
    USART_TxS("READ\n", sizeof ("READ\n")-1);
    USART_TxS("COORDINATE X:", sizeof ("COORDINATE X:")-1);
    USART_TxS(coordenadaX, sizeof (coordenadaX));
    USART_TxS("\nCOORDINATE Y:", sizeof ("\nCOORDINATE Y:")-1);
    USART_TxS(coordenadaY, sizeof (coordenadaY));
    USART_TxS("\nCOORDINATE Z:", sizeof ("\nCOORDINATE Z:")-1);
    USART_TxS(coordenadaZ, sizeof (coordenadaZ));
    Serial_RangosCoordenadas(CoordenadaX);
    Serial_RangosCoordenadas(CoordenadaY);
    Serial_RangosCoordenadas(CoordenadaZ);
    return;
}
 
 void Serial_FiltroCaracteres(char C[]) {//Funcion que checa que las coordenadas se encuentren dentro del rango
    for (int i=0;i<3;i++){
    if (!(C[i] >= 48 && C[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    return;
}
 
 */

