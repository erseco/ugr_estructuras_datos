#include <stdio.h>
#include "td_cola.h"

    
/***********************************************************************/
/*************  TDA COLA DE NODOS                                      */
/***********************************************************************/


 
tcola Crear_C ( void ){
tcola c;


  c  = (tcola) malloc( sizeof( struct cola ) );
  if (c == NULL) return c;
  else {
       c->ini = (struct celda *) malloc( sizeof (struct celda) );
       if (c->ini == NULL) 
            { free( c );
              c = NULL;
	      return c;
	    }
       else { c->ini->nodo = NULL;
	      c->ini->ss = NULL;
              c->fin = c->ini;
              return c;    
	 }
   }
}

void Destruir_C( tcola c){
struct celda *p;

   while (c->ini != c->fin) {
     p = c->ini;
     c->ini = c->ini->ss;
     free( p );
     }
   free( c->ini );
   free( c );
}



int  Encolar( tnodo n, tcola c){
/* Insertamos por el final de la cola */
struct celda *p;

   p = (struct celda *) malloc( sizeof (struct celda) );
   if ( p == NULL) return 0;
   else {
     p->ss = NULL;
     p->nodo = n;
     c->fin->ss = p;
     c->fin = p;     
   }
}

tnodo Frente( tcola c ){

if (c->ini == c->fin) return NULL;
else  return c->ini->ss->nodo ;

}

tnodo Desencolar( tcola c ){
tnodo p;
struct celda *q;

if (c->ini == c->fin) return NULL;
else  {
      p = c->ini->ss->nodo;
      q = c->ini;
      c->ini = c->ini->ss;
      free ( q );
      return p;
      }  
}


int Vacia_C( tcola c ){

  return (c->ini == c->fin );
}
 
