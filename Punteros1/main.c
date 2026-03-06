#include <stdio.h>
#include <stdlib.h>

#define TAMINT sizeof(int)   // TAMINT guarda el tamaño en bytes de un entero

int main()
{
    int *principio;   // Puntero que apuntará al inicio del arreglo dinámico
    int value;        // Variable donde se guarda cada número ingresado
    int n = 0;        // Contador de cuántos números se han guardado

    register unsigned k; 
    // Variable declarada en registro (más rápida en teoría)
    // No se usa en el programa

    /* ==========================
       1) PRIMERA RESERVA DE MEMORIA
       ========================== */

    // Se reserva memoria para 1 entero
    principio = (int *)malloc(TAMINT);

    // Si malloc devuelve NULL significa que no hay memoria disponible
    if (principio == NULL) {
        printf("\n\nNo hay memoria disponible...");
        exit(1);   // Finaliza el programa con código de error
    }

    /* ==========================
       2) INGRESO DE DATOS
       ========================== */

    do {

        // Se pide un número al usuario
        printf("\nIngrese un numero entero: ");
        scanf("%d", &value);

        // Se guarda el número en la posición actual del array
        // *(principio + n) es equivalente a principio[n]
        principio[n] = value;

        // Se incrementa el contador
        n++;

        /* =======================================
           3) AUMENTAR EL TAMAÑO DEL ARRAY
           ======================================= */

        // Se aumenta el tamaño del arreglo para que tenga espacio
        // para un entero adicional (n + 1 posiciones)
        principio = (int *)realloc(principio, (n + 1) * TAMINT);

        // Si realloc falla
        if (principio == NULL) {
            printf("\n\nNo hay memoria disponible...");
            exit(2);
        }


    } while (value != -999);  
    // El ciclo continúa mientras el número sea diferente de -999
    // IMPORTANTE: el -999 también se guarda en el arreglo

    /* ==========================
       4) AJUSTE FINAL
       ========================== */

    // Se ajusta el tamaño del arreglo exactamente a n enteros
    principio = (int *)realloc(principio, n * TAMINT);

    if (principio == NULL) {
        printf("\n\nNo hay memoria disponible...");
        exit(3);
    }

    for (k = 0; k < n; k++) {
        printf("%d\n", principio[k]); // Imprime cada número ingresado
    
        printf("\n\n"); // Imprime una línea en blanco entre números

    // Se libera la memoria reservada
    free(principio);

    return 0;
    }
}