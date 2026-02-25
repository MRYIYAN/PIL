// PUNTEROS Y ARRAYS CLASE 26/02/2026

#include <stdio.h>

int main(void)
{
    int arr[10], *ptr;
    unsigned i;

    arr[0] = 1; arr[1] = 5; arr[2] = -2; arr[3] = 7; arr[4] = 3;
    arr[5] = 9; arr[6] = -4; arr[7] = 12; arr[8] = -5; arr[9] = 15;

    ptr = arr; // ptr apunta al primer elemento del array

    printf("\n\nArreglo:\n");

    for (i = 0; i < 10; i++) {
        printf("%d\n", *(ptr + i)); // Imprime el valor al que apunta ptr
    }

    return 0;
}
