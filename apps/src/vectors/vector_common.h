
#ifndef VECTOR_COMMON_H
#define VECTOR_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum TYPEVECTOR
{
    custom = 0x00,
    u8 = 0x01,
    u16 = 0x02,
    u32 = 0x04,
    u64 = 0x08,
    f32 = 0x14,
    f64 = 0x18
} typeVector;

typedef struct VECTOR
{
    size_t sizeElement;
    size_t capacity;
    size_t itemsUsed;
    void *data;
    typeVector type;
} vector;

vector *createVector(size_t sizeElement, typeVector type, size_t capacity);
void deleteVector(vector *vectorName);

void *pushVector(vector *vectorName, void *element);
void *popVector(vector *vectorName);
bool insertItemVector(vector *vectorName, void *element, size_t position);
bool eraseItemVector(vector *vectorName, size_t position);
void *atVector(vector *vectorName, size_t position);

#endif