#include <stdio.h>

#include "td_pila.h"


/***********************************************************************/
/*************  TDA PILA DE NODOS                                      */
/***********************************************************************/


 
tpila Crear_P ( void ){
tpila p;

   p = (tpila) malloc( sizeof (struct pila) );
   if (p==NULL) return p;
   else { p->ss=NULL; 
          return p;
         }
}


void Destruir_P( tpila P ){
tpila q;

for (q=P; P!=NULL;  ){
      P = P->ss;
      free( q );
     }
}

int Push( tnodo n, tpila P ){
tpila q;

   q = (tpila) malloc( sizeof (struct pila) );
   if (q==NULL) return -1;
   else { q->nodo = n;
          q->ss = P->ss;
          P->ss = q;
          return 0;
        }
}

tnodo Top( tpila P ) {
  
   return P->ss->nodo;
}

tnodo Pop( tpila P ){
tpila q; 
tnodo n;

if (P->ss == NULL) return NULL;
else { q = P->ss;
       P->ss = q->ss;
       n = q->nodo;
       free( q );
       return n;
      }
}

int Vacia_P( tpila P ){
  
  return  ( P->ss==NULL );
}

    
      




 
