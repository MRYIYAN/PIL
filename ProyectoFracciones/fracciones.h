
//=======================================================//
//                   IMPORTS                             //
//=======================================================//

#ifndef _FRACCIONES_H_
#define _FRACCIONES_H_

//=======================================================//
//                   Clase fraccion                      //
//=======================================================//
// Representa una fraccion usando numerador y denominador
// Los datos quedan dentro de la clase
//=======================================================//

class fraccion
{
    int numerador;
    int denominador;

    static int mcd(int a, int b);
    void normalizar();

public:

    //=======================================================//
    //  Constructor                                          //
    //=======================================================//
    // Crea una fraccion con numerador y denominador
    //=======================================================//
    fraccion(int num = 0, int den = 1);

    //=======================================================//
    //  Metodos para obtener datos                           //
    //=======================================================//
    // Devuelven el numerador y el denominador
    //=======================================================//
    int dameNumerador() const { return numerador; }
    int dameDenominador() const { return denominador; }

    //=======================================================//
    //  Metodos para modificar datos                         //
    //=======================================================//
    // Cambian el numerador y el denominador
    //=======================================================//
    void ponNumerador(int num);
    void ponDenominador(int den);

    //=======================================================//
    //  Operador suma                                        //
    //=======================================================//
    // Permite sumar dos fracciones usando el operado
    //=======================================================//
    fraccion operator+(const fraccion& otraFrac) const;

    //=======================================================//
    //  Funcion imprime                                      //
    //=======================================================//
    // Muestra la fraccion por pantalla
    //=======================================================//
    void imprime();
};

#endif