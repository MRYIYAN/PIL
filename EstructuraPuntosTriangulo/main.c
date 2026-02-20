#include <stdio.h>
#include <stdlib.h>
#include "def.h"

typedef struct {
    unsigned ID;
    double x,y;
} punto2D;

typedef struct {
    unsigned ID;
    punto2D *nodo1, *nodo2, *nodo3;
} triangulo;

punto2D punto1, punto2, punto3;
triangulo T; *ptr_triang = &T;


// Cambiar inicializacón de nodos a punteros a estructuras de tipo punto2D y triangulos

punto1.ID = 1; 
punto1.x = 0.0; punto1.y = 0.0;
punto2.ID = 2;
punto2.x = 2.0; punto2.y = 0.0;
punto3.ID = 3;
punto3.x = 1.0; punto3.y = 1.0;

T.ID = 1;
T.nodo1 = &punto1;
T.nodo2 = &punto2;
T.nodo3 = &punto3;                                            

// Area del triangulo

double area = 0.5 * (T.nodo1->x * (T.nodo2->y - T.nodo3->y) + 
                     T.nodo2->x * (T.nodo3->y - T.nodo1->y) + 
                     T.nodo3->x * (T.nodo1->y - T.nodo2->y));
printf("Area del triangulo: %f\n", area);
