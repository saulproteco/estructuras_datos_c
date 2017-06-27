#ifndef _ARBOL_BINARIO_BUSQUEDA_H
#define _ARBOL_BINARIO_BUSQUEDA_H

#include <stdint.h>
#include <stdbool.h>

typedef int32_t Tipo;

typedef struct nodo Nodo;
struct nodo {
    Tipo dato;
    struct nodo * hijoIzq;
    struct nodo * hijoDer;
    struct nodo * padre;
}

typedef struct bst ArbolBinario;
struct bst {
    Nodo * raiz;

    int32_t niveles;
    int32_t numero_elementos;
};

ArbolBinario * nuevoArbol(void);
void eliminarArbol(ArbolBinario * arbol);

bool insertar(ArbolBinario * arbol, Tipo elemento);
bool eliminar(ArbolBinario * arbol, Tipo * sacado);

bool existe(ArbolBinario * arbol, Tipo elemento);

void imprimirPreOrden(Nodo * nodo_arbol);
void imprimirPosOrden(Nodo * nodo_arbol);
void imprimirInOrden(Nodo * nodo_arbol);

#endif /* _ARBOL_BINARIO_BUSQUEDA_H */
