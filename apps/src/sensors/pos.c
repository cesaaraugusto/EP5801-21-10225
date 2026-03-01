#include <stdio.h>
#include "pos.h"

pos posicion;

void printPos()
{
    printf("Posición: %u, %u, %u\n", posicion.x, posicion.y, posicion.z);
}

// Decodificación: Primer byte se desplaza un byte para hacer espacio al segundo byte de la coordenada respectiva, y finalmente se juntan ambos bytes
printSensorInfo PosInfo(uint8_t *data)
{
    posicion.x = (data[0] << 8) | data[1];
    posicion.y = (data[2] << 8) | data[3];
    posicion.z = (data[4] << 8) | data[5];
    return printPos;
}