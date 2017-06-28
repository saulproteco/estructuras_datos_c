#include <stdio.h>

int main(void) {
    int a = 10;
    int b;

    b = a % 2 ? a < 5 ? a >= 5 ? 1 : 2 : 3 : 4;

    puts("CuAl es el valor de b?");

    printf("b es: %d\n", b);
    return 0;
}
