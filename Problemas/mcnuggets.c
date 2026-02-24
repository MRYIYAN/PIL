//==============================================================//
// PRACTICA - PROBLEMA DE LOS MCNUGGETS (Uso wsl por si tiene problemas con los saltos de linea)
//==============================================================//
//
// En este ejercicio queremos saber si se pueden formar
// todos los numeros usando cajas de 6, 9 y 20 nuggets.
//
// La idea que he usado es probar muchas combinaciones
// hasta ver si el numero sale exacto.
//
// Si no se puede formar, lo mostramos.
// Tambien guardo el mayor numero que no se puede formar.
//
// Seguro que hay una forma mas inteligente pero asi funciona es mas sencillo
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

    int numero;             // numero que estamos comprobando
    int i, j, k;            // contadores para las cajas
    int sePuede;            // 0 = no, 1 = si
    int maxNoFormable = 0;  // guardo el mayor que no se puede
    int limite = 200;       // limite que vamos a revisar

    printf("Numeros que NO se pueden formar con cajas de 6, 9 y 20:\n\n");

    //----------------------------------------------------------//
    // Recorremos todos los numeros desde 1 hasta el limite
    //----------------------------------------------------------//

    for(numero = 1; numero <= limite; numero++) {

        sePuede = 0;  // al principio supongo que no se puede

        //------------------------------------------------------//
        // Aqui pruebo combinaciones
        // voy probando cuantas cajas de 6, 9 y 20 usar
        //------------------------------------------------------//

        for(i = 0; i <= numero / 6; i++) {

            for(j = 0; j <= numero / 9; j++) {

                for(k = 0; k <= numero / 20; k++) {

                    // si la suma da justo el numero entonces si se puede
                    if(6*i + 9*j + 20*k == numero) {
                        sePuede = 1;
                    }
                }
            }
        }

        //------------------------------------------------------//
        // Si despues de probar todo no se pudo formar
        //------------------------------------------------------//

        if(sePuede == 0) {

            printf("%d ", numero);

            // lo guardo por si es el mas grande hasta ahora
            maxNoFormable = numero;
        }
    }

    //----------------------------------------------------------//
    // Resultado final
    //----------------------------------------------------------//

    printf("\n\nEl mayor numero que no se puede formar (en este rango) es: %d\n", maxNoFormable);

    return 0;
}