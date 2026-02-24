//==============================================================//
// PRACTICA - HASH DEBIL (Uso wsl por si tiene problemas con los saltos de linea)
//==============================================================//
//
// En este ejercicio nos dan una funcion hash bastante simple.
// Lo unico que hace es sumar los valores ASCII de cada letra
// y al final hacer % 100.
//
// Entonces pense que si dos palabras tienen la misma suma,
// aunque esten en distinto orden, el hash va a ser el mismo.
//
// Por eso pruebo con "ab" y "ba", porque tienen las mismas
// letras pero cambiadas de posicion.
//
//--------------------------------------------------------------//
// Librerias
//--------------------------------------------------------------//

#include <stdio.h>

//--------------------------------------------------------------//
// Funcion hash
//--------------------------------------------------------------//

int hash(char *s) {

    int h = 0;  // aqui voy acumulando la suma
    int i = 0;  // contador para recorrer la cadena

    // Recorro la cadena caracter por caracter
    // hasta que encuentre el final 
    while(s[i] != '\0') {

        // voy sumando el valor ASCII de cada letra
        h = h + s[i];

        i++;  // paso al siguiente caracter
    }

    // al final devuelvo la suma modulo 100
    return h % 100;
}

//--------------------------------------------------------------//
// Programa principal
//--------------------------------------------------------------//

int main() {

    // Aqui defino dos cadenas distintas pero que tienen las mismas letras
    char cadena1[] = "ab";
    char cadena2[] = "ba";

    // Calculo el hash de cada una
    int hash1 = hash(cadena1);
    int hash2 = hash(cadena2);

    printf("Cadena 1: %s ---> Hash: %d\n", cadena1, hash1);
    printf("Cadena 2: %s ---> Hash: %d\n", cadena2, hash2);

    // Compruebo si los hash son iguales
    if(hash1 == hash2) {

        printf("\nColision encontrada!\n");
        printf("Son cadenas distintas pero mismo hash.\n");

    } else {

        printf("\nNo hay colision.\n");
    }

    return 0;
}