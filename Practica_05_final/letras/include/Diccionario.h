/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A Diccionario
 *
 ******************************************************************************/

#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <string>
#include "ArbolGeneral.h"
#include "tree.h"
// #include "tree.hh"
// #include "tree_util.hh" // Funciones para pintar arboles

using namespace std;

 struct info
 {
	char c; ///<< caracter que se almacena en un nodo
	bool final; ///< nos indica si es final o no de palabra
	info()
	{
		c='\0';
		final=false;
	}
	info(char car, bool f) : c(car), final(f) {}

	friend ostream & operator<<(ostream & os, const info &i)
	{
		os << i.c;

		return os;
	}
};

class Diccionario
{

private:

	// ArbolGeneral<info> datos;
	tree<info> datos;

public:

	/**
	@brief Construye un diccionario vacio.
	**/
	Diccionario();

	/**
	@brief Devuelve el numero de palabras en el diccionario
	**/
	int size() const ;

	/**
	@brief Obtiene todas las palabras en el diccionario de un longitud dada
	@param longitud: la longitud de las palabras de salida
	@return un vector con las palabras de longitud especifica en el parametro de entrada
	**/
	vector<string> PalabrasLongitud(int longitud);

	/**
	@brief Indica si una palabra esta en el diccionario o no
	@param palabra: la palabra que se quiere buscar
	@return true si la palabra esta en el diccionario. False en caso contrario
	**/
	bool Esta(string palabra);


	void Agrega(string palabra);

	/**
	@brief Lee de un flujo de entrada un diccionario @param is:flujo de entrada
	@param D: el objeto donde se realiza la lectura. @return el flujo de entrada
	**/
	friend istream & operator>>(istream & is,Diccionario &D);

	/**
	@brief Escribe en un flujo de salida un diccionario @param os:flujo de salida
	@param D: el objeto diccionario que se escribe @return el flujo de salida
	**/
	friend ostream & operator<<(ostream & os, const Diccionario &D);


	class iterator
	{
	private:
		ArbolGeneral<info>::iter_preorden it;
		//tree<info>::iter_preorden it;
		string cad; //mantiene los caracteres desde el nivel 1 hasta donde se encuentra it.
	public:

		iterator ();

		string operator *();
		iterator & operator ++();
		bool operator ==(const iterator &i);
		bool operator !=(const iterator &i);
		friend class Diccionario;
	};

	iterator begin();
	iterator end();

};

#include "Diccionario.cpp"

#endif
