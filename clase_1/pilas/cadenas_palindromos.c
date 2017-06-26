#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pila_dinamica/pilad.h"

#define TAMANIO_CADENA 100

char * invertirCadena(char * cadena);

PilaDinamica * pila_caracteres;

int main(void) {
    pila_caracteres = nuevaPila();

    bool continuar;
    char cadena[TAMANIO_CADENA];
    char * invertida;

    do {
        printf("\nIngrese una cadena para determinar si es un palindromo:\n");

        fgets(cadena, TAMANIO_CADENA, stdin);
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
    return EXIT_SUCCESS;
}

char * invertirCadena(char * cadena) {
    int32_t longitud = strlen(cadena);
    char * invertida = malloc(longitud + 1);

    if (!invertida) {
        perror("Error de asignacion:");
        exit(EXIT_FAILURE);
    }

    for (int32_t i = 0; i < longitud; i++)
        insertar(pila_caracteres, cadena[i]);

    for (int32_t i = 0; i < longitud; i++) {
        char caracter_sacado;
        eliminar(pila_caracteres, &caracter_sacado);
        invertida[i] = caracter_sacado;
    }
    invertida[longitud] = '\0';

    return invertida;
}
