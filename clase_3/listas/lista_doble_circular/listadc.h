#ifndef _LISTA_DOBLE_CIRCULAR_H
#define _LISTA_DOBLE_CIRCULAR_H

#include <stdbool.h>

typedef int Tipo;

typedef struct lcnodo Nodo;
struct lcnodo {
    Tipo dato;

    Nodo * anterior;
    Nodo * siguiente;
};

typedef struct listadb ListaCircular;
struct listadb {
    Nodo * primero;
    Nodo * ultimo;

    int numero_elementos;
    bool ordenado;
};

ListaCircular * nuevaLista(void);
void eliminarLista(ListaCircular * lista);

bool insertarPrincipio(ListaCircular * lista, Tipo elemento);
bool eliminarPrimero(ListaCircular * lista, Tipo * sacado);

bool insertarFinal(ListaCircular * lista, Tipo elemento);
bool eliminarUltimo(ListaCircular * lista, Tipo * sacado);

bool insertar(ListaCircular * lista, Tipo elemento, int posicion);
bool eliminar(ListaCircular * lista, Tipo * sacado, int posicion);

void ordenarAscendente(ListaCircular * lista);
void ordenarDescendente(ListaCircular * lista);

bool existe(ListaCircular * lista, Tipo elemeno);
extern int comparar(Tipo elemento1, Tipo elemento2);
extern bool estaVacia(ListaCircular * lista);

#endif // _LISTA_DOBLE_CIRCULAR_H
