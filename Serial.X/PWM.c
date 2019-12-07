
#include <xc.h>
#include "configuration.h"
#include "PWM.h"
#include "GPIOsparcA1.h"

void PWM_GeneratePulsos(char Oupcode,int pulsosX, int pulsosY) {
    if (Oupcode == 'S') {
        PWM_InitS();
    } else {
        PWM_InitF();
    }
    ENABLE_X = 0;//Habilita los drivers
    ENABLE_Y = 0; //Habilita los drivers
    int countX = 0;
    int countY = 0;
    if (pulsosX==0){
        ENABLE_X = 1;//En caso de que los pasos enviados sean 0 no mover
    } 
    if (pulsosY==0){
        ENABLE_Y = 1;////En caso de que los pasos enviados sean 0 no mover
    }
    T2CONbits.TMR2ON = 1; // Timer ON
    while ((countX < pulsosX) || (countY < pulsosY)) {
        if (countX < pulsosX) {
            if (PORTCbits.RC1 == 1) {
                countX = PWM_OneshotX(countX);
            } else {
                oneshotX = 0;
            }
        } else {
            ENABLE_X = 1;
        }
        if (countY < pulsosY) {
            if (PORTCbits.RC2 == 1) {
                countY = PWM_OneshotY(countY);
            } else {
                oneshotY = 0;
            }
        } else {
            ENABLE_Y = 1;
        }
    }
    
    countX = 0;
    oneshotX = 0;
    countY = 0;
    oneshotY = 0;
    ENABLE_Y = 1;
     ENABLE_X = 1;
    T2CONbits.TMR2ON = 0; // Timer OFF
    return;
}
/*
void PWM_Pulsos_Home(char banderaX, char banderaY){
    PWM_InitS();
    if(banderaX==1 && banderaY==1){
        Enable_DriverX = 1;//DESHabilita los drivers
    Enable_DriverY = 1; //DESHabilita los drivers
    T2CONbits.TMR2ON = 0; // Timer off
    return;
    }
    if (banderaX==1){
    Enable_DriverX = 1;//DESHabilita los drivers
    Enable_DriverY = 0; //Habilita los drivers=
    }else if(banderaY==1){
       Enable_DriverX = 0;//Habilita los drivers
    Enable_DriverY = 1; //DesHabilita los drivers= 
    } else {
        Enable_DriverX = 0;//Habilita los drivers
    Enable_DriverY =0 ; //Habilita los drivers
    }
     T2CONbits.TMR2ON = 1; // Timer ON
    return;
}*/

void PWM_InitF(void) {

    PR2 = 0X7C;//FRECUENCIA DE 1000HZ
    CCPR1L = 0X3E;//DUTY CICLE 50
    CCPR2L = 0X3E;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    T2CON = 0X03; //PREESCALER 16 TIMER 2
    CCP1CON = 0X0C;
    CCP2CON = 0X0C;
    T2CONbits.TMR2ON = 0; 
    return;
}

void PWM_InitS(void) {

    PR2 = 0XF0;//FRECUENCIA DE 500HZ
    CCPR1L = 0X3E;//DUTY CICLE 50
    CCPR2L = 0X3E;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    T2CON = 0X03; //PREESCALER 16 TIMER 2
    CCP1CON = 0X0C;
    CCP2CON = 0X0C;
    T2CONbits.TMR2ON = 0; // Timer ON
    return;
}

int PWM_OneshotX(int countX) {
    if (PORTCbits.RC1 == 1 & oneshotX == 0) {
        countX++;
        oneshotX = 1;
    }
    return countX;
}

int PWM_OneshotY(int countY) {
    if (PORTCbits.RC2 == 1 & oneshotY == 0) {
        countY++;
        oneshotY = 1;
    }
    return countY;
}


