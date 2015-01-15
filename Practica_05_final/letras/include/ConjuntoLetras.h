/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A ConjuntoLetras
 *
 ******************************************************************************/

#ifndef __ConjuntoLetras_h__
#define __ConjuntoLetras_h__

#include <set>
#include <iostream>
#include <string>
#include "Letra.h"

using namespace std;

class ConjuntoLetras
{

private:

 	// Aqui almacenamos las letras
 	set<Letra, cmp> abecedario;

public:
	// Constructor por defecto
	ConjuntoLetras()
	{

	}

	int size()
	{
		return abecedario.size();
	}

	// Letra getLetra(int n)
	// {
	// 	set<Letra>::iterator it = abecedario.begin();
	// 	advance(it, n);
	// 	return *it;
	// }

    const Letra & operator[](int n) const
    {
		set<Letra>::iterator it = abecedario.begin();
		advance(it, n);
		return *it;
    };


	// Funcion para pintar las letras
	friend ostream & operator<<(ostream & os, const ConjuntoLetras &cl)
	{
		set<Letra>::iterator it = cl.abecedario.begin();

		for (; it!=cl.abecedario.end(); ++it )
			os << *it << endl;

		return os;
	}

	// Funcion para rellenar el conjunto de letras
	friend istream & operator>>(istream & is, ConjuntoLetras &cl)
	{

		// Obtenemos la primera línea (hay que ignorarla)
		string linea;
		getline(is, linea);

		while (is)
		{
			char c;
			int n, p;

			// Obtenemos los valores (char, int, int)
			is >> c >> n >> p;

			// Creamos una nueva letra
			Letra l(c, n, p);

			// Agregamos la letra al conjunto
			cl.abecedario.insert(l);
		}

		return is;
	}

};

#endif