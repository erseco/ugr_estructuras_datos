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

 	/**
 	 * @brief Representación del conjunto de letras (un set)
 	 */
 	set<Letra, cmp> abecedario;

public:

	/**
	 * @brief Devuelve Tamaño del conjunto de letras (abecedario)
	 *
	 * @return Tamaño del conjunto de letras
	 */
	int size()
	{
		return abecedario.size();
	}

	/**
	 * @brief Obtiene una letra en base a su posicion
	 *
	 * @param n posicion de la letra
	 */
    const Letra & operator[](int n) const
    {
		set<Letra>::iterator it = abecedario.begin();
		advance(it, n); // incrementa el iterador n posiciones
		return *it;
    };

    int puntuacion(string palabra)
    {
    	int puntos = 0;

    	for (int i=0;i<palabra.size(); i++)
    	{
    		bool salir = false;
    		set<Letra>::iterator it = abecedario.begin();
    		for (; !salir && it!=abecedario.end(); ++it )
    		{
				puntos  +=  it->getPuntos();
				salir = true;
    		}

    	}

		return puntos;
    }

	/**
	 * @brief Pinta un conjunto de letras en un ostream
	 *
	 * @param os la referencia al ostream donde escribir
	 * @param cl Conjunto de Letras desde el que leer
	 */
	friend ostream & operator<<(ostream & os, const ConjuntoLetras &cl)
	{
		set<Letra>::iterator it = cl.abecedario.begin();

		for (; it!=cl.abecedario.end(); ++it )
			os << *it << endl;

		return os;
	}

	/**
	 * @brief Llena un conjunto de letras desde un istream
	 *
	 * @param is la referencia al istream desde el que leer
	 * @param cl Conjunto de Letras en el que escribir
	 */
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