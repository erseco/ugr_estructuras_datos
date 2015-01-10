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
  * @file cola.cpp
  * @brief Implementación del TDA Lista
  *
  */
#include <cassert>
// #include "lista.h" // El codigo ya se incluye en lista.h

/* _________________________________________________________________________ */

template <class T>
Lista<T>::Lista()
{
  cab = new nodoLista;
  assert(cab != 0);
  fin = cab;
  num_elem = 0;
}

/* _________________________________________________________________________ */

template <class T>
Lista<T>::Lista(const Lista<T> & l)
{
  num_elem = l.num_elem;

  cab = new nodoLista;
  assert(cab != 0);
  fin = cab;
  Posicion q = cab;

  Posicion p = l.cab;
  while (p->siguiente != 0)
    {
      q->siguiente = new nodoLista(0, p->siguiente->elemento);
      assert(q->siguiente != 0);
      q = q->siguiente;
      p = p->siguiente;
    }
  fin = q;
}

/* _________________________________________________________________________ */

template <class T>
bool Lista<T>::vacia() const
{
  return num_elem == 0;
}

/* _________________________________________________________________________ */

template <class T>
int Lista<T>::num_elementos() const
{
  return num_elem;
}

/* _________________________________________________________________________ */

template <class T>
T& Lista<T>::elemento(const Posicion p)
{
  assert(p != final());

  return p->siguiente->elemento;
}

/* _________________________________________________________________________ */

template <class T>
void Lista<T>::insertar(const Posicion p, const T & elemento)
{
  Posicion q = new nodoLista(p->siguiente, elemento);
  assert(q != 0);
  p->siguiente = q;
  if (q->siguiente == 0)
    fin = q;
  num_elem++;
}


/* _________________________________________________________________________ */

template <class T>
void Lista<T>::borrar(const Posicion p)
{
  if (p != final())
    {
      Posicion q = p->siguiente;
      p->siguiente = q->siguiente;
      delete q;
      num_elem--;
      if (p->siguiente == 0)
	fin = p;
    }
};

/* _________________________________________________________________________ */

template <class T>
typename Lista<T>::Posicion Lista<T>::primero() const
{
  return cab;
}

/* _________________________________________________________________________ */

template <class T>
typename Lista<T>::Posicion Lista<T>::final() const
{
  return fin;
}

/* _________________________________________________________________________ */

template <class T>
typename Lista<T>::Posicion Lista<T>::siguiente(const Posicion p) const
{
  assert (p != final());

  return p->siguiente;
}

/* _________________________________________________________________________ */

template <class T>
typename Lista<T>::Posicion Lista<T>::anterior(const Posicion p) const
{
  assert(p != primero());

  Posicion q;
  for (q = cab;
       (q->siguiente != 0) && (q->siguiente != p);
       q = q->siguiente)
    ;  // Cuerpo vacío
  return q;
}

/* _________________________________________________________________________ */

template <class T>
void Lista<T>::hacer_nula()
{
  if (!vacia())
    {
      Posicion p = cab->siguiente;
      while (p != 0)
	{
	Posicion  q = p;
	  p = p->siguiente;
	  delete q;
	}
    }
  cab->siguiente = 0;
  num_elem = 0;
  fin = cab;
}

/* _________________________________________________________________________ */

template <class T>
Lista<T>::~Lista()
{
  Posicion p, q;
  if (!vacia())
    {
      p = cab->siguiente;
      while (p != 0)
	{
	  q = p;
	  p = p->siguiente;
	  delete q;
	}
    }
  delete cab;
}


