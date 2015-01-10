/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 ******************************************************************************/

void Pila_max::quitar()
{
  Cola<elemento> aux;

  int size = num_elementos() -1;

  // Cogemos todos menos el ultimo
  for (int i = 0; i<size; i++)
  {
    aux.poner(datos.frente());
    datos.quitar();
  }

  datos = aux;

}

/* _________________________________________________________________________ */

elemento Pila_max::tope()
{
  Cola<elemento> aux = datos;

  elemento el = aux.frente();

  while (!aux.vacia())
  {
      el.ele = aux.frente().ele;
      el.maximo = aux.frente().maximo;
      aux.quitar();
  }

  return el;
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
  datos.poner(nuevo);
}

