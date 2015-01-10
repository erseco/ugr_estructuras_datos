/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 ******************************************************************************/

/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA Pila_max usando una cola
  *
  * Gestiona una secuencia de elementos con su máximo
  */
#ifndef __PILA_MAX
#define __PILA_MAX

#include <iostream>
#include <cola.h>

using namespace std;

class Pila_max
{

private:
  /**
    * @brief Rep de pila_max
    *
    * Guardamos los datos en una cola de tipo elemento
    * En este caso no hay invariante de la representación ya que
    * todo descansa en la clase cola
    *
    */
    Cola<elemento> datos;

public:

    /**
     * @brief Indica si la pila está vacia
     * @return Un valor booleano, true si la pila esta vacia, false si contiene
     * al menos un elemento
     */
    bool vacia() const
    {
      return datos.vacia();
    }

    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(int valor);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const
    {
      return datos.num_elementos();
    }

    /**
     * @brief Devuelve el ultimo elemento de la pila
     * @return Un elemento
     */
    elemento tope();

};

#include <pila_max_cola.cpp>

#endif