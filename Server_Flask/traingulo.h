#ifndef TRIANGULO_H
#define TRIANGULO_H

// Definición de la estructura triangulo
struct Triangulo {
    float lado1;
    float lado2;
    float lado3;
};

// Prototipo de función para imprimir un triangulo
void imprimirTriangulo(struct Triangulo *t);

#endif