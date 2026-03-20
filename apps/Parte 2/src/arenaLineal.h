#ifndef ARENA_LINEAL_H
#define ARENA_LINEAL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ARENA_LINEAL
{
    size_t size;   // Tamaño Arena Solicitada
    size_t offset; // Contador Posición dentro de la Arena
    void *memory;  // Inicio memoria
} arena;

// firmas funciones
arena *crearArena(size_t sizeArena);
void *colocarArena(arena *nombreArena, size_t sizeData, void *data);
void liberarArena(arena *nombreArena);

#endif