/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Cabecera Clase Pila_max
 *
 *  Este fichero llama a los ficheros *_cola.h *_lista.h o _vd.h segun lo definido
 *  en la variable CUAL_COMPILA
 *
 ******************************************************************************/

using namespace std;

/**
 * @brief TDA Elemento
 *
 * Es un contenedor donde almacenaremos los valores a agregar a la pila
 * Se compone de dos variables, el elemento en si como un entero y el valor máximo
 * introducido hasta el momento, tambien de tipo entero
 *
 *
 */
struct elemento
{
    int ele;    // elemento a almacenar
    int maximo; // el máximo

    /**
     * @brief Sobrecarga del operador <<
     * @details pintal elemento y su máximo de la siguiente forma:
     * elemento (maximo)
     *
     * @param os stream de salida
     * @param e elemento
     * @return la misma instancia del ostream para poder redireccionar varias salidas
     */
    friend ostream& operator<<(ostream &os, const  elemento& e)
    {
        // Volcamos la información que queramos en el ostream
    	os << e.ele << " (" << e.maximo << ")" << endl;

        // Lo devolvemos
    	return os;

    };
};

// la variable CUAL_COMPILA nos define que tipo de implementación vamos a usar
#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
	#include <pila_max_vd.h>
#elif CUAL_COMPILA==2
	#include <pila_max_lista.h>
#else
	#include <pila_max_cola.h>
#endif

