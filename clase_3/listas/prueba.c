#include <stdio.h>
#include "lista_doble_circular/listadc.h"

int comparar(int num1, int num2);
void imprimirLista(ListaCircular * lista);

int main(void) {
    ListaCircular * lc = nuevaLista();

    insertarPrincipio(lc, 10);
    printf("Insertar 10 al principio\n");
    imprimirLista(lc);
    getchar();

    insertarPrincipio(lc, 20);
    printf("Insertar 20 al principio\n");
    imprimirLista(lc);
    getchar();

    insertarPrincipio(lc, 30);
    printf("Insertar 30 al principio\n");
    imprimirLista(lc);
    getchar();

    insertarPrincipio(lc, 40);
    printf("Insertar 40 al principio\n");
    imprimirLista(lc);
    getchar();

    insertarPrincipio(lc, 40);
    printf("Insertar 40 al principio\n");
    imprimirLista(lc);
    getchar();

    insertarPrincipio(lc, 50);
    printf("Insertar 50 al principio\n");
    imprimirLista(lc);
    getchar();

    insertarFinal(lc, 20);
    printf("Insertar 20 al final\n");
    imprimirLista(lc);
    getchar();

    insertarFinal(lc, 30);
    printf("Insertar 30 al final\n");
    imprimirLista(lc);
    getchar();

    insertarFinal(lc, 40);
    printf("Insertar 40 al final\n");
    imprimirLista(lc);
    imprimirLista(lc);
    getchar();

    insertarFinal(lc, 50);
    printf("Insertar 50 al final\n");
    imprimirLista(lc);
    getchar();

    insertar(lc, 2, 9);
    printf("Insertar 2 posicion 9\n");
    imprimirLista(lc);
    getchar();

    printf("Ordenar en forma ascendente: \n");
    ordenarAscendente(lc);
    imprimirLista(lc);
    getchar();

    printf("Ordenar en forma descendente: \n");
    ordenarDescendente(lc);
    imprimirLista(lc);
    getchar();

    // Eliminando elementos
    printf("Eliminar Ultimo: \n");
    int sacado;
    eliminarUltimo(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar Ultimo: \n");
    eliminarUltimo(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar Ultimo: \n");
    eliminarUltimo(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar Ultimo: \n");
    eliminarUltimo(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar Ultimo: \n");
    eliminarUltimo(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar primero: \n");
    eliminarPrimero(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar primero: \n");
    eliminarPrimero(lc, &sacado);
    imprimirLista(lc);
    getchar();

    printf("Eliminar posicion 2: \n");
    eliminar(lc, &sacado, 1);
    imprimirLista(lc);
    getchar();

    printf("Eliminar posicion 1: \n");
    eliminar(lc, &sacado, 1);
    imprimirLista(lc);
    getchar();

    printf("Eliminar posicion 0: \n");
    eliminar(lc, &sacado, 1);
    imprimirLista(lc);
    getchar();

    printf("Eliminar posicion 0: \n");
    eliminar(lc, &sacado, 0);
    imprimirLista(lc);
    getchar();

    eliminarLista(lc);

    return 0;
}

int comparar(int num1, int num2) {
    return num1 - num2;
}

void imprimirLista(ListaCircular * lista) {
    int i;
    Nodo * nodo_aux = lista->primero;

    printf("La lista es:\n");

    for (i = 1; i <= lista->numero_elementos; i++) {
        printf("| %d <- %d -> %d |\n", nodo_aux->anterior->dato, nodo_aux->dato, nodo_aux->siguiente->dato);
        nodo_aux = nodo_aux->siguiente;

    }

    putchar('\n');
}
