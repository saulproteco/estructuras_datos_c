#include <stdlib.h>
#include <stdbool.h>

typedef int Tipo;
#define VALOR_DEFECTO 0

typedef struct nodo Nodo;
struct nodo {
    Tipo dato;
    struct nodo * siguiente;
};

typedef struct pilad Pila;
struct pilad {
    Nodo * tope;
    int num_elementos;
};

Pila * nuevaPila(void);
void  borrarPila(Pila * pila);

bool insertar(Pila * pila, Tipo elemento);
bool eliminar(Pila * pila, Tipo * sacado);

bool estaVacia(Pila * pila);
