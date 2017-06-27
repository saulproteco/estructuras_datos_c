#ifndef _CONFN_H
#define _CONFN_H

// Como estas funciones no son compatibles entre windows y linux
// se definirAn de manera condicional segUn el sistema

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32   // Desde aquI empiezan las definiciones para windows

// Letras minusculas acentuadas
#define A "\xA0"
#define E "\x82"
#define I "\xA1"
#define O "\xA2"
#define U "\xA3"
#define N "\xA4"

// Signo de interrogaciOn inicial
#define IN  "\xa8"

// Signo de exclamaciOn inicial
#define EX  "\xAD"

#include <windows.h>
#include <conio.h>

#define WIN32_LEAN_AND_MEAN

#define CLEAR "cls"

static void (*manejador_seniales)(int senial) = NULL;

static BOOL ManejadorSeniales(DWORD tipo_senial) {
    if (tipo_senial == CTRL_C_EVENT) {
        manejador_seniales(0);
        return TRUE;
    }

    return FALSE;
}

void Iniciar(void * manejador) {
    srand(time(NULL));

    manejador_seniales = manejador;
    if ( !SetConsoleCtrlHandler((PHANDLER_ROUTINE)manejador, TRUE) )
        exit(1);

    CONSOLE_CURSOR_INFO cci = { 100, false }; // Ocultar cursor

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    system(CLEAR);
}

void Terminar(void) {
    CONSOLE_CURSOR_INFO cci = { 100, true }; // Regresa el cursor

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

    system(CLEAR);
}

void Dormir(int milisegundos) {
    Sleep(milisegundos);
}

char ObtenerCaracter(void) {
    return getch();
}

bool SePresionoTecla(void) {
    return kbhit();
}

void MoverseAXY(int x, int y) {
    COORD pos;

    pos.X = x - 1;
    pos.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#else           // Desde aquI empiezan las definiciones para linux/unix/mac

// Letras minusculas
#define A "\u00E1"
#define E "\u00E9"
#define I "\u00ED"
#define O "\u00F3"
#define U "\u00FA"
#define N "\u00F1"

// Signo de pregunta abierto
#define IN  "\u00BF"

// Signo de exclamaciOn inicial
#define EX  "\u00A1"

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define CLEAR "clear"

static struct termios terminal_normal, terminal_configurada;

void Iniciar(void * funcion_manejadora) {
    system(CLEAR);
    srand(time(NULL));
    tcgetattr(0, &terminal_normal);
    signal(SIGINT, funcion_manejadora);

    terminal_configurada = terminal_normal;

    // Desactivamos la entrada con buffer y el echo (ya no se muestran
    // los caracteres que escribes)
    terminal_configurada.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(0, TCSANOW, &terminal_configurada);
}

void Terminar(void) {

    tcsetattr(0, TCSANOW, &terminal_normal);
    system(CLEAR);
}

void Dormir(int milisegundos) {
    usleep(milisegundos * 1000);
}

char ObtenerCaracter(void) {
    return getchar();
}

bool SePresionoTecla(void) {
    int formato_control;
    int c;

    formato_control = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, formato_control | O_NONBLOCK);

    c = getchar();

    fcntl(STDIN_FILENO, F_SETFL, formato_control);

    if ( c != EOF ) {
        ungetc(c, stdin);
        return 1;
    }


    return 0;
}

void MoverseAXY(int x, int y) {
    printf("\e[%d;%df", y, x);
}

#endif

void LimpiarPantalla(void) {
    system(CLEAR);
}

#endif // _CONFN_H
