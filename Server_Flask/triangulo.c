#include <stdio.h>
#include "triangulo.h"

// Función que imprime un triángulo
// Se pasa por referencia (puntero) como suele pedir el profesor
void imprimirTriangulo(struct Triangulo *t) {

    printf("Lado 1: %.2f\n", t->lado1);
    printf("Lado 2: %.2f\n", t->lado2);
    printf("Lado 3: %.2f\n", t->lado3);
    printf("---------------------\n");
}