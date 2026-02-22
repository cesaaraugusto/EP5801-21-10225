// Ubuntu 24.04.4 LTS x86_64
#include <stdio.h>
#include <string.h>

char string[100];
extern void asmprint(char *string, int longitud); // aviso de que la función será definida

int main()
{
    printf("Introduce una frase:\n");
    fgets(string, sizeof(string), stdin); // Obtenemos un string, asignamos tamaño a leer y la fuente de entrada
    int nCaracteres = strlen(string) - 1; // Obtenemos la longitud del string sin incluir el salto de línea
    asmprint(string, nCaracteres);        // Envío string a función asmprint, junto con su longitud
    return 0;
}