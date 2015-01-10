/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  T.D.A. Palabra
 *
 ******************************************************************************/

#include "palabra.h"

using namespace std;

void Palabra::add(string value)
{
    translations.insert(value);
}