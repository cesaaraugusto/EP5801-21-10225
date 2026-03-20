#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "arenaStack.h"

stack *crearStack(size_t sizeStack)
{
    stack *stackCreada = malloc(sizeof(stack) + sizeStack); // Solicitud memoria
    if (stackCreada == NULL)                                // Si no hay memoria disponible
    {
        exit(-1);
    }

    stackCreada->size = sizeStack;                                                                     // Asignación tamaño a la stackCreada
    stackCreada->offset = 0;                                                                           // Asignación posición inical a la stackCreada
    stackCreada->memory = memset((void *)((uint8_t *)(stackCreada) + sizeof(stack)), 0x00, sizeStack); // Nos situamos en la dirección de la stackCreada, nos desplazamos el tamaño de la estructura  para poder apuntar al inicio de la stack usable. Para que esté limpia seteamos en 0 los bytes de la stack
    return stackCreada;
}

void liberarStack(stack *nombreStack)
{
    if (nombreStack == NULL)
    {
        printf("Stack no creada\n");
        return;
    }

    free(nombreStack);
}

void *pushItem(stack *nombreStack, size_t sizeData, void *data)
{
    if (nombreStack == NULL)
    {
        printf("Stack no creado\n");
        return NULL;
    }

    if (nombreStack->offset + sizeData + sizeof(itemHeader) <= nombreStack->size) // Verificación si hay espacio
    {
        // Copy Data to memory
        void *ptrData = memcpy(((uint8_t *)nombreStack->memory) + nombreStack->offset, data, sizeData);

        // Header nueva data
        itemHeader *newItemHeader = ((itemHeader *)(((uint8_t *)nombreStack->memory) + nombreStack->offset + sizeData));
        newItemHeader->sizeItem = sizeData;

        // Actulizar offset
        nombreStack->offset += sizeData + sizeof(itemHeader);

        return ptrData;
    }
    else
    {
        printf("No hay espacio suficiente\n");
        return NULL;
    }
}

void *popItem(stack *nombreStack)
{
    if (nombreStack == NULL || nombreStack->offset == 0)
    {
        return NULL;
    }

    itemHeader *ultimoHeader = ((itemHeader *)(((uint8_t *)nombreStack->memory) + nombreStack->offset - sizeof(itemHeader))); // Obtener header del último item

    void *ptrDataAnterior = ((uint8_t *)nombreStack->memory) + nombreStack->offset - sizeof(itemHeader) - ultimoHeader->sizeItem; // Obtener puntero al dato del último item

    // Actulizar offset
    nombreStack->offset -= ultimoHeader->sizeItem + sizeof(itemHeader);

    return ptrDataAnterior;
}