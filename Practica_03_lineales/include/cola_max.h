/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Cabecera Clase Cola_max
 *
 *  Este fichero llama a los ficheros *_cola.h *_lista.h o _vd.h segun lo definido
 *  en la variable CUAL_COMPILA
 *
 ******************************************************************************/

#ifndef __COLA_MAX
#define __COLA_MAX

#include <iostream>
#include <pila.h>

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


class Cola_max
{

private:
  /**
    * @brief Rep de cola_max
    *
    * Guardamos los datos en un pila de tipo elemento
    * En este caso no hay invariante de la representación ya que
    * todo descansa en la clase pila
    *
    */
    Pila<elemento> datos;

public:

    /**
     * @brief Indica si la pila está vacia
     * @return Un valor booleano, true si la pila esta vacia, false si contiene
     * al menos un elemento
     */
    bool vacia() const
    {
      return datos.vacia();
    }

    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(int valor);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const
    {
      return datos.num_elementos();
    }

    /**
     * @brief Devuelve el ultimo elemento de la pila
     * @return Un elemento
     */
    elemento tope();

};

#include <cola_max.cpp>

#endif
