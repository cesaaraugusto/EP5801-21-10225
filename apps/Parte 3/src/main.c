#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arenaStack.h"
#include <stdint.h>

char entradaUsuario[100]; // Máximo de entradas
char *ptrConversor;
float Num;

int main()
{
    stack *stackCalculadora = crearStack(100 * sizeof(float)); // Crear stack para 100 floats
    float resultado = 0;

    printf("\033[4mCalculadora RPN - Para salir presione q\033[0m\n"); // Titulo
    do
    {
        if (stackCalculadora->offset != 0) // Imprimir contenido de la pila si no está vacía
        {
            size_t cursor = 0;

            while (cursor < stackCalculadora->offset) // Recorrer la pila hasta el offset actual
            {
                float *data = (float *)(((uint8_t *)stackCalculadora->memory) + cursor); // Obtener el puntero al dato actual

                printf("%f ", *data); // Imprimir el valor del dato actual

                if (*data == 0)
                {
                    popItem(stackCalculadora); // Si el valor es 0, sacarlo de la pila
                }

                cursor += (sizeof(float) + sizeof(itemHeader)); // Avanzar el cursor al siguiente elemento (tamaño del dato + tamaño del header)
            }
        }

        if (fgets(entradaUsuario, sizeof(entradaUsuario), stdin) == NULL) // Para entrada nula
            return 1;

        char *termino = strtok(entradaUsuario, " \n"); // Manejo de entrada

        while (termino != NULL)
        {
            Num = strtof(termino, &ptrConversor);                 // Conversión a float
            if (ptrConversor != termino && *ptrConversor == '\0') // Verificación si termino es float
            {
                pushItem(stackCalculadora, sizeof(float), &Num);
            }
            else
            {
                if (strcmp(termino, "q") == 0 || strcmp(termino, "Q") == 0) // Verificación salida
                {
                    liberarStack(stackCalculadora);
                    exit(0);
                }

                float *num2 = (float *)popItem(stackCalculadora);
                float *num1 = (float *)popItem(stackCalculadora);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Error: Faltan operandos en la pila\n");
                    if (num1 != NULL)
                    {
                        pushItem(stackCalculadora, sizeof(float), num1); // Devolver num1 a la pila si se sacó
                    }
                    if (num2 != NULL)
                    {
                        pushItem(stackCalculadora, sizeof(float), num2); // Devolver num2 a
                    }
                    break;
                }
                else if (strcmp(termino, "*") == 0) // verificación multiplicación
                {
                    resultado = (*num1) * (*num2);
                    pushItem(stackCalculadora, sizeof(float), &resultado);
                }
                else if (strcmp(termino, "/") == 0) // verificación multiplicación
                {
                    if (*num2 == 0) // Verificación división por cero
                    {
                        printf("Error: División por cero\n");
                        pushItem(stackCalculadora, sizeof(float), num1); // Devolver num1 a la pila si se sacó
                        break;
                    }
                    resultado = (*num1) / (*num2); // verificación división
                    pushItem(stackCalculadora, sizeof(float), &resultado);
                }
                else if (strcmp(termino, "+") == 0) // verificación suma
                {
                    resultado = (*num1) + (*num2);
                    pushItem(stackCalculadora, sizeof(float), &resultado);
                }
                else if (strcmp(termino, "-") == 0) // verificación resta
                {
                    resultado = (*num1) - (*num2);
                    pushItem(stackCalculadora, sizeof(float), &resultado);
                }
            }

            termino = strtok(NULL, " \n"); // pedir siguiente termino
        }
    } while (1);
}