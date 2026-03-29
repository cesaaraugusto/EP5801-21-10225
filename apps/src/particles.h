#ifndef PARTICLES_H
#define PARTICLES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vectors/vector_common.h"

typedef struct PARTICLE
{
    float x;
    float y;
    float z;
    float velocidad;
} particle;

vector *crearParticulas();
vector *agregarParticula(vector *vectorParticulas, particle *particula);
vector *insertarParticula(vector *vectorParticulas, particle *particula, size_t position);
vector *eliminarParticula(vector *vectorParticulas, size_t position);
vector *eliminarUltimaParticula(vector *vectorParticulas);
void *detalleParticula(vector *vectorParticulas, size_t position);
void eliminarParticulas(vector *vectorParticulas);
#endif