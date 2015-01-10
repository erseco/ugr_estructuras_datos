/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 ******************************************************************************/

#include <cassert>

elemento Pila_max::tope()
{
  // Controlamos que haya al menos un elemento
  assert(num_elementos()>0);
  return datos[num_elementos()-1];
}

/* _________________________________________________________________________ */

void Pila_max::poner(int valor)
{
  elemento nuevo;
  nuevo.ele = valor;

  if (vacia())
  {
    nuevo.maximo = valor;
  }
  else
  {
    elemento anterior = tope();
    nuevo.maximo = (valor > anterior.maximo) ? valor : anterior.maximo;
  }

  datos.add(nuevo);
}