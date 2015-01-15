#ifndef __PILA
#define __PILA

/***********************************************************************/
/*************  TDA PILA DE NODOS                                      */
/***********************************************************************/

#include "td_arb_g.h"

typedef struct  pila{
       tnodo nodo;
       struct  pila *ss;
       }*tpila;

 
tpila Crear_P ( void );

void Destruir_P( tpila P );

int Push( tnodo n, tpila P );

tnodo Top( tpila P );

tnodo Pop( tpila P );

int Vacia_P( tpila P );

#endif

      

 




