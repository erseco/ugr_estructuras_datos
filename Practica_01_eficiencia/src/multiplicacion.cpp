/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado <erseco@correo.ugr.es>
 * --------------------------------------------------------
 *
 *	Este programa multiplica dos vectores multidimensionales
 *	
 *	Para compilar: g++ -Ofast multiplicacion.cpp -o multiplicacion
 *
 ******************************************************************************/
	 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

/**
 * @brief Multiplica una matriz
 * @details [long description]
 * 
 * @param vr: vector de resultado. Debe tener n elementos. Es modificado
 * @param v1: vector de elementos. Debe tener n elementos. No es modificado
 * @param v2: vector de elementos. Debe tener n elementos. No es modificado
 * @param n: numero de elementos. num_elem > 0
 */
inline void multiplicacion(int **vr, int **v1, int **v2, int n) {

	for (int i = 0; i<n; i++)
		for (int j=0 ; j<n; j++)
			for (int k = 0; k < n; k++)
				vr[i][j]+=v1[i][k]*v2[k][j];


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

	if (argc != 2)
	{
		cerr << "Formato " << argv[0] << " <num_elem>" << endl;
		return -1;
	}

	int n = atoi(argv[1]);


// Reserva de memoria para matrices 
	int ** T1 = new int * [n];
	int ** T2 = new int * [n];
	int ** TR = new int * [n];
	
	for (int i=0; i<n; i++){
		T1[i]=new int [n]; 
		T2[i]=new int [n]; 
		TR[i]=new int [n];
	}
	
	// Comprobamos que se hayan creado los vectores, si no generaría una excepción
	assert(T1);
	assert(T2);
	assert(TR);
	
	srandom(time(0));

	// Se rellenan dos matrices con números aleatorios, y una tercera con todo ceros.
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++){ 
			T1[i][j] = random(); 
			T2[i][j] = random();
			TR[i][j] = 0; 		// Rellenar con 0
	}



	clock_t t_antes = clock();
	
	multiplicacion(TR, T1, T2, n);
	
	clock_t t_despues = clock();

	cout << n << "  " << ((double)(t_despues - t_antes)) / CLOCKS_PER_SEC << endl;


	delete [] T1;
	delete [] T2;
	delete [] TR;

	return 0;
};
