#include <stdio.h>

typedef struct {
    unsigned ID;
    double x,y;
} punto2D;


typedef struct {
    unsigned i;
    double z;
    unsigned j; 
}miest;

void main(void) 
{

    int x, *ptr1, *ptr2;
    x = 5;
    ptr1 = &x;

    printf("\n integer: %u bytes\n", sizeof(int));
    printf("\n unsigned integer: %u bytes\n", sizeof(unsigned));
    printf("\n long long integer: %u bytes\n", sizeof(long long));
    printf("\n float: %u bytes\n", sizeof(float));
    printf("\n double: %u bytes\n", sizeof(double));
    printf("\n char: %u byte\n", sizeof(char));
    printf("\n int*: %u byte\n", sizeof(int *));
    printf("\n char*: %u byte\n", sizeof(char *));
    printf("\n float*: %u byte\n", sizeof(float *));
    printf("\n double*: %u byte\n", sizeof(double *));
    printf("\n punto2D: %u bytes\n", sizeof(punto2D));
    printf("\n miest: %u bytes\n", sizeof(punto2D));
    printf("\n memory addresses ptr1, ptr2, x: %p - %p - %p - %d\n",
           ptr1, ptr2, &x, *ptr1);

    return 0;
}