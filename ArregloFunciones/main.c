#include <stdio.h>
#define MAXTAM 10

void ptrarray(int *);
void ptrsubarray(int *);

int main(void)
{
    int arr[MAXTAM] 
;
    arr[0] = 5; arr[1] = 9; arr[2] = 7; arr[3] = -1; arr[4] = -8;
    arr[5] = 4; arr[6] = 0; arr[7] = 3; arr[8] = 1; arr[9] =9;

    ptrarray(arr);
    ptrsubarray(arr);

    return 0;
}