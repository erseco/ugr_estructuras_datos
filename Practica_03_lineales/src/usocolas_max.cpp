/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Fichero para probar el TDA Cola_max (ejercicio adicional)
 *
 ******************************************************************************/
#include <iostream>
#include "cola_max.h"

using namespace std;

int main(){

  Cola_max c;
  int i;

  // De 10 a 0
  for ( i=10; i>=0 ; i--)
    c.poner(i);

  // De 0 a 10
  // for ( i=0; i<=10 ; i++)
  //   c.poner(i);

  while (!c.vacia() ){
    elemento x = c.tope();
    cout << x << endl;
    c.quitar();
  }

  return 0;
}
