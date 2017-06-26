#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola_estatica/colae.h"

enum opciones {
    NUEVO_CLIENTE = 1,
    ATENDER_CLIENTE,
    CERRAR_TIENDA
};

const char * PRODUCTO[] = {
    "unos doritos nacho",
    "una caja de galletas",
    "una barra snikers",
    "una bolsa de jabOn 1/2",
    "un surtido rico",
    "una caja de korn flakes",
    "una revista 'muy interesante'",
    "13 piezas de pan blanco",
    "algo que no te puedo mencionar",
    "4 six mAs un tonayan",
    "un litro de leche"
};

#define NUM_PRODUCTOS (sizeof(PRODUCTO) / sizeof(void *))

/*
 * En este super se limita el nUmero de personas
 * que se pueden formar en una sola caja para evitar
 * desorden
 */

#define MAX_PERSONAS 10
#define MAX_NOMBRE   100

void menu(void);
int32_t leerEntero(int32_t min, int32_t max);
char * leerCadena(void);
void cerrar(ColaEstatica * fila);

bool establecimientoAbierto;

int main(void) {
    int opcion;
    char * nombre;

    ColaEstatica * fila_personas = nuevaCola(MAX_PERSONAS);
    if (!fila_personas) {
        fprintf(stderr, "Lo sentimos, el sistema del mercado se ha caido\n");
    }

    establecimientoAbierto = true;
    printf("La tienda acaba de abrir\n");

    while (establecimientoAbierto) {
        menu();
        opcion = leerEntero(1, 3);

        switch (opcion) {
            case NUEVO_CLIENTE:
                if (estaLlena(fila_personas)) {
                    puts("Lo sentimos, la fila es muy grande");
                    break;
                }

                puts("Ingrese el nombre de nuevo cliente:\n");
                nombre = leerCadena();

                if (!nombre) {
                    cerrar(fila_personas);
                    break;
                }

                insertar(fila_personas, nombre);
                puts("Una nueva persona se ha aniadido correctamente");

                break;
            case ATENDER_CLIENTE:
                if (estaVacia(fila_personas)) {
                    puts("La fila estA vacia, no hay a quien atender");
                    break;
                }

                eliminar(fila_personas, &nombre);
                printf("El cilente %s ha sido atendido, comprO %s\n",
                        nombre, PRODUCTO[rand() % NUM_PRODUCTOS]);

                free(nombre);
                break;
            case CERRAR_TIENDA:
                printf("La tienda cierra ahora, los clientes restantes"
                        "se quedan sin ser atendidos\n");
                cerrar(fila_personas);
                break;

            default:
                fprintf(stderr, "Esto jamAs deberia pasar D:\n");
                exit(EXIT_FAILURE);
                break;
        }
    }

    return EXIT_SUCCESS;
}

void menu(void) {
    puts("QuE operaciOn desea hacer?\n");

    puts("\t1) Pasar una nueva persona al final de la cola.");
    puts("\t2) Atender a una persona.");
    puts("\t3) Cerrar el establecimiento.");
}

void cerrar(ColaEstatica * fila) {
    char * nombre;
    while (!estaVacia(fila)) {
        eliminar(fila, &nombre);

        printf("%s se ha quedado sin ser atendido\n", nombre);

        free(nombre);
    }

    establecimientoAbierto = false;
}

int32_t leerEntero(int32_t min, int32_t max) {
    int auxiliar;

    // No se debe leer con %d un int32_t por posible
    // inequivalencia de tamanio
    while (scanf("%d", &auxiliar) || auxiliar < min || auxiliar > max)
        scanf("%*[^\n]%*c");

    return (int32_t)auxiliar;
}

char * leerCadena(void) {
    char espacio[MAX_NOMBRE];
    char * cadena_leida;
    int largo_cadena_leida;

    fgets(espacio, MAX_NOMBRE, stdin);
    largo_cadena_leida = strlen(espacio);

    if (espacio[largo_cadena_leida - 1] == '\n')
        espacio[--largo_cadena_leida] = '\0';

    cadena_leida = malloc(sizeof(char) * largo_cadena_leida);

    if (!cadena_leida) {
        fprintf(stderr, "El supermercado se ha quedado sin papel para"
                " escribir el nombre del cliente\n");
        return NULL;
    }

    strcpy(cadena_leida, espacio);

    return cadena_leida;
}
