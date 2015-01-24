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

	// Recorremos todo el arbol...
	for (ArbolGeneral<info>::iter_preorden it = datos.begin(); it!=datos.end(); ++it)
	{
		char c_tree = (*it).c; // Caracter actual del arbol

		// ...buscando el caracter
		if (c_tree == tolower(c))
			apariciones++; // Si está incrementamos el contador
	}

	return apariciones;
}

vector<string> Diccionario::PalabrasLongitud(int longitud)
{
	vector<string> palabras;

	for (iterator it_dic = begin(); it_dic != end(); ++it_dic)
	{
		if ((*it_dic).size() == longitud)
			palabras.push_back(*it_dic);

	}

	return palabras;

}

/**
 * @brief Implementación del metodo buscar
 * @details Notese que se ha implementado de dos formas diferentes
 *
 * @param palabra palabra a buscar
 * @return true si la palabra está en el diccionario
 */
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

	// NOTA!! Se ha dejado la primera implementación del metodo, pero nunca alcanzará
	// esta sección ya que siempre saldrá por el return superior
	// la implemtacion de abajo está solo con fines comparativos de la diferencia
	// entre usar iteradores o usar el arbol a pelo
	//
	// MOTODO 1 (buscando) (mas engorroso)
	// recorremos las letras de origen
	//
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
	//
	//     una vez finalizadas las letras, si en la ultima pone final es que está
	ArbolGeneral<info>::iter_preorden it = datos.begin();
	// Incrementamos el iterador para que se vaya al primer nivel
	++it;
	for (int i=0; i < palabra.size(); i++)
	{
		char letra = palabra[i];
		ArbolGeneral<info>::Nodo n = &it; // VER NOTA!!!
		bool salir = false;
		while (!salir && n!=0)
		{
			if ((*it).c == letra) // VER NOTA!!!
			{
				if ((*it).final && i == palabra.size()-1) // VER NOTA!!!
				    return true;
				else
				{
				    ++it;
				    salir = true; // VER NOTA!!!
				}
			}
			else if (datos.hermanoderecha(&it) == 0)
			{
				return false; // VER NOTA!!!
			}
			else
			{
				n = datos.hermanoderecha(&it);
				it = ArbolGeneral<info>::iter_preorden(n);
			}
		}

	}
	return false; // VER NOTA!!!
}

void Diccionario::insertar_cadena( string palabra, int i, ArbolGeneral<info>::Nodo n)
{

	ArbolGeneral<info>::Nodo p,nuevo_nodo;
	info x;


	if (i == palabra.size()) // Si es la siguiente a la última letra...
	{
		// ...hemos llegado al final,  así que marcamos la letra
		datos.etiqueta(n).final = true;
	}
	else
	{
		bool salir = false;
		p= datos.hijomasizquierda(n);
		while ( p!=0 && !salir)
		{
			x = datos.etiqueta(p);
			if (x.c == palabra[i])
				salir = true;
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

		// Si el nivel es 0 es que estamos al final del arbol (ha vuelto a a la raiz)
		if (level_actual == 0)
		{
			// ...ponemos el iterador en situacion de .end()
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

