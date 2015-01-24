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
#include <vector>

#include "ArbolGeneral.h"
#include "Color.h" // definiciones de colores ansi

using namespace std;

/**
 * @brief Estructura que almacenaremso en el arbol
 *
 */
struct info
{
	/**
	 * Guardaremos el caracter de la palabra en un char
	 * y una bandera final que estará a true si desde el primer nivel
	 * hasta el nodo que contiene la bandera se forma una palabra
	 *
	 */
	char c; ///<< caracter que se almacena en un nodo
	bool final; ///< nos indica si es final o no de palabra

	/**
	 * @brief Constructor sin parametros
	 */
	info() : c('\0'), final(false) {}

	/**
	 * @brief Constructor con parametros
	 *
	 * @param car char con el caracter a almacenar
	 * @param f booleano que indica si es la letra final de la palabra
	 */
	info(char car, bool f) : c(car), final(f) {}

	/**
	 * @brief Constructor de copia
	 */
	info(const info & i) : c(i.c), final(i.final) {}

	/**
	 * @brief Operador de salida
	 */
	friend ostream & operator<<(ostream & os, const info &i)
	{
		os << i.c;
		return os;
	}
};

/**
 * @brief TDA Diccionario
 * @details Almacena las palabras de un fichero de texto e itera sobre ellas
 *
 */
class Diccionario
{

private:

	/**
	 * La representación de los datos del diccionario es un ArbolGeneral de elementos
	 * de tipo info (que a su vez son un char y un booleano que indica si es final de palabra)
	 *
	 * Dicha representación hace que las palabras ocupen menos en memoria, la cual
	 * es la única ventaja real a utilizar otros sistemas menos complejos como podrian ser
	 * vectores de cadenas
	 *
	 */
	ArbolGeneral<info> datos;

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


	/**
	 * @brief Indica el numero de apariciones de una letra en el arbol
	 *
	 * @param c letra a buscar
	 * @return Un entero indicando el numero de apariciones
	 */
	int getApariciones(const char c);


	/**
	 * @brief Agrega una palabra al arbol
	 * @details esta funcion se llama recursivamente
	 *
	 * @param palabra la palabra a agregar
	 * @param i posicion de la letra a insertar
	 * @param l ultimo nodo insertado
	 */
	void insertar_cadena( string palabra, int i, ArbolGeneral<info>::Nodo n);

	/**
	 * @brief Agrega una palabra al arbol
	 *
	 * @param palabra Palabra a agregar al arbol
	 */
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

	/**
	 * @brief Clase iteradora del diccioanrio
	 *
	 */
	class iterator
	{
	private:

		/**
		 *  representacion de los datos del iterador del diccionario
		 *  nos guardamos una copia del arbol y un iterador del mismo
		 *  asi como la cadena que iremos construyendo y el nivel
		 */
		ArbolGeneral<info> arbol;
		ArbolGeneral<info>::iter_preorden it;
		string cad; //mantiene los caracteres desde el nivel 1 hasta donde se encuentra it.
		int level;

	public:

		/**
		 * @brief Constructor sin parametros
		 */
		iterator();
		iterator(Diccionario diccionario);

		string operator *();
		iterator & operator ++();
		bool operator ==(const iterator &i);
		bool operator !=(const iterator &i);

		ostream & operator<<(ostream & os);

		friend class Diccionario;
	};

	iterator begin();
	iterator end();

};

#include "Diccionario.cpp"

#endif
