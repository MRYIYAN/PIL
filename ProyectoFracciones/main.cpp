//=======================================================//
//                   IMPORTS                             //
//=======================================================//
#include <iostream>
#include "fracciones.h"
using namespace std;

//=======================================================//
//  Programa principal                                   //
//=======================================================//
// Crea dos fracciones, las suma y muestra el resultado
// usando la funcion imprime()
//=======================================================//

int main()
{
    //=======================================================//
    //  Creacion de fracciones                               //
    //=======================================================//
    // Se crean dos objetos de la clase fraccion
    //=======================================================//
    fraccion p(2, 3);
    fraccion q(7, 9);

    //=======================================================//
    //  Operaciones con fracciones                           //
    //=======================================================//
    // Se usan los operadores sobrecargados
    //=======================================================//
    fraccion suma = p + q;
    fraccion resta = p - q;
    fraccion multiplicacion = p * q;
    fraccion division = p / q;

    //=======================================================//
    //  Mostrar resultado                                    //
    //=======================================================//
    suma.imprime();

    return 0;
}