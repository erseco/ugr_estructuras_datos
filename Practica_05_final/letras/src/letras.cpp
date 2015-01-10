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
#include "traductor.h"

using namespace std;

/**
 * @brief Obtiene un traductor invertido
 *
 * @param t_origen Un traductor
 * @param t_destino traductor de destino (por referencia)
 *
 */
void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino)
{

    Traductor::const_iterator it;

    // Recorremos el traductor de origen
    for (it=t_origen.begin(); it!=t_origen.end();++it)
    {

        Palabra::const_iterator it_d=(*it).second.begin();

        //Recorremos sus palabras
        for (; it_d!=(*it).second.end();++it_d)
        {

            // Aqui se invierte key y value
            string key   = *it_d;
            string value = (*it).first;

            // Vamos insertando en destino
            t_destino.inserta(key, value);
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
    if (argc!=2 && argc!=3)
    {
        cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
        cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
        return 0;
    }

    ifstream f (argv[1]);
    if (!f)
    {
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    Traductor t_ori;

    f>>t_ori; //Cargamos en memoria, en el traductor.
    Traductor t_des;

    GetTraductorInverso(t_ori,t_des);

    if (argc==2)
        ImprimeTraductor(t_des,cout);
    else
    {
        ofstream fout(argv[2]);
        if (!fout)
        {
            cout<<"No puedo crear el fichero "<<argv[2]<<endl;
            return 0;
        }
        ImprimeTraductor(t_des,fout);
    }
}