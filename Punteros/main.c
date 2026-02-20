#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main()
{
    punto2D punto1, punto2, punto3;
    punto2D *ptr_pt1, *ptr_pt2;
    punto2D *ptr_pt3;
    triangulo T, *ptr_triang;

    ptr_pt1 = &punto1;
    ptr_pt2 = &punto2;
    ptr_pt3 = &punto3;

    ptr_triang = &T;

    punto1.ID = 1;
    punto1.x = 0.0; punto1.y = 0.0;
    punto2.ID = 2;
    punto2.x = 2.0; punto2.y = 0.0;
    punto3.ID = 3;
    punto3.x = 1.0; punto3.y = 1.0;

    T.ID = 1;
    T.nodo1 = *ptr_pt1;
    T.nodo2 = *ptr_pt2;
    T.nodo3 = *ptr_pt3;

    printf("\n\n");
    printf("Tri\xA0ngulo:");
    printf(" ID = %d",(*ptr_triang).ID); //printf(" ID = %d",ptr_triang ->ID);
    printf("\n vertice 1: (%lf, %lf ", ptr_triang ->nodo1.x,ptr_triang ->nodo1.y);
    printf("\n vertice 2: (%lf, %lf ", ptr_triang ->nodo2.x,ptr_triang ->nodo2.y);
    printf("\n vertice 3: (%lf, %lf ", ptr_triang ->nodo3.x,ptr_triang ->nodo3.y);

    return 0;
}