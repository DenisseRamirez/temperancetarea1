/* 
 * File:   User_Interface.c
 * Author: saenz
 *
 * Created on December 2, 2019, 11:56 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "GPIOsparcA1.h"
#include "User_Interface.h"
#include "configuration.h"

void Usart_Interface_OFF(char color){
    if (color=='A'){
        LED_B_SetLow();
    }else if (color=='V'){
        LED_G_SetLow();
    } else if (color=='R'){
        LED_R_SetLow();
    }
    return;
}
void Usart_Interface_ON(char color){
    if (color=='A'){
        LED_B_SetHigh();
    }else if (color=='V'){
        LED_G_SetHigh();
    } else if (color=='R'){
        LED_R_SetHigh();
    }
    return;
}
/*
void Usart_Interface_Flash(char color){
      if (color=='A'){
        GPIO_RB7_SetHigh();
        __delay_ms(200);
          __delay_ms(200);
        GPIO_RB7_SetLow();
    }else if (color=='V'){
        GPIO_RB6_SetHigh();
        __delay_ms(200);
          __delay_ms(200);
        GPIO_RB6_SetLow();
    } else if (color=='R'){
        GPIO_RB5_SetHigh();
        __delay_ms(200);
          __delay_ms(200);
        GPIO_RB5_SetLow();
    }
      return;
}*/