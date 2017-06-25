/*========================================================*
 * COdigo fuente para hacer uso de pilas de tamanio       *
 * dinAmico dentro del lenguaje C.                        *
 *========================================================*/

/*-* Bibliotecas que no requieren verse publicamente *-*/
#include "pilad.h"
#include <stdlib.h>

/*-* Constructor / Desctructor *-*/

PilaDinamica * nuevaPila(void) {
    return calloc(1, sizeof(PilaDinamica));
}

void  borrarPila(PilaDinamica * pila) {
    Tipo elemento;
    while (!estaVacia(pila))
        eliminar(pila, &elemento);

    free(pila);
}

/*-* Funciones que modifican los dAtos guardados *-*/

bool insertar(PilaDinamica * pila, Tipo elemento) {
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;

    pila->num_elementos++;
    return true;
}

bool eliminar(PilaDinamica * pila, Tipo * sacado) {
    if (estaVacia(pila))
        return false;

    Nodo * auxiliar = pila->tope;
    *sacado = auxiliar->dato;
    pila->tope = auxiliar->siguiente;

    free(auxiliar);

    pila->num_elementos--;
    return true;
}

/*-* Auxiliares de uso rApido *-*/

inline Tipo checar(const PilaDinamica * pila) {
    return pila->tope->dato;
}

inline bool estaVacia(const PilaDinamica * pila) {
    return pila->num_elementos == 0;
}
