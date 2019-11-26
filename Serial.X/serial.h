#ifndef serial_H
#define	serial_H

#ifdef	__cplusplus
extern "C" {
#endif

    void Serial_DecodificacionX(char string_coordenada[], int *pointerCX);
    void Serial_DecodificacionY(char string_coordenada[], int *pointerCY);
    void Serial_DecodificacionZ(char string_coordenada[], int *pointerCZ);
    void Serial_Lectura_Memoria(char direccion, int *pointerCX, int *pointerCY, int *pointerCZ);
    void Serial_Escritura_Memoria(char direccion,char string_setpoint[]);
    char Seria_Decodificacion_Memoria(char direccion);
    int CoordenadaX; //Coordenada en x, global ya que sera usada en varias funciones
    int CoordenadaY; //Cooordenada en y
    int CoordenadaZ; //Coordenad en Z
    char coordenada_array[7];
    char coordenada_setpoint[11];
    char Direccion_Memoria;

#ifdef	__cplusplus
}
#endif

#endif	