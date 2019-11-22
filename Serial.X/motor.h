#ifndef motor_H
#define	motor_H

#ifdef	__cplusplus
extern "C" {
#endif
int pasos_convertidos=0;
int pasosX=0;
int pasosY=0;
int Motor_Conversion(int CoordenadaX);
void Motor_Movimiento(char Oupcode,int CoordenadaX,int CoordenadaY);
#ifdef	__cplusplus
}
#endif

#endif	