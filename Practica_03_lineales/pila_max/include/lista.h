/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Basado en el código del Prof. Joaquin Fdez. Valdivia
 *
 ******************************************************************************/

/**
  * @file lista.h
  * @brief Fichero cabecera del TDA Lista
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en cualquier posicion
  */

#ifndef __Lista_H__
#define __Lista_H__

/**
 * @brief  T.D.A. Lista
 *
 * Cada objeto del TDA Lista de T, modela listas de objetos del domino T.
 * Asociado al TDA Lista existe el TDA Posicion, cuyos valores son
 * posiciones válidas de los elementos de una lista. Cada objeto
 * (instancia) del TDA Lista tiene vinculado un conjunto de valores del
 * tipo Posicion, distinto.
 *
 * - [a1,a2,a3,..,an>
 *
 * donde @e ai es el elemento de la posición i-ésima.
 *
 * El espacio requerido para el almacenamiento es O(n). Donde n es el
 * número de elementos de la Lista.
 *
 * Son mutables.
 *
 * Residen en memoria dinámica.
 *
 */
template <class T>
class Lista {

  class nodoLista {
  public:
    T elemento;
    nodoLista * siguiente;
    nodoLista(nodoLista * p, const T & elem)
      : siguiente(p), elemento(elem)
      {};
    nodoLista() : siguiente(0)
      {};
  };

/*
  Función de Abstracción:
  ----------------------
  Dado el objeto del tipo rep r, r = {cab, fin, num_elem}, el objeto
  abstracto al que representa es:
    l = < r.cab->siguiente->elemento,
          r.cab->siguiente->siguiente->elemento,
    ...
    r.cab->siguiente-> (num_elem) ->siguiente->elemento >

  Invariante de Representación:
  ----------------------------
   -  0 <= r.num_elem
   -  r.fin == r.cab->siguiente-> (num_elem) ->siguiente->elemento
   -  r.fin->siguiente->siguiente == 0

 */
private:

    typedef nodoLista * Posicion;
    Posicion cab;
    Posicion fin;
    int num_elem;

public:

  /**
     @brief Constructor por defecto.
     Crea una lista vacía.
  */
  Lista();

  /**
      @brief Constructor de copia.
      @param l: lista que se copia.
      Crea una lista que es copia de l.
  */
  Lista(const Lista<T> & l);

  /**
     @brief Destructor.

     Elimina todos los elementos de la lista, liberando los recursos
     usados.
  */
  ~Lista();

  /**
     @brief Informa si la lista está vacía.

     @return true, si la lista está vacía.
            false, en otro caso.
  */
  bool vacia() const;

  /**
     @brief Vacía la lista.

     Destruye todos los elementos del objeto receptor, que queda
     vacío. MODIFICA al objeto receptor.
  */
  void hacer_nula();


  /**
     @brief Devuelve el número de elementos de la lista.
     @return número de elementos de la lista.
  */
  int num_elementos() const;

  /**
     @brief Inserta un elemento en la lista.

     @param p: posición detrás de la que se inserta. Debe ser una
           posición válida para el objeto lista receptor.
     @param elemento: elemento que se inserta.

     @precondition: num_elem() < long_max().

     Inserta un element con el valor 'elem' en la posición siguiente
     a 'p'. MODIFICA al objeto receptor.
  */
  void insertar(const Posicion p, const T & elemento);

  /**
     @brief Elimina un elemento de la lista.

     @param p: posición del elemento que se borra. Debe ser una
            posición válida para el objeto lista receptor.

      Destruye el objeto que ocupa la posición 'p' en el objeto
      lista receptor. MODIFICA al objeto receptor.
  */
  void borrar(Posicion p);

  /**
     @brief Obtienen un elemento de la lista.

     @param p: posición del elemento a obtener. Debe ser una
            posición válida para el objeto lista receptor.
            p != final().

     @return El elemento situado en la posición p de la lista.

     Dado que se devuelve una referencia al objeto, éste puede ser
     modificado desde fuera de la lista.
  */
  T & elemento(const Posicion p);

  /**
    @brief Primera posición de la lista.
    @return la primera posición de la lista receptora.
  */
  Posicion primero() const;

  /**
     @brief Posición posterior al último elemento de la lista.
     @return la posición siguiente al último elemento de la lista
      receptora.
  */
  Posicion final() const;

  /**
     @brief Siguiente posición de la lista.
     @param p: Posición válida de la lista receptora. p != final();
     @return la posición siguiente a 'p' en la lista receptora.
  */
  Posicion siguiente(const Posicion p) const;

  /**
     @brief Anterior posición de la lista.
     @param p: Posición válida de la lista receptora. p != primero();
     @return la posición anterior a 'p' en la lista receptora.
  */
  Posicion anterior(const Posicion p) const;

};

#include <lista.cpp>

#endif // __Lista_H__
