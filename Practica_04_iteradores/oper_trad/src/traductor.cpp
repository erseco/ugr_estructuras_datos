/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A. Traductor
 *
 ******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "traductor.h"

using namespace std;

vector<string> Traductor::GetTraducciones(string p)
{

    Palabra pal = datos[p];

    vector<string> result;

    for (Palabra::const_iterator it=pal.begin(); it != pal.end(); ++it)
        result.push_back(*it);


    return result;
}

void Traductor::inserta(string key, string value)
{
        datos[key].add(value);
}


istream& operator>> (istream& is, Traductor& t)
{
    // Recorremos el stream
    while (is)
    {

        string palabra;

        // Obtenemos la palabra
        getline(is, palabra, ';');

        // Bandera para salir del bucle cuando se llegue al salto de linea
        // se utiliza este sistema para no usar break
        bool salir = false;

        // Recorre el stream
        while (!salir && is)
        {
            string translation;

            // Obtenemos la siguiente palabra (usamos como separador el punto y coma)
            getline(is, translation, ';');


            // Si detectamos un salto de linea...
            if (is.peek() == '\n')
            {
                // ...obtenemos el siguiente caracter (salto) y salimos del bucle
                is.get();
                salir = true;
            }

            // Agregamos la traduccion a la colección de traducciones ya que [] si no existe lo crea
            t.datos[palabra].add(translation);

        }
    }

    // Devolvemos la referencia al flujo
    return is;
}
