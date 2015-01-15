/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Este programa construye palabras de longitud mayor (o puntuacion mayor ) a
 *  partir de una serie de letras seleccionadas de forma aleatoria.
 *
 ******************************************************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <ctime>    // Recursos para medir tiempos

#include <vector>
#include <string>

// #include "Diccionario.h"
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;

// /**
//  * @brief Obtiene un traductor invertido
//  *
//  * @param t_origen Un traductor
//  * @param t_destino traductor de destino (por referencia)
//  *
//  */
// void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino)
// {

//     Traductor::const_iterator it;

//     // Recorremos el traductor de origen
//     for (it=t_origen.begin(); it!=t_origen.end();++it)
//     {

//         Palabra::const_iterator it_d=(*it).second.begin();

//         //Recorremos sus palabras
//         for (; it_d!=(*it).second.end();++it_d)
//         {

//             // Aqui se invierte key y value
//             string key   = *it_d;
//             string value = (*it).first;

//             // Vamos insertando en destino
//             t_destino.inserta(key, value);
//         }
//     }

// }

// void ImprimeTraductor(const Traductor &T,ostream &os)
// {
//     Traductor::const_iterator it;
//     for (it=T.begin(); it!=T.end();++it)
//     {
//         os<<(*it).first<<";";
//         Palabra::const_iterator it_d;
//         for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d)
//             os<<(*it_d)<<";";
//         os<<endl; // Faltaba el fin de linea
//     }
// }


int main(int argc, char * argv[])
{
    if (argc!=5)
    {
        cout<<".-Dime el nombre del diccionario "<<endl;
        cout<<".-Dime el nombre de fichero de letras "<<endl;
        cout<<".-Numero de letras a generar "<<endl;
        cout<<".-Modo de juego (L: palabras mas larga, P: mayor puntuacion)"<<endl;
        return 1;
    }

    ifstream f_dicccionario (argv[1]);
    if (!f_dicccionario)
    {
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    ifstream f_letras (argv[2]);
    if (!f_letras)
    {
        cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return 0;
    }


    // ----- DICCIONARIO


    // ----- FIN DICCIONARIO

    // ----- LETRAS
    ConjuntoLetras conjunto;
    f_letras >> conjunto; // Cargamos las letras en memoria.

    BolsaLetras bolsa;
    conjunto >> bolsa; // Llenamos la bolsa de letras en base a las veces que se tiene que repetir cada letra

    // Generamos las letras con las que jugaremos:
    int numero_letras = atoi(argv[3]);

    cout << "Las letras son:\t";
    srand(time(0));            // Inicialización del generador de números pseudoaleatorios
    vector<Letra> letras;

    for (int i=0; i<numero_letras; i++)
    {


        int rnd = rand() % bolsa.size();      // Generar aleatorio [0,size]

        Letra l = bolsa[rnd];

        cout << *l << '\t';

        letras.push_back(l);


    }
    cout << endl;


    string solucion_usuario;
    cout << "Dime tu solucion:";
    cin >> solucion_usuario;


    if (strcmp(argv[4], "L") == 0)
    {
        // Modo longitud
    }
    else if (strcmp(argv[4], "P") == 0)
    {
        // Modo puntos
    }
    else
    {
        // Modo incorrecto
        cout<<"Error: El modo es incorrecto, debe ser L o P"<<endl;
        return 0;
    }






    return 0;

}