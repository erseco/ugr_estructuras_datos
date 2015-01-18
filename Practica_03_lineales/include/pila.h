/**
  * @file pila.h
  * @brief Fichero cabecera del TDA Pila
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  *
  */

#ifndef __Pila_H__
#define __Pila_H__

#include <cassert>

/**
 *  @brief T.D.A. Pila
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c Pila sobre el
 * tipo @c T es una lista de elementos del mismo con un funcionamiento
 * @e LIFO (Last Input, First Output). En una pila, las operaciones
 * de inserción y borrado de elementos tienen lugar en uno de los extremos
 * denominado @e Tope. Una pila de longitud @e n la denotamos
 *
 * - [a1,a2,a3,..,an>
 *
 * donde @e ai es el elemento de la posición i-ésima.
 *
 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es
 * decir, a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.
 *
 * Si @e n=0 diremos que la pila está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n). Donde n es el
 * número de elementos de la Pila.
 *
 */
template <class T>
class Pila
{
  private:
    struct Celda
    {
      T elemento;
      Celda * siguiente;

      Celda() : siguiente(0) {};
      Celda(const T & elem, Celda * sig) : elemento(elem), siguiente(sig) {};
    };

    Celda * primera;
    int num_elem;
  public:
    Pila(): primera(0), num_elem(0) {};
    Pila(const Pila<T> & p);
    ~Pila();
    Pila& operator= (const Pila<T>& p);
    bool vacia() const {return primera==0;}
    T& tope ()
      { assert(primera!=0); return primera->elemento;}
    const T & tope () const
      { assert(primera!=0); return primera->elemento;}
    void poner(const T & elem);
    void quitar();
    int num_elementos() const
      { return num_elem; }
};


#include <pila.cpp>

#endif // __Pila_H__
