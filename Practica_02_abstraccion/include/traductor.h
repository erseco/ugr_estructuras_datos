/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Cabecera del Traductor
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
class Traductor {

 private:

/**
  * @page rep Conjunto Rep del Traductor
  * vector<Palabra>
  *
  * @section inv Conjunto Invariante de la representación
  * Las palabras deberan estar definidas corretamente segun las restricciones
  * propias de la clase palabra
  *
  * @section fa Conjunto Función de abstracción
  * Un vector de objetos de la clase palabra
  *
  * Un objeto válido @e rep del Traductor representa al valor
  * (vector de palabras)
  *
  */

  /**
   * @brief Coleccion (lista) de instancias de la clase palabra
   */
  vector<Palabra> words;


 public:

/**
 * @brief Obtiene las traducciones a una palabra
 *
 * @param word La plabra a traducir
 * @return Retorna un vector de traducciones
 */
  vector<string> GetTraducciones(string word);

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
