/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A Resultado
 *
 ******************************************************************************/

#ifndef __Resultado_h__
#define __Resultado_h__

#include <string>

using namespace std;

class Resultado
{

private:
	string palabra;	// La palabra en si
	int puntuacion; // La puntuacion.

public:
	// Constructor por defecto
	Resultado() : palabra(""), puntuacion(0) {}

	// Constructor con parametros
	Resultado(string pal, int p) : palabra(pal), puntuacion(p) {}

	// Funcion para pintar el resultado
	friend ostream & operator<<(ostream & os, const Resultado &r)
	{
		os << r.palabra << "\t\tPuntuacion:" << r.puntuacion;
		return os;
	}

    /**
     * @brief [brief description]
     * @details [long description]
     *
     * @param L1 [description]
     * @param L2 [description]
     *
     * @return [description]
     */
    struct cmp_pal
    {
        bool operator()(const Resultado &L1 , const Resultado &L2)
        {
            return (L1.palabra.size() > L2.palabra.size()) ? true : false;
        }
    };

    struct cmp_pts
    {
        bool operator()(const Resultado &L1 , const Resultado &L2)
        {
            return (L1.puntuacion > L2.puntuacion) ? true : false;
        }
    };


    };



#endif