#include <stdbool.h>
#include <stdint.h>

typedef int32_t Tipo;

typedef struct lnodo Nodo;
struct lnodo {
    Tipo dato;
    Nodo * siguiente;
};

typedef struct listals ListaSimple;
struct listals {
    Nodo * primero;
    Nodo * ultimo;

    int32_t numero_elementos;
};

ListaSimple * nuevaLista(void);
void eliminarLista(ListaSimple * lista);

bool insertarPrincipio(ListaSimple * lista, Tipo elemento);
bool eliminarPrimero(ListaSimple * lista, Tipo * elemento);

bool insertarFinal(ListaSimple * lista, Tipo elemento);
bool eliminarUltimo(ListaSimple * lista, Tipo * elemento);

bool insertar(ListaSimple * lista, Tipo elemento, int posicion);
bool eliminar(ListaSimple * lista, Tipo * elemento, int posicion);

int32_t indice (ListaSimple * lista, Tipo elemeno);
extern int32_t comparar(Tipo elemento1, Tipo elemento2);
extern bool estaVacia(ListaSimple * lista);
