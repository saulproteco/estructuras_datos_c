/*========================================================*
 * COdigo fuente para hacer uso de colas de tamanio       *
 * estAtico dentro del lenguaje C.                        *
 *========================================================*/

/*-* Bibliotecas que no requieren verse publicamente *-*/
#include "colae.h"
#include <stdlib.h>

/*-* Constructor / Destructor *-*/
ColaEstatica * nuevaCola(int32_t tamanio) {
    if (tamanio < 0)
        return NULL;

    ColaEstatica * nueva_cola = calloc(1, sizeof(ColaEstatica));

    if (!nueva_cola)
        return NULL;

    nueva_cola->elementos = calloc(tamanio, sizeof(Tipo));

    if (!nueva_cola->elementos) {
        free(nueva_cola);
        return NULL;
    }

    nueva_cola->tamanio = tamanio;
    nueva_cola->estaVacia = true;

    return nueva_cola;
}

void borrarCola(ColaEstatica * cola) {
    free(cola->elementos);
    free(cola);
}

/*-* Funciones que modifican los datos *-*/
bool insertar(ColaEstatica * cola, Tipo elemento) {
    if (estaLlena(cola))
        return false;

    cola->elementos[cola->fin] = elemento;
    cola->fin = (cola->fin + 1) % cola->tamanio;

    cola->estaVacia = false;

    if (cola->inicio == cola->fin)
        cola->estaLlena = true;

    return true;
}

bool eliminar(ColaEstatica * cola, Tipo * sacado) {
    if (estaVacia(cola))
        return false;

    *sacado = cola->elementos[cola->inicio];
    cola->inicio = (cola->inicio + 1) % cola->tamanio;

    cola->estaLlena = false;

    if (cola->inicio == cola->fin)
        cola->estaVacia = true;

    return true;
}

/*-* Auxiliares de uso rApido *-*/
Tipo checar(const ColaEstatica * cola) {
    return cola->elementos[cola->inicio];
}

inline bool estaLlena(const ColaEstatica * cola) {
    return cola->estaLlena;
}

inline bool estaVacia(const ColaEstatica * cola) {
    cola->estaVacia;
}
