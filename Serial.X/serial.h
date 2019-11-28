#ifndef serial_H
#define	serial_H

#ifdef	__cplusplus
extern "C" {
#endif

    void Serial_DecodificacionX(char string_coordenada[], int *pointerCX);
    void Serial_DecodificacionY(char string_coordenada[], int *pointerCY);
    void Serial_DecodificacionZ(char string_coordenada[], int *pointerCZ);
    void Serial_Lectura_MemoriaX(char direccion, int *pointerCX) ;
    void Serial_Lectura_MemoriaY(char direccion, int *pointerCY) ;
    void Serial_Lectura_MemoriaZ(char direccion, int *pointerCZ) ;
    void Serial_RangosCoordenadas(int C);
   // void Serial_FiltroCaracteres(char C[]);
   // void Serial_Lectura_Memoria(char direccion, int *pointerCX, int *pointerCY, int *pointerCZ);
    void Serial_Escritura_Memoria(char direccion,char string_setpoint[]);
    char Seria_Decodificacion_Memoria(char direccion);
    int CoordenadaX; //Coordenada en x, global ya que sera usada en varias funciones
    int CoordenadaY; //Cooordenada en y
    int CoordenadaZ; //Coordenad en Z
    char C[3];
    char coordenada_array[7];
    char coordenada_setpoint[11];
    char Direccion_Memoria;
    char Coordenadas_fuera=0;
    char Coordenadas_mal=0;
#ifdef	__cplusplus
}
#endif

#endif	