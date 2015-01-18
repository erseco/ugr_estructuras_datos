/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Cabecera T.D.A. Palabra
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
#include <string>
#include <set>

using namespace std;

/**
  * @file palabra.h
  * @brief T.D.A. Palabra
  *
  * Una instancia @e c del tipo de datos abstracto @c Palabra es un objeto
  * que contiene una coleccion de traducciones asociadas que se asociaran a una
  * palabra.
  *
  * Quizá para ser mas correcto debería haber un atributo string conteniendo la
  * palabra, pero como luego ese string se va a usar como key en el map que con-
  * tiene las palabras se ha optado por omitirlo
  *
  * Se compone de un lista (set) de palabras destino
  * Las palabras pueden contener mas de un vocablo.
  * P.e abandonar se traduce en ingles como “give up”.
  * Asi tanto en el origen como en el destino puede tener mas de un vocablo.
  * Las vocablos no contendran acentos, tildes ni el caracter ñ.
  * Los vocablos si existe mas de uno se separan por un espacio.
  *
  * Lo representamos como:
  * <"traduccion1","traduccion2","traduccion3","traduccion4"...>
  *
  * Ejemplos:
  * <"home", "house">
  * <"cat">
  *
  */
class Palabra
{

private:

  /**
   * @brief Coleccion de palabras
   */
  set<string> translations;

public:

/**
* @brief clase para iterar sobre las palabras
* */
class const_iterator{
private:

  set<string>::const_iterator it;
public:
  /**
   * @brief Sobrecarga del operador ++
   */
  const_iterator & operator++(){
    ++it;
    return *this;
  }
  /**
   * @brief Sobrecarga del operador --
   */
  const_iterator & operator--(){
    --it;
    return *this;
  }
  /**
   * @brief Sobrecarga del operador *
   */
  const string &operator *(){
    return *it;
  }
  /**
   * @brief Sobrecarga del operador ==
   */
  bool operator ==(const const_iterator &i){
    return i.it==it;
  }
  /**
   * @brief Sobrecarga del operador !=
   */
  bool operator !=(const const_iterator &i){
    return i.it!=it;
  }
  // La clase Palabra tiene que poder acceder al iterador
  friend class Palabra;
};


  /**
  * @brief Inicializa un iterator al comienzo de Palabra
  * */
  const_iterator begin() const
  {
    const_iterator i;
    i.it=translations.begin();
    return i;
  }
  /**
  * @brief Inicializa un iterator al final de Palabra
  * */
  const_iterator end() const
  {
    const_iterator i;
    i.it=translations.end();
    return i;
  }

  /**
   * @brief Esta funcion agrega una palabra al set
   *
   * @param value la palabra a añadir
   */
  void add(string value);

};



#endif