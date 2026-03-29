#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "particles.h"

vector *crearParticulas()
{
    vector *vectorParticulas = createVector(sizeof(particle), custom, 2); // Creamos un vector para almacenar las particulas

    if (vectorParticulas == NULL)
    {
        return NULL;
    }

    return vectorParticulas;
}

vector *agregarParticula(vector *vectorParticulas, particle *particula)
{
    if (vectorParticulas == NULL || particula == NULL)
    {
        return NULL;
    }

    pushVector(vectorParticulas, particula); // Agregamos la particula al vector

    return vectorParticulas;
}

vector *insertarParticula(vector *vectorParticulas, particle *particula, size_t position)
{
    if (vectorParticulas == NULL || particula == NULL)
    {
        return NULL;
    }

    insertItemVector(vectorParticulas, particula, position); // Insertamos la particula en la posicion deseada

    return vectorParticulas;
}

vector *eliminarParticula(vector *vectorParticulas, size_t position)
{
    if (vectorParticulas == NULL)
    {
        return NULL;
    }

    eraseItemVector(vectorParticulas, position); // Eliminamos la particula de la posicion deseada
    return vectorParticulas;
}

vector *eliminarUltimaParticula(vector *vectorParticulas)
{
    if (vectorParticulas == NULL)
    {
        return NULL;
    }

    popVector(vectorParticulas); // Eliminamos la particula del vector

    return vectorParticulas;
}

void *detalleParticula(vector *vectorParticulas, size_t position)
{
    if (vectorParticulas == NULL)
    {
        return NULL;
    }

    return atVector(vectorParticulas, position); // Obtenemos la particula de la posicion deseada
}

void eliminarParticulas(vector *vectorParticulas)
{
    if (vectorParticulas == NULL)
    {
        return;
    }

    deleteVector(vectorParticulas); // Eliminamos el vector de particulas
}