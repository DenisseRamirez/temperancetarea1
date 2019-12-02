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

void Usart_Interface_Off(char color){
    if (color=='A'){
        GPIO_RB7_SetLow();
    }else if (color=='V'){
        GPIO_RB6_SetLow();
    } else if (color=='R'){
        GPIO_RB5_SetLow();
    }
    return;
}
void Usart_Interface_ON(char color){
    if (color=='A'){
        GPIO_RB7_SetHigh();
    }else if (color=='V'){
        GPIO_RB6_SetHigh();
    } else if (color=='R'){
        GPIO_RB5_SetHigh();
    }
    return;
}

void Usart_Interface_Flash(char color){
      if (color=='A'){
        GPIO_RB7_SetHigh();
        __delay_ms(200);
        GPIO_RB7_SetLow();
    }else if (color=='V'){
        GPIO_RB6_SetHigh();
        __delay_ms(200);
        GPIO_RB6_SetLow();
    } else if (color=='R'){
        GPIO_RB5_SetHigh();
        __delay_ms(200);
        GPIO_RB5_SetLow();
    }
      return;
}