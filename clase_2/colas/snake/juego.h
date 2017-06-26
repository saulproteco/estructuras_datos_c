#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#define BUFSIZE 65565
#define SHIFTED 0x8000

#include "colad.h"
#include <stdio.h>
#include <stdlib.h>

#define NOMBRE_VENTANA "Mi juego de snake"

#define TIEMPO_RETARDO  100
#define ALTO_VENTANA    720
#define ANCHO_VENTANA   720

#define DIVISIONES_PANTALLA 10.0f
#define ANCHO_RECUADRO      (1.0f / DIVISIONES_PANTALLA)

#define RVA(rojo, verde, azul) ((rojo) / 255.0f), ((verde) / 255.0f), ((azul) / 255.0f)
#define COOR_X(coor) ((coor.X) / DIVISIONES_PANTALLA)
#define COOR_Y(coor) ((coor.Y) / DIVISIONES_PANTALLA)

HINSTANCE hinst;
HHOOK hhk;

enum direccion {
    IZQUIERDA = 1,
    DERECHA,
    ARRIBA,
    ABAJO
};

ColaDinamica * serpiente;

enum direccion dir_actual = DERECHA;
enum direccion dir_siguiente = DERECHA;

struct {
    COORD posicion;
    BOOL existe;
} comida;

void actualizarImagen(HDC *);
void dibujarMuro(void);
void dibujarSerpiente(void);
void dibujarComida(void);

void actualizarJuego(BOOL *);
void movimiento(BOOL * juego_perdido);
void comprobar_colisiones(COORD, BOOL *);
void generarComida(void);

void actualizarImagen(HDC * hDC) {

    glClearColor(RVA(87, 90, 96), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    dibujarMuro();
    dibujarSerpiente();
    dibujarComida();

    SwapBuffers(*hDC);
}

void dibujarMuro(void) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(0.9f, -0.9f, -0.9f, 0.9f);
}

void dibujarSerpiente(void) {
    Nodo * auxiliar = serpiente->primero;
    glColor3f(RVA(44, 28, 188));

    while (auxiliar) {
        glRectf(COOR_X(auxiliar->dato), COOR_Y(auxiliar->dato),
                COOR_X(auxiliar->dato) + ANCHO_RECUADRO, COOR_Y(auxiliar->dato) + ANCHO_RECUADRO);
        auxiliar = auxiliar->siguiente;
    }
}

void dibujarComida(void) {
    glColor3f(RVA(128, 10, 10));

    glRectf(COOR_X(comida.posicion), COOR_Y(comida.posicion),
            COOR_X(comida.posicion) + ANCHO_RECUADRO,
            COOR_Y(comida.posicion) + ANCHO_RECUADRO);
}

void actualizarJuego(BOOL * juego_perdido) {
    movimiento(juego_perdido);
    generarComida();
}

void movimiento(BOOL * juego_perdido) {
    COORD auxiliar;

    dir_actual = dir_siguiente;

    eliminar(serpiente, &auxiliar);
    auxiliar = serpiente->ultimo->dato;

    switch (dir_actual) {
    case IZQUIERDA:
        auxiliar.X--;
        break;

    case DERECHA:
        auxiliar.X++;
        break;

    case ARRIBA:
        auxiliar.Y++;
        break;

    case ABAJO:
        auxiliar.Y--;
        break;
    default:
        fprintf(stderr, "Esto no deberia pasar nunca\n");
        exit(EXIT_FAILURE);
        break;
    }
    comprobar_colisiones(auxiliar, juego_perdido);

    insertar(serpiente, auxiliar);
}

void comprobar_colisiones(COORD nueva_posicion, BOOL * juego_perdido) {
    Nodo * aux = serpiente->primero;

    while (aux->siguiente) {
        if (nueva_posicion.X == aux->dato.X &&
            nueva_posicion.Y == aux->dato.Y) {
            *juego_perdido = TRUE;
            return;
        }
        aux = aux->siguiente;
    }

    if (nueva_posicion.X < -DIVISIONES_PANTALLA + 1 ||
        nueva_posicion.X >= DIVISIONES_PANTALLA - 1 ||
        nueva_posicion.Y < -DIVISIONES_PANTALLA + 1 ||
        nueva_posicion.Y >= DIVISIONES_PANTALLA - 1) {
        *juego_perdido = TRUE;
    }

    if ( nueva_posicion.X == comida.posicion.X &&
         nueva_posicion.Y == comida.posicion.Y ) {
		insertar(serpiente, nueva_posicion);
        comida.existe = false;
    }
}

void generarComida() {

    if (!comida.existe) {
        BOOL espacio_libre = FALSE;
        while (!espacio_libre) {
            Nodo * aux = serpiente->primero;

            espacio_libre = TRUE;
            comida.posicion.X = (rand() % 18) - 9;
            comida.posicion.Y = (rand() % 18) - 9;

            while (aux) {

                if ( comida.posicion.X == aux->dato.X &&
                     comida.posicion.Y == aux->dato.Y ) {
                    espacio_libre = FALSE;
                    break;
                }
                aux = aux->siguiente;
            }
        }
        comida.existe = TRUE;
    }
}

#endif // JUEGO_H_INCLUDED
