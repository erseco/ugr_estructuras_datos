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

#include <cstring>

#include <vector>
#include <string>


#include <algorithm> // Utilizado para el sort

#include "Diccionario.h"
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;

struct MyStringLengthCompare
{
    bool operator () (const std::string & p_lhs, const std::string & p_rhs)
    {
        const size_t lhsLength = p_lhs.length() ;
        const size_t rhsLength = p_rhs.length() ;

        if(lhsLength == rhsLength)
        {
            return (p_lhs > p_rhs) ; // when two strings have the same
                                     // length, defaults to the normal
                                     // string comparison
        }

        return (lhsLength > rhsLength) ; // compares with the length
    }
} ;

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
	Diccionario diccionario;
	f_dicccionario >> diccionario;
	// ----- FIN DICCIONARIO

	// ----- LETRAS
	ConjuntoLetras conjunto;
	f_letras >> conjunto; // Cargamos las letras en memoria.

	BolsaLetras bolsa;
	conjunto >> bolsa; // Llenamos la bolsa de letras en base a las veces que se tiene que repetir cada letra

	// Generamos las letras con las que jugaremos:
	int numero_letras = atoi(argv[3]);

	char type;
	do
	{
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


		// letras.clear();

		// Letra l_a('A', 12, 1);
		// Letra l_d('D', 5, 2);
		// Letra l_t('T', 4, 1);
		// Letra l_n('N', 5, 1);

		// cout << "FIJO: \tA\tD\tT\tN no encuentra 'ta'" << endl;

		// letras.push_back(l_a);
		// letras.push_back(l_d);
		// letras.push_back(l_t);
		// letras.push_back(l_n);



		string palabra;
		for (int i=0; i<letras.size(); i++)
		{
			Letra l = letras[i];
			palabra.push_back(tolower(*l));
		}

		sort(palabra.begin(), palabra.end());



		string solucion_usuario;
		cout << "Dime tu solucion:";
		cin >> solucion_usuario;

		if (solucion_usuario.size() > numero_letras)
			cout << RED <<"TRAMPOSO!! La palabra introducida es mayor a la cantidad de letras proporcionadas" << BLACK << endl;
		else
		{

			bool ilegal = false;
			for (int i=0; i<solucion_usuario.size(); i++)
			{
				char letra = solucion_usuario[i];
				if (palabra.find(letra) == string::npos)
				{
					ilegal = true;
				}
			}

			if (ilegal)
				cout << RED <<"TRAMPOSO!! Has usado letras fuera de la secuencia" << BLACK << endl;

			else if (!diccionario.Esta(solucion_usuario))
				cout << RED <<"Esa palabra no existe" << BLACK << endl;
			else
				cout << BLUE << solucion_usuario << "\tPuntuacion: " << conjunto.puntuacion(solucion_usuario) << BLACK << endl;

		}


		// BUSCAMOS LAS LETRAS

		// Basado en la explicacion de pedro reina
		// La idea clave es esta: se parte de un diccionario con las palabras válidas.
		// Se eligen las de nueve letras (luego de ocho, siete, etc.).
		// Se colocan por orden alfabético las letras de cada palabra (por ejemplo, de la palabra "nutritivo" obtenemos "iinorttuv").
		// Se guardan todas las palabras clasificadas y normales; valdría un archivo de texto, aunque es más cómodo usar un gestor
		// de bases de datos. Ahora nos dan nueve letras para buscar una palabra con ellas. Colocamos las letras por orden alfabético
		// y buscamos en la lista si aparece esa combinación. Si aparece, damos las palabras de la que partió.
		// Por ejemplo, a partir de las letras "ntviriuto" obtenemos "iinorttuv", que tiene como palabra asociada "nutritivo".



		set<string, MyStringLengthCompare> encontradas;

		cout << "Mis soluciones son:" << endl;
		bool alguna = false;

		for (int i=numero_letras; i>0; i--)
		{
			vector<string> v = diccionario.PalabrasLongitud(i);

			vector<string>::iterator it = v.begin();
			for (; it!=v.end();++it)
			{

				string palabra_vector = *it;

				sort(palabra.begin(), palabra.end());
				sort(palabra_vector.begin(), palabra_vector.end());


				// if(palabra.substr(0, palabra_vector.size()) == palabra_vector)
				// {
				// 	alguna = true;
				// 	//cout << GREEN << *it << "\tPuntuacion: "  << conjunto.puntuacion(*it) << BLACK << endl;
				// 	cout << GREEN << *it << "\tPuntuacion: "  << conjunto.puntuacion(*it) << " - " << palabra_vector << " palabra: " << palabra << BLACK << endl;



				// }
				// // else if ((*it).size() == 2)
				// // {
				// // 	cout << RED << *it << " - " << palabra_vector << " palabra: " << palabra << BLACK << endl;
				// // }
				// else
				// {
					do
					{


						if(palabra.substr(0, palabra_vector.size()) == palabra_vector)
						{
							alguna = true;
							//cout << GREEN << *it << "\tPuntuacion: "  << conjunto.puntuacion(*it) << BLACK << endl;
							// cout << GREEN << *it << "\tPuntuacion: "  << conjunto.puntuacion(*it) << " - " << palabra_vector << " palabra: " << palabra << BLACK << endl;


							encontradas.insert(*it);


						}


				  	} while (next_permutation(palabra.begin(), palabra.end()) );

				// }


			}
		}

		if (encontradas.size() > 0)
		{

			set<string>::iterator it = encontradas.begin();
			for (;it!=encontradas.end();++it)
				cout << GREEN << *it << "\tPuntuacion: "  << conjunto.puntuacion(*it) << BLACK << endl;



		}
		else
			cout << RED <<"No se encontró ninguna palabra con esas letras" << BLACK << endl;

		// if (!alguna)
		// 	cout << RED <<"No se encontró ninguna palabra con esas letras" << BLACK << endl;
		// FIN DE LA BUSQUEDA DE LETRAS





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


		cout << "¿Quieres seguir jugando[S/N]?";
		cin >> type;
		cout << endl; // metemos un salto
	}
	while (!cin.fail()  && tolower(type) !='n');



	return 0;

}