#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "particle_math.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

particle *distanciaParticulas(particle *p1, particle *p2)
{
    particle *resultado = malloc(sizeof(particle)); // Creamos una particula para almacenar el resultado
    if (resultado == NULL)
    {
        return NULL;
    }

    resultado->x = p2->x - p1->x;
    resultado->y = p2->y - p1->y;
    resultado->z = p2->z - p1->z;
    resultado->velocidad = p2->velocidad - p1->velocidad;

    return resultado;
}

vector *distanciaConjuntoParticulas(vector *vectorParticulas1, vector *vectorParticulas2)
{
    if (vectorParticulas1 == NULL || vectorParticulas2 == NULL)
    {
        return NULL;
    }

    vector *resultado = createVector(sizeof(particle), custom, 2); // Creamos un vector para almacenar las particulas

    if (resultado == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < MIN(vectorParticulas1->itemsUsed, vectorParticulas2->itemsUsed); i++)
    {
        particle *p1 = (particle *)detalleParticula(vectorParticulas1, i);
        particle *p2 = (particle *)detalleParticula(vectorParticulas2, i);

        particle *distancia = distanciaParticulas(p1, p2);
        agregarParticula(resultado, distancia);
        free(distancia); // Liberamos la memoria de la distancia calculada
    }

    return resultado;
}