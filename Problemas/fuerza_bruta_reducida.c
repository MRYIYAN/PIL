//==============================================================//
// PRACTICA - FUERZA BRUTA REDUCIDA  (Uso wsl por si tiene problemas con los saltos de linea)
//==============================================================//
//
// En este ejercicio el PIN es de 3 digitos (000 a 999).
// Tenemos que encontrar todos los que cumplen:
//
// 1. Ser multiplo de 7
// 2. Que el digito del medio sea 5
//
// Lo que hago es probar todos los numeros de 0 a 999
// y comprobar uno por uno.
//
// Tambien cuento cuantos hay y guardo el menor y el mayor.
//
//--------------------------------------------------------------//
// Librerias
//--------------------------------------------------------------//

#include <stdio.h>

//--------------------------------------------------------------//
// Funcion valid (la misma que nos dan)
//--------------------------------------------------------------//

int valid(int pin) {

    if (pin % 7 != 0) return 0;

    if ((pin / 10) % 10 != 5) return 0;

    return 1;
}

//--------------------------------------------------------------//
// Programa principal
//--------------------------------------------------------------//

int main() {

    int pin;
    int contador = 0;      // para contar cuantos validos hay
    int menor = -1;        // guardo el menor valido
    int mayor = -1;        // guardo el mayor valido

    printf("PIN validos de 3 digitos:\n\n");

    //----------------------------------------------------------//
    // Recorremos de 0 a 999
    //----------------------------------------------------------//

    for(pin = 0; pin <= 999; pin++) {

        if(valid(pin)) {

            // %03d sirve para que siempre tenga 3 digitos (ej: 007)
            printf("%03d ", pin);

            contador++;

            // Si es el primero que encontramos lo guardo como menor
            if(menor == -1) {
                menor = pin;
            }

            // Siempre voy actualizando el mayor
            mayor = pin;
        }
    }

    //----------------------------------------------------------//
    // Resultados finales
    //----------------------------------------------------------//

    printf("\n\nTotal de PIN validos: %d\n", contador);
    printf("Menor PIN valido: %03d\n", menor);
    printf("Mayor PIN valido: %03d\n", mayor);

    return 0;
}