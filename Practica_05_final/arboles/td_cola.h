
/***********************************************************************/
/*************  TDA COLA DE NODOS                                      */
/***********************************************************************/

#ifndef __COLA 
#define __COLA 

#include "td_arb_g.h"

typedef struct celda{
       tnodo nodo;
       struct celda *ss;
       }tcelda;

typedef struct cola{
       struct celda *ini;
       struct celda *fin;
	} *tcola;

tcola Crear_C ( void );

void Destruir_C( tcola c);

int  Encolar( tnodo n, tcola c);

tnodo Frente( tcola c );

tnodo Desencolar( tcola c );
 
int Vacia_C( tcola c );

#endif

 
