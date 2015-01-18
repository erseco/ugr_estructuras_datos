/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingenier�a Inform�tica
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Basado en el c�digo del Prof. Joaquin Fdez. Valdivia
 *
 ******************************************************************************/

/**
  * @file lista.h
  * @brief Fichero cabecera del TDA Lista
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en cualquier posicion
  */

#ifndef __Lista_H__
#define __Lista_H__

/**
 * @brief  T.D.A. Lista
 *
 * Cada objeto del TDA Lista de T, modela listas de objetos del domino T.
 * Asociado al TDA Lista existe el TDA Posicion, cuyos valores son
 * posiciones v�lidas de los elementos de una lista. Cada objeto
 * (instancia) del TDA Lista tiene vinculado un conjunto de valores del
 * tipo Posicion, distinto.
 *
 * - [a1,a2,a3,..,an>
 *
 * donde @e ai es el elemento de la posici�n i-�sima.
 *
 * El espacio requerido para el almacenamiento es O(n). Donde n es el
 * n�mero de elementos de la Lista.
 *
 * Son mutables.
 *
 * Residen en memoria din�mica.
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
  Funci�n de Abstracci�n:
  ----------------------
  Dado el objeto del tipo rep r, r = {cab, fin, num_elem}, el objeto
  abstracto al que representa es:
    l = < r.cab->siguiente->elemento,
          r.cab->siguiente->siguiente->elemento,
    ...
    r.cab->siguiente-> (num_elem) ->siguiente->elemento >

  Invariante de Representaci�n:
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
     Crea una lista vac�a.
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
     @brief Informa si la lista est� vac�a.

     @return true, si la lista est� vac�a.
            false, en otro caso.
  */
  bool vacia() const;

  /**
     @brief Vac�a la lista.

     Destruye todos los elementos del objeto receptor, que queda
     vac�o. MODIFICA al objeto receptor.
  */
  void hacer_nula();


  /**
     @brief Devuelve el n�mero de elementos de la lista.
     @return n�mero de elementos de la lista.
  */
  int num_elementos() const;

  /**
     @brief Inserta un elemento en la lista.

     @param p: posici�n detr�s de la que se inserta. Debe ser una
           posici�n v�lida para el objeto lista receptor.
     @param elemento: elemento que se inserta.

     @precondition: num_elem() < long_max().

     Inserta un element con el valor 'elem' en la posici�n siguiente
     a 'p'. MODIFICA al objeto receptor.
  */
  void insertar(const Posicion p, const T & elemento);

  /**
     @brief Elimina un elemento de la lista.

     @param p: posici�n del elemento que se borra. Debe ser una
            posici�n v�lida para el objeto lista receptor.

      Destruye el objeto que ocupa la posici�n 'p' en el objeto
      lista receptor. MODIFICA al objeto receptor.
  */
  void borrar(Posicion p);

  /**
     @brief Obtienen un elemento de la lista.

     @param p: posici�n del elemento a obtener. Debe ser una
            posici�n v�lida para el objeto lista receptor.
            p != final().

     @return El elemento situado en la posici�n p de la lista.

     Dado que se devuelve una referencia al objeto, �ste puede ser
     modificado desde fuera de la lista.
  */
  T & elemento(const Posicion p);

  /**
    @brief Primera posici�n de la lista.
    @return la primera posici�n de la lista receptora.
  */
  Posicion primero() const;

  /**
     @brief Posici�n posterior al �ltimo elemento de la lista.
     @return la posici�n siguiente al �ltimo elemento de la lista
      receptora.
  */
  Posicion final() const;

  /**
     @brief Siguiente posici�n de la lista.
     @param p: Posici�n v�lida de la lista receptora. p != final();
     @return la posici�n siguiente a 'p' en la lista receptora.
  */
  Posicion siguiente(const Posicion p) const;

  /**
     @brief Anterior posici�n de la lista.
     @param p: Posici�n v�lida de la lista receptora. p != primero();
     @return la posici�n anterior a 'p' en la lista receptora.
  */
  Posicion anterior(const Posicion p) const;

};

#include <lista.cpp>

#endif // __Lista_H__
