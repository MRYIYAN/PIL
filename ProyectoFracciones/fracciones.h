
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
    //  Operadores aritméticos                               //
    //=======================================================//
    // Permiten sumar, restar, multiplicar y dividir fracciones
    //=======================================================//
    fraccion operator+(const fraccion& otraFrac) const;
    fraccion operator-(const fraccion& otraFrac) const;
    fraccion operator*(const fraccion& otraFrac) const;
    fraccion operator/(const fraccion& otraFrac) const;

    //=======================================================//
    //  Expresion decimal                                    //
    //=======================================================//
    // Devuelve la fraccion como numero decimal
    //=======================================================//
    double decimal() const;

    //=======================================================//
    //  Operador igualdad                                    //
    //=======================================================//
    // Comprueba si dos fracciones son iguales
    //=======================================================//
    bool operator==(const fraccion& otraFrac) const;

    //=======================================================//
    //  Funcion imprime                                      //
    //=======================================================//
    // Muestra la fraccion por pantalla
    //=======================================================//
    void imprime() const;
};

#endif