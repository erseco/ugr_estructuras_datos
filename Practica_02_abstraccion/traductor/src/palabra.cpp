/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Clase Palabra
 *
 ******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "palabra.h"

using namespace std;

string Palabra::GetWord()
{
    return word;
}

vector<string> Palabra::GetTranslations()
{
    return translations;
}

istream& operator>> (istream& is, Palabra& p)
{
    // Obtenemos la primera palabra y la asignamos a la variable
    // (utilizamos como separador el punto y coma)
    getline(is, p.word, ';');

    // Bandera para salir del bucle cuando se llegue al salto de linea
    // se utiliza este sistema para no usar break
    bool salir = false;

    // Recorre
    while (!salir && is)
    {
        string translation;

        // Obtenemos la siguiente palabra (usamos como separador el punto y coma)
        getline(is, translation, ';');

        // Agregamos la traduccion a la colección de traducciones
        p.translations.push_back(translation);

        // Si detectamos un salto de linea...
        if (is.peek() == '\n')
        {
            // ...obtenemos el siguiente caracter (salto) y salimos del bucle
            is.get();
            salir = true;
        }

    }

    // Devolvemos la referencia al istream
    return is;

}