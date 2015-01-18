/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A Letra
 *
 ******************************************************************************/

#ifndef __Letra_h__
#define __Letra_h__

#include <iostream>

using namespace std;

class Letra
{

private:
	char c;	// El caracter de la propia letra
	int n; 	// La cantidad de veces que puede aparecer.
	int p; 	// La puntuacion de una letra.

public:
	// Constructor por defecto
	Letra()
	{
		c='\0';
		n=0;
		p=0;
	}

    // bool operator<(const Letra &L2)
    // {
    //     return (*this < L2) ? true : false;
    // }

    // bool operator()(const Letra &L2)
    // {
    //     return (c < L2.getC()) ? true : false;
    // }

    char operator *()
    {
    	return c;
    }

    int operator &()
    {
    	return n;
    }

    int getPuntos() const
    {
    	return p;
    }

	char getC() const
	{
		return c;
	}

	// Constructor con parametros
	Letra(char c, int n, int p) : c(c), n(n), p(p) {}

	// Funcion para pintar la letra
	friend ostream & operator<<(ostream & os, const Letra &l)
	{
		os << l.c << " " << l.n << " Pts:" << l.p;
		return os;
	}

};

// Definimos un functor para la comparación NOTA: No es neceario, pues hemos
// implementado el operador <
struct cmp
{
    bool operator()(const Letra &L1 , const Letra &L2)
    {
        return (L1.getC() < L2.getC()) ? true : false;
    }
};

#endif