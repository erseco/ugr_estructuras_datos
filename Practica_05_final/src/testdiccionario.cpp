/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Este programa comprueba que funcione bien la clase diccionario
 *
 ******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"

int main(int argc, char * argv[])
{
	if (argc!=2)
	{
		cout<<"Los parametros son:"<<endl;
		cout<<"1.- El fichero con las palabras";

		return 0;
	}

	ifstream f(argv[1]);
	info ii(' ', false);
	cout<<"Cargando diccionario...."<<endl;
	Diccionario D;
	f>>D;
	cout<<"Leido el diccionario..."<<endl;
	cout<<D;

	int longitud;

	cout<<"Dime la longitud de las palabras que quieres ver" << endl;
	cin>>longitud;
	vector<string> v=D.PalabrasLongitud(longitud);

	cout<<"Palabras de Longitud "<<longitud<<endl;
	for (unsigned int i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	 string p;
	 cout<<"Dime una palabra: ";
	 cin>>p;

	if (D.Esta(p))
		cout << GREEN <<"Sí esa palabra existe" << BLACK << endl;
	else
		cout << RED <<"Esa palabra no existe" << BLACK << endl;

}



