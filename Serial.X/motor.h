#ifndef motor_H
#define	motor_H

#ifdef	__cplusplus
extern "C" {
#endif
int pasos_convertidos=0;
int pasosX=0;
int pasosY=0;
int coordenaX=0;
int coordenaY=0;
int CoordenadaXX=0;
int CoordenadaYY=0;
int Motor_Conversion(int CoordenadaX);
void Motor_Movimiento(char Oupcode,int CoordenadaX,int CoordenadaY);
int Motor_Calcular_PasosX(int pasos_converX);
int Motor_Calcular_PasosY(int pasos_converY);
void Motor_MovimientoZ(char direccion);
void Motor_MovimientoZ_Init(char direccion);
#ifdef	__cplusplus
}
#endif

#endif	