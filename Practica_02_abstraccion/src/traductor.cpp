/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 * 
 *  Clase Traductor
 *  
 ******************************************************************************/

#include <cstdlib>
#include <iostream> 
#include <iomanip> 
#include "traductor.h"

using namespace std;

vector<string> Traductor::GetTraducciones(string word)
{

    vector<string> result;
    bool salir = false;

    // Recorremos la lista de palabras
    for (int i=0; !salir && i<words.size(); i++)
    {

        // Comprobamos palabra a palabra
        if (words[i].GetWord() == word)
        {
            // Asignamos el resultado y salimos del bucle
            result = words[i].GetTranslations();
            salir = true;
        }


    }

    // Devolvemos el resultado
    return result;

}

istream& operator>> (istream& is, Traductor& t) 
{

    // Recorremos el stream
    while (is)
    {

        // Llenamos una palabra (usamos la sobrecarga del operador >> de palabra)
        Palabra pal;

        is >> pal;

        // Lo guardamos en la colección de palabras
        t.words.push_back(pal);

    }

    // Devolvemos la referencia al flujo
    return is;

}