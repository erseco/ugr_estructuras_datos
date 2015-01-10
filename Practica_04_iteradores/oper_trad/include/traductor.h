/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Cabecera del T.D.A. Traductor
 *
 ******************************************************************************/

/**
  * @file traductor.h
  * @brief Fichero cabecera del TDA Traductor
  *
  */
#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "palabra.h"


using namespace std;

/**
  * @brief T.D.A. Traductor
  *
  * Esta clase carga una serie de palabras con sus respectivas traducciones y
  * permite consultar las traducciones de una determinada palabra
  *
  * Un ejemplo de su uso:
  * @include pruebatraductor.cpp
  *
  */
class Traductor
{
/**
* @page rep Conjunto Rep del Traductor
* map <string, Palabra>
*
* @section inv Conjunto Invariante de la representación
* Las palabras deberan estar definidas corretamente segun las restricciones
* propias de la clase palabra
*
* @section fa Conjunto Función de abstracción
* Un mapa de objetos de la clase palabra indizados por su palabra de origen
*
* Un objeto válido @e rep del Traductor representa al valor
* Un map de string y Palabra
*
*/

private:

  /**
   * @brief Coleccion (lista) de traducciones, consistente en una palabra origen
   * como key de la clase palabra y una palabra (lista de traducciones) como
   * value
   */
  map <string, Palabra> datos;

public:

/**
* @brief clase para iterar sobre el traductor
* */
class const_iterator
{
public:

  map<string,Palabra >::const_iterator it;

public:
  /**
   * @brief Sobrecarga del operador ++
   */
  const_iterator & operator++()
  {
    ++it;
    return *this;
  }
  /**
   * @brief Sobrecarga del operador --
   */
  const_iterator & operator--()
  {
    --it;
    return *this;
  }
  /**
   * @brief Sobrecarga del operador *
   */
  const pair<const string, Palabra > &operator *()
  {
    return *it;
  }

  /**
   * @brief Sobrecarga del operador ==
   */
  bool operator ==(const const_iterator &i)
  {
    return i.it==it;
  }

  /**
   * @brief Sobrecarga del operador !=
   */
  bool operator !=(const const_iterator &i)
  {
    return i.it!=it;
  }

  // La clase Traductor tiene que poder acceder al iterador
  friend class Traductor;
};

/**
* @brief Inicializa un iterator al comienzo del traductor
* */
const_iterator begin() const
{
  const_iterator i;
  i.it=datos.begin();
  return i;
}

/**
* @brief Inicializa un iterator al final del traductor
* */
const_iterator end() const
{
  const_iterator i;
  i.it=datos.end();
  return i;
}

/**
 * @brief Busca un para de traduccion
 *
 * @param key palabra origen a buscar
 * @return un iterador de traductor con el resulado
 * de la búsqueda
 */
const_iterator buscar(string key)
{
  const_iterator i;
  i.it=datos.find(key);
  return i;
}

/**
 * @brief Inserta una palabra traducida en un traductor
 *
 * Agrega value a la coleccion de palabras traducidas evitando duplicados
 *
 * @param key palabra origen
 * @param value traduccion
 */
void inserta(string key, string value);

 public:

/**
 * @brief Obtiene las traducciones a una palabra
 *
 * @param word La plabra a traducir
 * @return Retorna un vector de traducciones
 *
 * NOTA: Se devuelve como un vector de string por compatibilidad con el codigo
 * proporcionado previamente, aunque se podria usar una representación directa
 * de palabra
 *
 */
  vector<string> GetTraducciones(string p);

/**
  * @brief Entrada de una Traduccion desde istream
  * @param is stream de entrada
  * @param t Traductor que recibe el valor
  * @return La referencia al istream
  * @pre La entrada es un fichero separado por ";" con una palabra origen y al
  * menos una palabra de traduccion
  */
  friend istream& operator>> (istream& is, Traductor& t);

};

#endif
