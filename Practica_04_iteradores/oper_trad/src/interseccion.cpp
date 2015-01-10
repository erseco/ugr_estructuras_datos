/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  obtiene la interseccion dos traductores
 *
 *  por ejemplo pasandole spanish_english y french_english
 *  me generará un traductor con las palabras comunes en español y frances
 *  y pondrá su traducciones comunes en inglés
 *
 *
 ******************************************************************************/

#include <fstream>
#include <iostream>
#include "traductor.h"

using namespace std;

/**
 * @brief Obtiene la interseccion de dos traductores de origen
 *
 * @param t_origen_1 Un traductor
 * @param t_origen_2 Otro traductor
 * @param t_destino traductor de destino (por referencia)
 *
 * @pre ambos traductores de origen deberían estar realacionados en destino, es decir
 * que sea spanish_english french_english o similar
 */
void GeInterseccionTraductores(const Traductor & t_origen_1, Traductor & t_origen_2, Traductor & t_destino)
{

    Traductor::const_iterator it_1;

    // Recorremos el primer traductor de origen
    for (it_1=t_origen_1.begin(); it_1!=t_origen_1.end();++it_1)
    {
        string key   = (*it_1).first;

        // Buscamos la palabra "key" en el segundo traductor de origen
        Traductor::const_iterator it_2 = t_origen_2.buscar(key);

        if (it_2 != t_origen_2.end())
        {
            // Los dos traductors contienen esa palabra


            // Ahora buscaremos las traducciones coincidentes
            Palabra::const_iterator it_d_1 =(*it_1).second.begin();
            Palabra::const_iterator it_d_2 =(*it_2).second.begin();

            for (; it_d_1!=(*it_1).second.end();++it_d_1)
            {

                for (; it_d_2!=(*it_2).second.end();++it_d_2)
                {

                    if (*it_d_1 == *it_d_2)
                        t_destino.inserta(key, *it_d_1);

                }

            }


        }

    }

}

void ImprimeTraductor(const Traductor &T,ostream &os)
{
    Traductor::const_iterator it;
    for (it=T.begin(); it!=T.end();++it)
    {
        os<<(*it).first<<";";
        Palabra::const_iterator it_d;
        for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d)
            os<<(*it_d)<<";";
        os<<endl; // Faltaba el fin de linea
    }
}


int main(int argc, char * argv[])
{
    if (argc<3 || argc>4)
    {
        cout<<".-Dime los nombres de los ficehros a concatenar"<<endl;
        cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
        return 0;
    }

    ifstream f1 (argv[1]);
    if (!f1)
    {
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    ifstream f2 (argv[2]);
    if (!f2)
    {
        cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return 0;
    }

    Traductor t_ori_1;
    f1>>t_ori_1; //Cargamos en memoria, en el traductor.

    Traductor t_ori_2;
    f2>>t_ori_2; //Cargamos en memoria, en el traductor.


    Traductor t_des;

    GeInterseccionTraductores(t_ori_1, t_ori_2,t_des);

    if (argc==3)
        ImprimeTraductor(t_des,cout);
    else
    {
        ofstream fout(argv[3]);
        if (!fout)
        {
            cout<<"No puedo crear el fichero "<<argv[3]<<endl;
            return 0;
        }
        ImprimeTraductor(t_des,fout);
    }
}