
/*-* Bibliotecas que no necesitan conocerse publicamente *-*/
#include "colad.h"
#include <stdlib.h>

/*-* Constructor / Destructor *-*/
ColaDinamica * nuevaCola(void) {
    return calloc(1, sizeof(ColaDinamica));
}

void borrarCola(ColaDinamica * cola) {
    Tipo elemento;
    while (!estaVacia(cola)) {
        eliminar(cola, &elemento);
    }

    free(cola);
}

/*-* Funciones que modifican los datos *-*/
bool insertar(ColaDinamica * cola, Tipo elemento) {
    Nodo * nuevo_nodo = calloc(1, sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;

    if (estaVacia(cola)) {
        cola->primero = cola->ultimo = nuevo_nodo;
    } else {
        cola->ultimo->siguiente = nuevo_nodo;
        cola->ultimo = nuevo_nodo;
    }


    cola->numero_elementos++;
    return true;
}

bool eliminar(ColaDinamica * cola, Tipo * sacado) {
    Nodo * auxiliar = cola->primero;

    if (estaVacia(cola))
        return false;

    cola->primero = auxiliar->siguiente;
    free(auxiliar);

    cola->numero_elementos--;
    return true;
}

/*-* Auxiliares de uso rApido (en lInea para mayor eficiencia) *-*/
inline Tipo checar(const ColaDinamica * cola) {
    return cola->primero->dato;
}

inline bool estaVacia(const ColaDinamica * cola) {
    return cola->numero_elementos == 0;
}
