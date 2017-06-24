#include <stdio.h>
#include <string.h>
#include "pilad.h"

char * invertirCadena(char * cadena);

Pila * pila_caracteres;

int main(void) {
    pila_caracteres = nuevaPila();

    bool continuar;
    char cadena[100];
    char * invertida;

    do {
        printf("\nIngrese una cadena para determinar si es un palindromo:\n");

        fgets(cadena, 100, stdin);
        if (cadena[strlen(cadena) - 1] == '\n')
            cadena[strlen(cadena) - 1] = '\0';

        invertida = invertirCadena(cadena);

        if (strcmp(cadena, invertida) == 0)
            printf("La cadena es un palindromo\n");
        else
            printf("La cadena no es un palindromo\n");

        printf("\nPresione una tecla para continuar . . .\n");
        getchar();

        free(invertida);

        printf("Desea probar otra vez ?, presione 1\n");
        fgets(cadena, 100, stdin);
        continuar = strstr(cadena, "1");
    } while (continuar);

    printf("Vuelva pronto :)\n");
    return 0;
}

char * invertirCadena(char * cadena) {
    int longitud = strlen(cadena);
    char * invertida = malloc(longitud + 1);

    if (!invertida) {
        perror("Error de asignacion:");
        exit(1);
    }

    for (int i = 0; i < longitud; i++)
        insertar(pila_caracteres, cadena[i]);

    for (int i = 0; i < longitud; i++) {
        char caracter_sacado;
        eliminar(pila_caracteres, &caracter_sacado);
        invertida[i] = caracter_sacado;
    }
    invertida[longitud] = '\0';

    return invertida;
}
