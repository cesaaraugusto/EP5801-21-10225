#include <stdio.h>
#include <stdint.h>

#define MEMORIA 256

uint8_t memoria[MEMORIA]; // Memoria Inicial
size_t memOffset = 0;     // Offset Inicial

typedef struct
{
    size_t tamMaximo; // Tamaño Reservado
    size_t offset;    // Posición elemento
    void *buffer;     // Inicio memoria
} espacioMemoria;

espacioMemoria staticMalloc(size_t maxSize)
{
    espacioMemoria arena;
    if (memOffset + maxSize <= MEMORIA) // Verificamos si nos queda memoria
    {
        arena.tamMaximo = maxSize;  // Setear tamaño solicitado
        arena.offset = memOffset;   // Setear posición de espacio solicitado
        arena.buffer = &memoria[0]; // Setear el inicio de la memoria
        memOffset += maxSize;       // Incrementar posición en memoria para nuevo item
    }
    else
    {
        printf("No hay suficiente memoria disponible.\n");
        arena.tamMaximo = 0;
        arena.offset = 0;
        arena.buffer = NULL;
    }
    return arena;
}