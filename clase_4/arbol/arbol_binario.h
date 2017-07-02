#ifndef _ARBOL_BINARIO_BUSQUEDA_H
#define _ARBOL_BINARIO_BUSQUEDA_H

#include <stdint.h>
#include <stdbool.h>

typedef int32_t Tipo;

typedef struct nodo Nodo;
struct nodo {
    Tipo dato;

    // Apuntadores a padre e hijos
    struct nodo * padre;
    struct nodo * hijoIzq;
    struct nodo * hijoDer;
};

typedef struct arbolb ArbolBinario;
struct arbolb {
    Nodo * raiz;

    int32_t numero_elementos;
};

ArbolBinario * nuevoArbol(void);
void liberarArbol(ArbolBinario * arbol);

Nodo * nuevoNodo(Tipo dato);
void liberarNodosRecursivo(Nodo * nodo);

bool insertar(ArbolBinario * arbol, Tipo elemento);
bool insertarRecursivo(Nodo * raiz, Tipo elemento);

bool eliminar(ArbolBinario * arbol, Tipo a_sacar);
bool eliminarRecursivo(Nodo * raiz, Tipo a_sacar);

bool existe(ArbolBinario * arbol, Tipo elemento);

void imprimirPreOrden(Nodo * nodo_arbol);
void imprimirPosOrden(Nodo * nodo_arbol);
void imprimirInOrden(Nodo * nodo_arbol);

extern bool estaVacio(const ArbolBinario * arbol);

#endif /* _ARBOL_BINARIO_BUSQUEDA_H */
