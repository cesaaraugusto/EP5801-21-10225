#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "vector_common.h"

vector *createVector(size_t sizeElement, typeVector type, size_t capacity)
{
    if (capacity == 0)
    {
        return NULL;
    }

    vector *vectorCreado = (vector *)malloc(sizeof(vector));

    if (vectorCreado == NULL)
    {
        return NULL;
    }

    vectorCreado->type = type;
    vectorCreado->capacity = capacity;
    vectorCreado->itemsUsed = 0;

    switch (type)
    {
    case u8:
    case u16:
    case u32:
    case u64:
    case f32:
    case f64:
        vectorCreado->sizeElement = 0xf & type; // Mascara de bits para obtener el tamaño del elemento
        break;

    default:
        vectorCreado->sizeElement = sizeElement;
        break;
    }

    vectorCreado->data = malloc(sizeElement * capacity);      // reservamos espacio para la data
    memset(vectorCreado->data, 0x00, sizeElement * capacity); // limpio espacio reservado

    if (vectorCreado->data == NULL)
    {
        free(vectorCreado);
        return NULL;
    }

    return vectorCreado;
}

void deleteVector(vector *vectorName)
{

    if (vectorName != NULL)
    {
        if (vectorName->data != NULL)
        {
            free(vectorName->data);
        }
        free(vectorName);
    }
}

void *pushVector(vector *vectorName, void *element)
{
    if (vectorName == NULL || vectorName->data == NULL || element == NULL)
    {
        return NULL;
    }

    if (vectorName->itemsUsed == vectorName->capacity) // Si el vector esta lleno, se duplica su capacidad
    {
        vectorName->capacity <<= 1; // Duplicamos la capacidad

        vectorName->data = realloc(vectorName->data, vectorName->capacity * vectorName->sizeElement);
    }

    void *referenciaFinalData = (void *)((uint8_t *)vectorName->data + (vectorName->itemsUsed * vectorName->sizeElement)); // Calculamos la referencia final de la data

    memcpy(referenciaFinalData, element, vectorName->sizeElement); // Copiamos el elemento al final de la data
    vectorName->itemsUsed++;                                       // Incrementamos el contador de items usados

    return referenciaFinalData;
}

void *popVector(vector *vectorName)
{
    if (vectorName == NULL)
    {
        return NULL;
    }

    if (vectorName->itemsUsed == 0) // Si el vector esta vacio, no se puede eliminar un elemento
    {
        return NULL;
    }

    void *referenciaPenultimaData = (void *)((uint8_t *)vectorName->data + ((vectorName->itemsUsed - 1) * vectorName->sizeElement)); // Calculamos la referencia final de la data

    vectorName->itemsUsed--; // Decrementamos el contador de items usados

    return referenciaPenultimaData;
}

bool insertItemVector(vector *vectorName, void *element, size_t position)
{
    if (vectorName == NULL || vectorName->data == NULL || element == NULL)
    {
        return false;
    }

    if (position > vectorName->itemsUsed) // Si la posicion es mayor a la cantidad de items usados, no se puede insertar el elemento
    {
        return false;
    }

    if (vectorName->itemsUsed == vectorName->capacity) // Si el vector esta lleno, se duplica su capacidad
    {
        vectorName->capacity <<= 1; // Duplicamos la capacidad

        vectorName->data = realloc(vectorName->data, vectorName->capacity * vectorName->sizeElement);
    }

    void *referenciaFinalData = (void *)((uint8_t *)vectorName->data + (position * vectorName->sizeElement)); // Calculamos la referencia final de la data

    memmove((uint8_t *)referenciaFinalData + vectorName->sizeElement, referenciaFinalData, (vectorName->itemsUsed - position) * vectorName->sizeElement); // Movemos los elementos a la derecha para hacer espacio para el nuevo elemento
    memcpy((uint8_t *)vectorName->data + (position * vectorName->sizeElement), element, vectorName->sizeElement);                                         // Copiamos el elemento a la posicion deseada
    vectorName->itemsUsed++;                                                                                                                              // Incrementamos el contador de items usados

    return true;
}

void *atVector(vector *vectorName, size_t position)
{

    if (vectorName == NULL || vectorName->data == NULL)
    {
        return NULL;
    }

    if (position >= vectorName->itemsUsed) // Si la posicion es mayor o igual a la cantidad de items usados, no se puede obtener el elemento
    {
        return NULL;
    }

    void *referenciaData = (void *)((uint8_t *)vectorName->data + (position * vectorName->sizeElement)); // Calculamos la referencia de la data

    return referenciaData;
}

bool eraseItemVector(vector *vectorName, size_t position)
{
    if (vectorName == NULL || vectorName->data == NULL)
    {
        return NULL;
    }

    if (position >= vectorName->itemsUsed) // Si la posicion es mayor o igual a la cantidad de items usados, no se puede eliminar el elemento
    {
        return NULL;
    }

    void *referenciaData = (void *)((uint8_t *)vectorName->data + (position * vectorName->sizeElement) + vectorName->sizeElement); // Calculamos la referencia de la data

    memmove((uint8_t *)referenciaData - vectorName->sizeElement, referenciaData, (vectorName->itemsUsed - position) * vectorName->sizeElement); // Movemos los elementos a la derecha para hacer espacio para el nuevo elemento

    vectorName->itemsUsed--;

    return true;
}
