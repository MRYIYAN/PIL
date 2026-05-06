//=======================================================//
//                   IMPORTS                             //
//=======================================================//


#include "fracciones.h"
#include <iostream>

using namespace std;

static int abs_val(int value)
{
    return value < 0 ? -value : value;
}

int fraccion::mcd(int a, int b)
{
    a = abs_val(a);
    b = abs_val(b);

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void fraccion::normalizar()
{
    if (denominador == 0)
    {
        denominador = 1;
    }

    if (denominador < 0)
    {
        numerador = -numerador;
        denominador = -denominador;
    }

    int divisor = mcd(numerador, denominador);
    if (divisor != 0)
    {
        numerador /= divisor;
        denominador /= divisor;
    }
}

fraccion::fraccion(int num, int den)
    : numerador(num), denominador(den)
{
    normalizar();
}

void fraccion::ponNumerador(int num)
{
    numerador = num;
    normalizar();
}

void fraccion::ponDenominador(int den)
{
    denominador = den;
    normalizar();
}

//=======================================================//
//  Operador suma                                        //
//=======================================================//
// Suma dos fracciones usando la formula:
// a/b + c/d = (a*d + b*c) / (b*d)
//=======================================================//
fraccion fraccion::operator+(const fraccion& otraFrac) const
{
    fraccion resultado(
        numerador * otraFrac.denominador + denominador * otraFrac.numerador,
        denominador * otraFrac.denominador
    );

    return resultado;
}

//=======================================================//
//  Operador resta                                       //
//=======================================================//
// Resta dos fracciones usando la formula:
// a/b - c/d = (a*d - b*c) / (b*d)
//=======================================================//
fraccion fraccion::operator-(const fraccion& otraFrac) const
{
    fraccion resultado(
        numerador * otraFrac.denominador - denominador * otraFrac.numerador,
        denominador * otraFrac.denominador
    );

    return resultado;
}

//=======================================================//
//  Operador multiplicacion                              //
//=======================================================//
// Multiplica dos fracciones multiplicando numeradores
// y denominadores entre si
//=======================================================//
fraccion fraccion::operator*(const fraccion& otraFrac) const
{
    fraccion resultado(
        numerador * otraFrac.numerador,
        denominador * otraFrac.denominador
    );

    return resultado;
}

//=======================================================//
//  Operador division                                    //
//=======================================================//
// Divide dos fracciones multiplicando por la inversa
//=======================================================//
fraccion fraccion::operator/(const fraccion& otraFrac) const
{
    fraccion resultado(
        numerador * otraFrac.denominador,
        denominador * otraFrac.numerador
    );

    return resultado;
}

//=======================================================//
//  Expresion decimal                                    //
//=======================================================//
// Devuelve la fraccion como numero decimal
// Se usa casting para que no haga division entera
//=======================================================//
double fraccion::decimal() const
{
    return (double)numerador / denominador;
}

//=======================================================//
//  Operador igualdad                                    //
//=======================================================//
// Compara si dos fracciones son iguales
// Como las fracciones se normalizan, basta comparar datos
//=======================================================//
bool fraccion::operator==(const fraccion& otraFrac) const
{
    return numerador == otraFrac.numerador &&
           denominador == otraFrac.denominador;
}

//=======================================================//
//  Funcion imprime                                      //
//=======================================================//
// Imprime la fraccion usando sus propios datos
//=======================================================//
void fraccion::imprime() const
{
    cout << endl << "La fraccion es:" << endl;
    cout << numerador << " / " << denominador << endl;
}