#ifndef serial_H
#define	serial_H

#ifdef	__cplusplus
extern "C" {
#endif

void Serial_DecodificacionX (char string_coordenada[], int *pointerCX);
void Serial_DecodificacionY (char string_coordenada[], int *pointerCY);
int CX; //Coordenada en x, global ya que sera usada en varias funciones
int CY; //Cooordenada en y
char coordenada_array[7];
#ifdef	__cplusplus
}
#endif

#endif	