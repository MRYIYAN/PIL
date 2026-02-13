//==============================================================//
// PRACTICA - NUMEROS PERFECTOS
//==============================================================//
//
// Este programa lo que hace es:
// 1. Pedir un numero
// 2. Buscar sus divisores menores que el
// 3. Sumarlos
// 4. Decir si es perfecto, abundante o deficiente
//
// He añadido una validacion sencilla para que no meta cosas raras.
// Tambien se repite hasta que el usuario quiera salir.
// Seguro que se puede hacer mejor pero asi funciona.
//
//--------------------------------------------------------------//
// Librerias
//--------------------------------------------------------------//

#include <stdio.h>

//--------------------------------------------------------------//
// Programa principal
//--------------------------------------------------------------//

int main() {

    //----------------------------------------------------------//
    // Variables
    //----------------------------------------------------------//

    int numero;
    int i;
    int suma;
    char repetir;

    //----------------------------------------------------------//
    // Bucle principal para repetir el programa
    //----------------------------------------------------------//

    do {

        suma = 0;  // reiniciamos la suma cada vez

        //------------------------------------------------------//
        // Validacion basica del numero
        //------------------------------------------------------//

        printf("Introduce un numero entero positivo: ");

        // comprobamos que sea entero
        if(scanf("%d", &numero) != 1) {

            printf("Error, debes introducir un numero entero.\n");

            // limpiamos el buffer
            while(getchar() != '\n');

            continue;  // vuelve a pedir el numero
        }

        if(numero <= 0) {
            printf("El numero debe ser mayor que 0.\n");
            continue;
        }

        //------------------------------------------------------//
        // Buscamos divisores
        //------------------------------------------------------//

        printf("\nDivisores propios de %d: ", numero);

        for(i = 1; i < numero; i++) {

            if(numero % i == 0) {

                printf("%d ", i);
                suma = suma + i;
            }
        }

        //------------------------------------------------------//
        // Mostramos resultado
        //------------------------------------------------------//

        printf("\n\nLa suma de los divisores es: %d\n", suma);

        if(suma == numero) {

            printf("Es un numero Perfecto\n");

        } else if(suma > numero) {

            printf("Es un numero Abundante\n");

        } else {

            printf("Es un numero Deficiente\n");
        }

        //------------------------------------------------------//
        // Preguntamos si quiere repetir
        //------------------------------------------------------//

        printf("\nQuieres probar otro numero? (s/n): ");
        scanf(" %c", &repetir);

        printf("\n");

    } while(repetir == 's' || repetir == 'S');

    return 0;
}