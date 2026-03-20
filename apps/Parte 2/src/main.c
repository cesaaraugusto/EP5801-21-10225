#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "arenaLineal.h"

extern void asmprint(char *string, size_t longitud); // Declaración función ensamblador

int main()
{
    arena *ptrStrings = crearArena(100);                                    // Crear arena
    char *texto = "Hola Mundo";                                             // String
    void *ptrString_1 = colocarArena(ptrStrings, strlen(texto) + 1, texto); // Asignación String dentro de la arena
    asmprint((char *)ptrString_1, strlen((char *)ptrString_1));             // Imprimir String

    liberarArena(ptrStrings);
}