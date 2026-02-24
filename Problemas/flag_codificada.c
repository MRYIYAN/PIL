//==============================================================//
// PRACTICA - FLAG CODIFICADA (Uso wsl por si tienes problemas con los saltos de linea)
//==============================================================//
//
// En este ejercicio nos dan un array de numeros y
// tenemos que reconstruir la flag.
//
// Yo creo que los numeros son letras pero en numero.
// Entonces lo que hago es imprimirlos como caracteres.
//
// No estoy 100% seguro pero creo que es ASCII.
//
//--------------------------------------------------------------//
// Librerias
//--------------------------------------------------------------//

#include <stdio.h>

int main() {

    // Este es el array que nos dan
    char secret[] = {72, 84, 84, 80, 83, 95, 49, 51, 51, 55};

    int i;

    printf("Flag reconstruida: ");

    // Recorro el array y lo imprimo como caracter
    for(i = 0; i < 10; i++) {

        printf("%c", secret[i]);
    }

    printf("\n");

    return 0;
}