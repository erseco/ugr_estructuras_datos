/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado <erseco@correo.ugr.es>
 * --------------------------------------------------------
 *
 *	Este programa ordena un vector aleatorio usando el metodo de la burbuja
 *
 *	Para compilar: g++ -Ofast ordenacion.cpp -o ordenacion
 *
 ******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

/**
 * @brief Ordena un vector por el método de la burbuja
 * @details [long description]
 *
 * @param v: vector de elementos. Debe tener n elementos. Es modificado
 * @param n: numero de elementos. num_elem > 0
 */
inline void ordenar(int *v, int n) {
	for (int i=0; i<n-1; i++)
		for (int j=0; j<n-i-1; j++)
			if (v[j]>v[j+1]) {
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
}

/**
 * @brief Punto de entrada al programa
 *
 * @param argc numero de parametros
 * @param argv vector con los parametros
 *
 * @return un entero con el resultado de la ejecución
 */
int main(int argc, char * argv[])
{

	// Se espera un parametro obligatorio (tamaño vector) y otro opcional (modo)
	if (argc < 2 || argc > 3)
	{
		cerr << "Formato " << argv[0] << " <num_elem> [0=random|1=mejor|2=peor]" << endl;
		return -1;
	}

	int n = atoi(argv[1]);

	int modo = 0;

	// Si hemos pasado el 3er parametro (opcional) lo extraemos como indicador de modo
	if (argc == 3)
		modo = atoi(argv[2]);

	int * T = new int[n];
	assert(T);

	srandom(time(0));

	// Llenamos el vector segun el modo
	if (modo == 0)
		for (int i = 0; i < n; i++)
			T[i] = random();
	else if (modo == 1)
		for (int i = 0; i < n; i++)
			T[i] = i; 			// Mejor
	else
		for (int i = 0; i < n; i++)
			T[i] = (n - i); 		// Peor


	const int TAM_GRANDE = 10000;
	const int NUM_VECES = 1000;

	if (n > TAM_GRANDE)
	{
		clock_t t_antes = clock();

		ordenar(T, n);

		clock_t t_despues = clock();

		cout << n << "  " << ((double)(t_despues - t_antes)) / CLOCKS_PER_SEC << endl;
	} else
	{
		int * U = new int[n];
		assert(U);

		for (int i = 0; i < n; i++)
			U[i] = T[i];

		clock_t t_antes_vacio = clock();
		for (int veces = 0; veces < NUM_VECES; veces++)
		{
			for (int i = 0; i < n; i++)
				U[i] = T[i];
		}
		clock_t t_despues_vacio = clock();

		clock_t t_antes = clock();
		for (int veces = 0; veces < NUM_VECES; veces++)
		{
			for (int i = 0; i < n; i++)
				U[i] = T[i];
			ordenar(U, n);
		}
		clock_t t_despues = clock();
		cout << n << " \t  "  << ((double) ((t_despues - t_antes) -  (t_despues_vacio - t_antes_vacio))) / (CLOCKS_PER_SEC * NUM_VECES) << endl;

		delete [] U;
	}

	delete [] T;

	return 0;
};
