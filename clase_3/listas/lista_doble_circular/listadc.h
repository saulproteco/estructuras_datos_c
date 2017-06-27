#include <stdbool.h>
#include <stdint.h>

typedef int32_t Tipo;

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

    int32_t numero_elementos;
};

ListaCircular * nuevaLista(void);
void eliminarLista(ListaCircular * lista);

bool insertarPrincipio(ListaCircular * lista, Tipo elemento);
bool eliminarPrimero(ListaCircular * lista, Tipo * elemento);

bool insertarFinal(ListaCircular * lista, Tipo elemento);
bool eliminarUltimo(ListaCircular * lista, Tipo * elemento);

bool insertar(ListaCircular * lista, Tipo elemento, int posicion);
bool eliminar(ListaCircular * lista, Tipo * elemento, int posicion);

bool existe(ListaCircular * lista, Tipo elemeno);
extern int32_t comparar(Tipo elemento1, Tipo elemento2);
extern bool estaVacia(ListaCircular * lista);
