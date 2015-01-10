/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Cabecera Clase Palabra
 *
 ******************************************************************************/

/**
  * @file palabra.h
  * @brief Fichero cabecera del TDA Palabra
  *
  */
#ifndef __PALABRA
#define __PALABRA

#include <iostream>

using namespace std;

#include <iostream>
#include <string>
#include <vector>


using namespace std;

/**
  * @file palabra.h
  * @brief T.D.A. Palabra
  *
  * Una instancia @e c del tipo de datos abstracto @c Palabra es un objeto
  * que contiene una palabra y una coleccion de traducciones asociadas a esa
  * palabra.
  *
  * Se compone de una palabra en el idioma origen y se transforma en una o mas
  * palabras en el idioma destino. Las palabras pueden contener mas de un vocablo.
  * P.e abandonar se traduce en ingles como “give up”.
  * Asi tanto en el origen como en el destino puede tener mas de un vocablo.
  * Las vocablos no contendran acentos, tildes ni el caracter ñ.
  * Los vocablos si existe mas de uno se separan por un espacio.
  *
  * Lo representamos como:
  * "palabra_origen" : <"traduccion1","traduccion2","traduccion3","traduccion4"...>
  *
  * Ejemplos:
  * "casa" : <"home", "house">
  * "gato" : <"cat">
  *
  */
class Palabra {

private:

/**
  * @page rep Conjunto Rep del TDA Palabra
  * string word
  * vector<string> translations
  *
  * @section inv Conjunto Invariante de la representación
  * Las vocablos no contendran acentos, tildes ni el caracter ñ.
  * Los vocablos si existe mas de uno se separan por un espacio.
  *
  * @section fa Conjunto Función de abstracción
  * La palabra origen es un String
  * Las traducciones asociadas se almacenan en un vector de string
  *
  * Un objeto válido @e rep del TDA Palabra representa al valor
  * "casa" : <"home", "house">
  *
  */

  /**
   * @brief Palabra origen
   */
	string word;

  /**
   * @brief Coleccion de palabras
   */
	vector<string> translations;

public:

  /**
   * @brief Obtiene una palabra
   * @pre Debe contener una palabra origen
   *
   * @return Devuelve la palabra origen de una instancia de la clase Palabra
   */
	string GetWord();

  /**
   * @brief Obtiene una coleccion de traducciones de una palabra
   * @pre Debe contener al menos una traduccion
   *
   * @return Devuelve una coleccion de traducciones de una instancia de la clase Palabra
   *
   */
	vector<string> GetTranslations();


/**
  * @brief Entrada de una Palabra desde istream
  * @param is stream de entrada
  * @param p Palabra que recibe el valor
  * @return La referencia al istream
  * @pre La entrada de una cadena separada por ";" con una palabra origen y al
  * menos una palabra de traduccion
  */
	friend istream& operator>> (istream& is, Palabra& p);

};



#endif