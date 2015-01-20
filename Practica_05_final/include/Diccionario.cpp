/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Implementación del T.D.A Diccionario
 *
 ******************************************************************************/

Diccionario::Diccionario()
{
	// Creamos el nodo que sera el raiz, le ponemos '*' por poner algo
	info nodo_raiz('*', false);
	datos = ArbolGeneral<info>(nodo_raiz);
}


int Diccionario::getApariciones(const char c)
{
	int apariciones = 0;

	ArbolGeneral<info>::iter_preorden it;

	// Recorremos todo el arbol...
	for (it = datos.begin(); it!=datos.end(); ++it)
	{
		char c_tree = (*it).c; // Caracter actual del arbol
		// cout << c_tree << " - " << tolower(c) << endl;

		// ...buscando el caracter
		if (c_tree == tolower(c))
			apariciones++; // Si está incrementamos el contador
	}

	return apariciones;
}

vector<string> Diccionario::PalabrasLongitud(int longitud)
{
	vector<string> palabras;



	// ArbolGeneral<info>::iter_preorden it;

	// for (it = datos.begin(); it!=datos.end(); ++it)
	// {
	// 	cout << "Letra: " << (*it).c << " nivel: " << it.getlevel() << endl;
	// }



	iterator it_dic = begin();

	for (it_dic = begin(); it_dic != end(); ++it_dic)
	{

		string palabra = *it_dic;

		if (palabra.size() == longitud)
			palabras.push_back(palabra);

		// cout << "plabra: " << *it_dic << endl;

	}




	return palabras;

}

bool Diccionario::Esta(string palabra)
{

	// METODO 2 (iteradores) (mas sencillo)

	for (iterator it_dic = begin(); it_dic != end(); ++it_dic)
	{
		string cad = *it_dic;

		if (palabra == cad)
			return true;
	}

	return false;




	// MOTODO 1 (buscando) (mas engorroso)

	// recorremos las letras de origen

	//     para cada Letra
	//         esta en el iterador actual?
	//             si
	//                 incrementamos iterador a la siguiente letra y repetimos
	//             no
	//                 tiene hermano?
	//                    si
	//                         vamos al hermano
	//                     no
	//                         la letra no está


	//     una vez finalizadas las letras, si en la ultima pone final es que está

	ArbolGeneral<info>::iter_preorden it = datos.begin();

	// Incrementamos el iterador para que se vaya al primer nivel
	++it;

	for (int i=0; i < palabra.size(); i++)
	{
		char letra = palabra[i];
		ArbolGeneral<info>::Nodo n = &it;

		// cout << "L:" << letra << endl;

		bool salir = false;

		while (!salir && n!=0)
		{

			// cout << "dep---:" << letra << " it:" << (*it).c << endl;

			if ((*it).c == letra)
			{

				if ((*it).final && i == palabra.size()-1)
				    return true;
				else
				{
				    ++it;
				    salir = true;
				}

			}
			else if (datos.hermanoderecha(&it) == 0)
			{
				return false;
			}
			else
			{
				n = datos.hermanoderecha(&it);
				it = ArbolGeneral<info>::iter_preorden(n);
			}



		}

	}

	return false;

}

void Diccionario::insertar_cadena( string palabra, int i, ArbolGeneral<info>::Nodo n)
{

	ArbolGeneral<info>::Nodo p,nuevo_nodo;
	info x;
	int salir = 0;

	if (i == palabra.size()) // Si es la siguiente a la última letra...
	{
		// ...hemos llegado al final,  así que marcamos la letra
		datos.etiqueta(n).final = true;
	}
	else
	{
		p= datos.hijomasizquierda(n);
		while ( p!=0 && !salir)
		{
			x = datos.etiqueta(p);
			if (x.c == palabra[i])
				salir = 1;
			else
				p=datos.hermanoderecha(p);
		}
		if (salir)
			insertar_cadena(palabra,++i,p);
		else
		{
			char letra = palabra[i];
			// Realmente no es necesario, ya que se re-marca al final de la palabra
			bool ultima = (i == palabra.size() - 1);

			// Creamos un nuevo info (letra)
			x = info(letra, ultima);

			// Creamos un nuevo arbol con el nodo nuevo
			ArbolGeneral<info> aux(x);

			// Lo insertamos
			datos.insertar_hijomasizquierda(n, aux);

			// Obtenemos el nodo recien insertado
			nuevo_nodo = datos.hijomasizquierda(n);

			// cout << "N:" <<datos.etiqueta(n).c << "NUEVO:" << datos.etiqueta(nuevo_nodo).c << endl;

			insertar_cadena(palabra,++i,nuevo_nodo);
		}
	}
}


istream& operator>> (istream & is,Diccionario &D)
{
	string palabra;

	// Vamos obteniendo palabras
	while (getline(is, palabra))
	{
		D.insertar_cadena(palabra,0, D.datos.raiz());
	}

	// Devolvemos la referencia al flujo
	return is;
}

ostream & operator<<(ostream & os, Diccionario &D)
{
	Diccionario::iterator it = D.begin();

	for (; it!=D.end(); ++it)
	{
		os << (*it) << endl;
	}

	// Devolvemos la referencia al flujo
	return os;
}

Diccionario::iterator::iterator()
{
	arbol = ArbolGeneral<info>();
	it = arbol.end();
	cad = "";  //mantiene los caracteres desde el nivel 1 hasta donde se encuentra it.
	level = 0;
}

Diccionario::iterator::iterator(const Diccionario::iterator & i) :  arbol(i.arbol), it(i.it), cad(i.cad), level(i.level) {}

Diccionario::iterator::iterator(Diccionario dic)
{
	arbol = dic.datos;
	it =  arbol.begin();
	cad = "";
	level = 0;
}

string Diccionario::iterator::operator*()
{
	return cad;
}

Diccionario::iterator & Diccionario::iterator::operator ++()
{

	if ((*it).final)
	{
		++it;

		int level_actual = it.getlevel();

		if (level_actual == 0)
		{

			// cout << "FIN" << endl;
		    //cout << "LLega al final trycatch" << endl;
			arbol = ArbolGeneral<info>();
			it = arbol.begin();
			cad = "";  //mantiene los caracteres desde el nivel 1 hasta donde se encuentra it.
			level = 0;

			return *this;


		}
		if (level_actual > level)
		{
			cad.push_back((*it).c);
			level++;

			//cout << "final - incremento nivel: " << level << endl;

		}
		else if (level_actual <= level)
		{

			int diff =  level - level_actual;

			// Si da un numero negativo es porque estamos en el final del arbol
			int caracteres_a_borrar = cad.size() - diff -1;

			cad.erase(caracteres_a_borrar);

			cad.push_back((*it).c);

			level = level_actual;

		}

	}

	while (!(*it).final)
	{
		++it;

		int level_actual = it.getlevel();

		if (level_actual > level)
		{
			cad.push_back((*it).c);
			level++;

			//cout << "incremento nivel: " << level << endl;
		}

	}

	return *this;
}

bool Diccionario::iterator::operator ==(const Diccionario::iterator &i)
{
	return it == i.it;
}

bool Diccionario::iterator::operator !=(const Diccionario::iterator &i)
{
	return it != i.it;
}


ostream & Diccionario::iterator::operator<<(ostream & os)
{
	os << cad;
	return os;
}

Diccionario::iterator Diccionario::begin()
{
	return iterator(*this);
}

Diccionario::iterator Diccionario::end()
{
	return iterator();
}

