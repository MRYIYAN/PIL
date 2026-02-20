#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

    

double mif(double) 

int main()
{
    double x = 7.0, y;
    printf("antes de la llamada: x = %f\n", x);
    y = mif(&x);
    printf("despues de la llamada: y = %f\n", y);
    return 0;
}