#ifndef ControlZ_H
#define	ControlZ_H

#ifdef	__cplusplus

#endif

void Control_Z (int Referencia);
void Control_ConvertirDistancia(int Volts);
int Control_InsertBits(char Bmenos, char Bmas);
int Control_LecturaFiltro(int n);
char controlZ;
float error;
float Distancia;
int Lectura;
int LecturaFiltro;
long Suma;
#ifdef	__cplusplus

#endif

#endif	
