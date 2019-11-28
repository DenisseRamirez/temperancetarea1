
    
#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus

#endif

char bites_menosS;
char bites_masS;
int Lectura;
int LecturaFiltro;
long Suma;
float Distancia;
void ADC_ConvertirDistancia(int Volts);
int ADC_InsertBits(char Bmenos, char Bmas);
int ADC_LecturaFiltro(int n);
void ADC_Init() ;


#ifdef	__cplusplus

#endif

#endif	
