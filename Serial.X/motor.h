#ifndef motor_H
#define	motor_H

#ifdef	__cplusplus
extern "C" {
#endif
int pasos_convertidos=0;
int PasosX=0;
int PasosY=0;
int DeltaX=0;
int DeltaY=0;
int CoordenadaXX=0;
int CoordenadaYY=0;
int coordenada_anteriorX=0;
int coordenada_anteriorY=0;
int Motor_Conversion(int CoordenadaX);
void Motor_Movimiento(char Oupcode,int CoordenadaX,int CoordenadaY);
void Motor_Calcular_PasosX(int coordenada_actualX);
void Motor_Calcular_PasosY(int coordenada_actualY);
void Motor_MovimientoZ(char direccion);
void Motor_MovimientoZ_Init(char direccion);
#ifdef	__cplusplus
}
#endif

#endif	