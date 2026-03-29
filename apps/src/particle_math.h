#ifndef PARTICLE_MATH_H
#define PARTICLE_MATH_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "particles.h"

particle *distanciaParticulas(particle *p1, particle *p2);
vector *distanciaConjuntoParticulas(vector *vectorParticulas1, vector *vectorParticulas2);

#endif