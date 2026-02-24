//==============================================================//
// PRACTICA - PASSWORD VALIDATOR (Uso wsl por si tiene problemas con los saltos de linea)
//==============================================================//
//
// En este ejercicio nos dan una funcion llamada valid()
// que comprueba si un PIN es correcto o no.
//
// Nosotros no sabemos cual es el PIN, asi que lo que hago
// es probar todos los numeros de 6 cifras hasta encontrar
// uno que haga que la funcion devuelva 1.
//
// No es la forma mas eficiente pero es sencilla y funciona.
//
//--------------------------------------------------------------//
// Librerias
//--------------------------------------------------------------//

#include <stdio.h>

//--------------------------------------------------------------//
// Funcion que nos dieron
//--------------------------------------------------------------//

int valid(int pin) {

    // Tiene que ser multiplo de 7
    if (pin % 7 != 0) return 0;

    // El segundo digito empezando por la derecha debe ser 5
    // Por eso dividimos entre 10 y luego hacemos %10
    if ((pin / 10) % 10 != 5) return 0;

    // Si pasa las dos condiciones entonces es valido
    return 1;
}

//--------------------------------------------------------------//
// Programa principal
//--------------------------------------------------------------//

int main() {

    int pin;  // aqui voy probando numeros

    printf("Buscando PIN valido de 6 cifras...\n\n");

    //----------------------------------------------------------//
    // Recorro todos los numeros de 6 cifras
    // Empiezo en 100000 porque asi seguro tiene 6 digitos
    //----------------------------------------------------------//

    for(pin = 100000; pin <= 999999; pin++) {

        // Llamo a la funcion para ver si cumple las condiciones
        if(valid(pin)) {

            printf("PIN valido encontrado: %d\n", pin);

            // Cuando encuentro el primero ya paro
            break;
        }
    }

    return 0;
}