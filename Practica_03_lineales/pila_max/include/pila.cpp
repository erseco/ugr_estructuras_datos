/**
  * @file pila.cpp
  * @brief Implementación del TDA Pila
  *
  */
#include <cassert>
// #include <pila.h>  El codigo ya se incluye en pila.h

/* _________________________________________________________________________ */


template <class T>
Pila<T>::Pila(const Pila<T> & p)
{
  if (p.primera!=0) {
    Celda *orig=p.primera;
    Celda *nueva;
    primera=nueva= new Celda(orig->elemento,0);
    orig=orig->siguiente;
    while (orig!=0) {
      nueva->siguiente=new Celda(orig->elemento,0);
      nueva=nueva->siguiente;
      orig=orig->siguiente;
    }
  }
  else primera=0;
  num_elem=p.num_elem;
}

/* _________________________________________________________________________ */

template <class T>
Pila<T>::~Pila()
{
  Celda *aux;
  while (primera!=0) {
    aux= primera;
    primera=primera->siguiente;
    delete aux;
  }
}

/* _________________________________________________________________________ */

template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> & p)
{
  if (this!=&p) {
    Celda *aux;
    while (primera!=0) {
      aux= primera;
      primera=primera->siguiente;
      delete aux;
    }
    if (p.primera!=0) {
      Celda *orig=p.primera;
      Celda *nueva;
      primera=nueva= new Celda(orig->elemento,0);
      orig=orig->siguiente;
      while (orig!=0) {
        nueva->siguiente=new Celda(orig->elemento,0);
        nueva=nueva->siguiente;
        orig=orig->siguiente;
      }
    }
    num_elem=p.num_elem;
  }
  return *this;
}

/*_________________________________________________________________________ */

template <class T>
void Pila<T>::poner(const T & elem)
{
  primera= new Celda(elem,primera);
  num_elem++;
}

/* _________________________________________________________________________ */

template <class T>
void Pila<T>::quitar()
{
  assert(primera!=0);
  Celda *aux=primera;
  primera= primera->siguiente;
  delete aux;
  num_elem--;
}
