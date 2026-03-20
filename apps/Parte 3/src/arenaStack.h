#ifndef Stack_STACK_H
#define Stack_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_STACK
{
    size_t size;
    size_t offset;
    void *memory;
} stack;

typedef struct ITEM_STACK_HEADER
{
    size_t sizeItem;
} itemHeader;

// Firmas de las funciones
stack *crearStack(size_t sizeStack);
void *pushItem(stack *nombreStack, size_t sizeData, void *data);
void *popItem(stack *nombreStack);
void liberarStack(stack *nombreStack);

#endif