#include <stdio.h>
#include <stdlib.h>

float primerTermino;
float segundoTermino;
int estado;
char caracter;

int entradaNumero(int numero)
{
    do
    {
        printf("\033[s"); // Guardar posicion del cursor
        if (numero == 1)
        {
            estado = scanf("%f", &primerTermino);
        }
        else
        {
            estado = scanf("%f", &segundoTermino);
        }

        if (estado == 1) // Si se ingresa un numero
        {
            printf("\033[u");  // Restaurar cursor
            printf("\033[0J"); // Limpiar hacia abajo
            if (numero == 1)
            {
                printf("%.4f\n", primerTermino);
            }
            else
            {
                printf("%.4f\n", segundoTermino);
            }
            break;
        }
        else // Si no se ingresa un numero
        {
            scanf("%c", &caracter);
            if (caracter == 'q' || caracter == 'Q') // Si es caracter de salida
            {
                exit(0);
            }
            else // Si no es caracter de salida
            {
                printf("\033[u");  // Restaurar cursor
                printf("\033[0J"); // Limpiar hacia abajo
            }
        }
    } while (1);
}

int main()
{
    printf("\033[4mCalculadora (2 terminos) - Para salir presione q\033[0m\n");
    entradaNumero(1);
    entradaNumero(2);

    do
    {
        printf("\033[s"); // Guardar posicion del cursor
        printf("Ingrese un operador (+, -, *, /): ");
        scanf(" %c", &caracter);                // captura operador
        if (caracter == 'q' || caracter == 'Q') // Si es caracter de salida
        {
            exit(0);
        }
        else if (caracter == '+')
        {
            primerTermino = primerTermino + segundoTermino;
            system("cls");
            printf("\033[4mCalculadora (2 terminos) - Para salir presione q\033[0m\n");
            printf("%.4f\n", primerTermino);
            entradaNumero(2);
        }
        else if (caracter == '-')
        {
            primerTermino = primerTermino - segundoTermino;
            system("cls");
            printf("\033[4mCalculadora (2 terminos) - Para salir presione q\033[0m\n");
            printf("%.4f\n", primerTermino);
            entradaNumero(2);
        }
        else if (caracter == '*')
        {
            primerTermino = primerTermino * segundoTermino;
            system("cls");
            printf("\033[4mCalculadora (2 terminos) - Para salir presione q\033[0m\n");
            printf("%.4f\n", primerTermino);
            entradaNumero(2);
        }
        else if (caracter == '/')
        {
            if (segundoTermino != 0)
            {
                primerTermino = primerTermino * segundoTermino;
                system("cls");
                printf("\033[4mCalculadora (2 terminos) - Para salir presione q\033[0m\n");
                printf("%.4f\n", primerTermino);
                entradaNumero(2);
            }
            else
            {
                printf("\033[u");  // Restaurar cursor
                printf("\033[0J"); // Limpiar hacia abajo
            }
        }
        else // Si no es caracter de salida
        {
            printf("\033[u");  // Restaurar cursor
            printf("\033[0J"); // Limpiar hacia abajo
        }
    } while (1);
}