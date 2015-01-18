/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  concatena dos traductores
 *
 *  por ejemplo pasandole spanish_english y english_french
 *  me generará un traductor spanish_french
 *
 ******************************************************************************/

#include <fstream>
#include <iostream>
#include "traductor.h"

using namespace std;

/**
 * @brief Concatena dos traductores de origen
 *
 * @param t_origen_1 Un traductor
 * @param t_origen_2 Otro traductor
 * @param t_destino traductor de destino (por referencia)
 *
 * @pre ambos traductores de origen deberían estar realacionados, es decir
 * que sea english_spanish spanish_french o similar
 */
void ConcatenarTraductores(const Traductor & t_origen_1, Traductor & t_origen_2, Traductor & t_destino)
{

    Traductor::const_iterator it;

    // Recorremos el traductor de origen
    for (it=t_origen_1.begin(); it!=t_origen_1.end();++it)
    {
        string key   = (*it).first;

        Palabra::const_iterator it_d;

        //Recorremos sus palabras
        for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d)
        {
            string value = *it_d;

            Traductor::const_iterator it_2 = t_origen_2.buscar(value);

            if (it_2 != t_origen_2.end())
            {

                Palabra::const_iterator it_3 = (*it_2).second.begin();

                for (;it_3 != (*it_2).second.end(); ++it_3)
                {
                    t_destino.inserta(key, *it_3);
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

    ConcatenarTraductores(t_ori_1, t_ori_2,t_des);

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