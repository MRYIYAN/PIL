#include <stdio.h>
#define MAXTAM 10

void ptrarray(int *arr)
{
    unsigned k;

    printf("\n\nArreglo:\n");
    for (k = 0; k < MAXTAM; k++) {
        printf("%d\n", arr[k]); // Imprime el valor del arreglo
    }
}
