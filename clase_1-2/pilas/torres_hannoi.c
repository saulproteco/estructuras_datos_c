#include <stdio.h>
#include "pilae.h" // Cabecera de la pila estAtica

#define ALTURA_MAXIMA 5

int leerEntero(int min, int max);
void jugar(int tamanio_torres);
void imprimirTorres(PilaEstatica ** torre);
bool movimientoValido(PilaEstatica ** torre, int origen, int destino);

int main(void) {
    int altura;
    printf("Elija la altura para jugar (2-5): ");
    altura = leerEntero(2, 5);

    jugar(altura);

    printf("Felicidades, has ganado el juego de las "
            "torres de hannoi con %d discos\n", altura);
    return 0;
}

void jugar(int tamanio_torres) {
    PilaEstatica * torre[3];

    for (int i = 0; i < 3; i++) torre[i] = nuevaPila(tamanio_torres);

    for (int i = tamanio_torres; i >= 1; i--)
        insertar(torre[0], i);

    printf("\n");

    bool ganado = false;
    int origen, destino;
    int disco;

    while (!ganado) {
        imprimirTorres(torre);

        printf("De quE torre quiere sacar el disco (1-3)\n");
        origen = leerEntero(1, 3) - 1;

        printf("A quE torre lo quiere mover (1-3)\n");
        destino = leerEntero(1, 3) - 1;

        if (movimientoValido(torre, origen, destino)) {
            eliminar(torre[origen], &disco);
            insertar(torre[destino], disco);
            printf("Movimiento exitoso\n");
        } else {
            printf("Movimiento invAlido\n");
        }

        ganado = (estaLlena(torre[2]));
    }

    for (int i = 0; i < 3; i++) borrarPila(torre[i]);
}

void imprimirTorres(PilaEstatica ** torre) {
    for (int j = (*torre)->tamanio - 1; j >= 0; j--) {
        for (int i = 0; i < 3; i++) {
            printf("| %c |\t", torre[i]->elementos[j] ?
                    torre[i]->elementos[j] + '0' : ' ');
        }
        putchar('\n');
    }
}

bool movimientoValido(PilaEstatica ** torre, int origen, int destino) {
    if (estaVacia(torre[origen]))
        return false;

    if (estaVacia(torre[destino]))
        return true;

    if (checar(torre[origen]) < checar(torre[destino]))
        return true;

    return false;
}

int leerEntero(int min, int max) {
    int auxiliar;
    while ( scanf("%d", &auxiliar) == 0 || auxiliar < min || auxiliar > max )
        scanf("%*[^\n]%*c");

    return auxiliar;
}
