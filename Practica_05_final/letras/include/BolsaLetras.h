/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A BolsaLetras
 *
 ******************************************************************************/

#ifndef __BolsaLetras_h__
#define __BolsaLetras_h__

#include <set>
#include <iostream>
#include <string>

#include "ConjuntoLetras.h"
#include "Letra.h"

using namespace std;

class BolsaLetras
{

private:

 	// Aqui almacenamos las letras
 	multiset<Letra, cmp> bolsa;

public:
	// Constructor por defecto
	BolsaLetras()
	{

	}


	int size()
	{
		return bolsa.size();
	}

	// Letra getLetra(int n)
	// {
	// 	multiset<Letra>::iterator it = bolsa.begin();
	// 	advance(it, n);
	// 	return *it;
	// }

    const Letra & operator[](int n) const
    {
		multiset<Letra>::iterator it = bolsa.begin();
		advance(it, n);
		return *it;
    };

	// Funcion para pintar las letras
	friend ostream & operator<<(ostream & os, const BolsaLetras &cl)
	{
		set<Letra>::iterator it = cl.bolsa.begin();

		for (; it!=cl.bolsa.end(); ++it )
			os << *it << endl;

		return os;
	}

	// Funcion para rellenar la bolsa de letras
	friend ConjuntoLetras & operator>>(ConjuntoLetras &cl, BolsaLetras &bl)
	{

		// Recorremos las letras...
		for (int i=0; i<cl.size(); i++)
		{

			Letra letra = cl[i];

			// ...y creamos tantas letras en la bolsa como cantidad tenga cada letra
			for (int j=0; j<&letra; j++)
			{
				bl.bolsa.insert(letra);

			}

		}

		return cl;
	}

};

#endif