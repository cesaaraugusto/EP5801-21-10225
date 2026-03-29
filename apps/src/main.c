#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "particles.h"
#include "particle_math.h"

int main()
{
    // Crearción Particulas
    vector *Particulas = crearParticulas();

    // Agregar Partículas
    agregarParticula(Particulas, &(particle){.x = 1.0f, .y = 2.0f, .z = 3.0f, .velocidad = 4.0f});
    agregarParticula(Particulas, &(particle){.x = 5.0f, .y = 6.0f, .z = 7.0f, .velocidad = 8.0f});

    // Insertar Partícula en el medio
    insertarParticula(Particulas, &(particle){.x = 0.0f, .y = 0.0f, .z = 0.0f, .velocidad = 0.0f}, 1);

    // Detalle Partícula
    particle *detalle = (particle *)detalleParticula(Particulas, 1);
    printf("Detalle Partícula: x = %f, y = %f, z = %f, velocidad = %f\n", detalle->x, detalle->y, detalle->z, detalle->velocidad);

    // Eliminar Partícula del medio
    eliminarParticula(Particulas, 1);

    // Distancia entre Partículas para cada eje
    particle *distancia = distanciaParticulas((particle *)detalleParticula(Particulas, 0), (particle *)detalleParticula(Particulas, 1));
    printf("Distancia Partículas: x = %f, y = %f, z = %f, velocidad = %f\n", distancia->x, distancia->y, distancia->z, distancia->velocidad);
    free(distancia); // Liberamos la memoria de la distancia calculada

    // Vaciar Partículas
    eliminarUltimaParticula(Particulas);
    eliminarUltimaParticula(Particulas);

    // Eliminar Vector de Partículas
    eliminarParticulas(Particulas);

    // Distancia entre conjuntos de Partículas
    vector *ParticulasAgua = crearParticulas();
    agregarParticula(ParticulasAgua, &(particle){.x = 1.0f, .y = 6.0f, .z = 3.0f, .velocidad = 4.0f});
    agregarParticula(ParticulasAgua, &(particle){.x = 5.0f, .y = 6.0f, .z = 7.0f, .velocidad = 8.0f});

    vector *ParticulasAceite = crearParticulas();
    agregarParticula(ParticulasAceite, &(particle){.x = 2.0f, .y = 7.0f, .z = 4.0f, .velocidad = 5.0f});
    agregarParticula(ParticulasAceite, &(particle){.x = 7.0f, .y = 8.0f, .z = 9.0f, .velocidad = 10.0f});

    vector *distanciasParticulas = distanciaConjuntoParticulas(ParticulasAgua, ParticulasAceite);

    for (size_t i = 0; i < distanciasParticulas->itemsUsed; i++)
    {
        printf("Distancias Particulas %zu: x = %f, y = %f, z = %f, velocidad = %f\n", i,
               ((particle *)detalleParticula(distanciasParticulas, i))->x,
               ((particle *)detalleParticula(distanciasParticulas, i))->y,
               ((particle *)detalleParticula(distanciasParticulas, i))->z,
               ((particle *)detalleParticula(distanciasParticulas, i))->velocidad);
    }

    return 0;
}