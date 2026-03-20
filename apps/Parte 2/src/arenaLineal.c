#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "arenaLineal.h"

arena *crearArena(size_t sizeArena)
{
    arena *arenaCreada = malloc(sizeof(arena) + sizeArena); // Solicitud memoria
    if (arenaCreada == NULL)                                // Si no hay memoria disponible
    {
        exit(-1);
    }

    arenaCreada->size = sizeArena;                                                                     // Asignación tamaño a la arenaCreada
    arenaCreada->offset = 0;                                                                           // Asignación posición inical a la arenaCreada
    arenaCreada->memory = memset((void *)((uint8_t *)(arenaCreada) + sizeof(arena)), 0x00, sizeArena); // Nos situamos en la dirección de la arenaCreada, nos desplazamos el tamaño de la estructura  para poder apuntar al inicio de la arena usable. Para que esté limpia seteamos en 0 los bytes de la arena
    printf("Arena creada\n");
    return arenaCreada;
}

void *colocarArena(arena *nombreArena, size_t sizeData, void *data)
{
    if (nombreArena == NULL)
    {
        printf("Arena no creada\n");
        return NULL;
    }

    if (nombreArena->offset + sizeData <= nombreArena->size) // Verificamos espacio en la arena
    {
        void *ptrData = memcpy((void *)(((uint8_t *)nombreArena->memory) + nombreArena->offset), data, sizeData); // Colocamos el objeto en la dirección desocupada
        nombreArena->offset += sizeData;                                                                          // Incremento del contador de posición dentro de la arena
        printf("Objeto colocado en la arena\n");
        return ptrData;
    }
    else
    {
        return NULL;
    }
}

void liberarArena(arena *nombreArena)
{
    if (nombreArena == NULL)
    {
        printf("Arena no creada\n");
        return;
    }

    free(nombreArena);
    printf("Arena liberada\n");
}