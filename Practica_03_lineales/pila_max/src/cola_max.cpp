/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 ******************************************************************************/

// NOTA: Funcion auxiliar para depurar que me pinta el contenido de la pila
// en pantalla, se pasa por copia así que se puede modificar
void PintaPila(Pila<elemento> aux)
{
  while (!aux.vacia())
  {
      cout << " - " << aux.tope().ele << "(" << aux.tope().maximo << ")" << endl;
      aux.quitar();
  }
}


void Cola_max::quitar()
{
  // En este caso hay que quitar el primero, así que sacamos
  Pila<elemento> aux;

  int size = num_elementos() -1;

  // Cogemos todos menos el ultimo
  for (int i = 0; i<size; i++)
  {
    aux.poner(datos.tope());
    datos.quitar();
  }


  // Ojo, ahora hay que invertir la pila!!
  Pila<elemento> invertida;
  while (!aux.vacia())
  {
      invertida.poner(aux.tope());
      aux.quitar();
  }

  datos = invertida;

}

/* _________________________________________________________________________ */

elemento Cola_max::tope()
{
  // El tope en este caso
  Pila<elemento> aux = datos;

  elemento el = aux.tope();

  while (!aux.vacia())
  {
      el.ele = aux.tope().ele;
      el.maximo = aux.tope().maximo;
      aux.quitar();
  }

  return el;
}

/* _________________________________________________________________________ */

void Cola_max::poner(int valor)
{
  // Hay que agregarlo al final
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


