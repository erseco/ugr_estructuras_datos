#include <stdio.h>
#include <stdarg.h>

#include "td_arb_g.h"

/*****************************************************************************/
/****************  TDA ARBOL GENERAL *****************************************/
 
tarbol Crear( telemento x ){
tarbol t;

  t = (tarbol) malloc( sizeof( struct nodo ) );
  if ( t==NULL) return t;
  else {
      t->dato = x;
      t->hi = t->p  = t->hd = NULL;
      return t;
  }
}


tarbol Crear_n(telemento x,...){
tarbol t;
va_list param;
tarbol t_h,aux;

t = (tarbol) malloc( sizeof( struct nodo ) );
if ( t==NULL) return t;
else { t->dato = x;
       t->p=NULL;
       t->hd=NULL;
       va_start(param,x);
       t_h = (tarbol) va_arg(param,tarbol);
       if (t_h == NULL) {
         t->hi=NULL;
	 return t;
         }
       else{
         t->hi=t_h;
         t->hi->p = t;
         aux = t->hi;
         while ( (t_h = (tarbol) va_arg(param,tarbol))!=NULL ){
              aux->hd = t_h;
              aux = aux->hd;
              aux->p = t;
              }
         aux->hd=NULL;
         va_end(param);
         return t;
         }
    }
}

               
        
              




void Destruir( tarbol T ){
tarbol m;

   if (T==AV) return;
   else {
      Destruir( T->hi );
      Destruir( T->hd );
      free( T );	 
   }
}

tarbol Padre( tnodo n, tarbol T ){
 
   return n->p;
}

tarbol Hijo_Izquierda( tnodo n, tarbol T ){

   return n->hi;
}

tarbol Hermano_Derecha( tnodo n, tarbol T ){

   return n->hd;
}

telemento Etiqueta( tnodo n, tarbol T ){

   return n->dato;
}

void Reetiquetar(tnodo n, telemento x, tarbol T) {

   n->dato = x;
}


tnodo Raiz( tarbol T ){

   return (tnodo) T;
}

void Insertar_HI( tnodo n, tarbol Ti, tarbol T ){

 if (Ti!=NULL){
   Ti->p = n;
   Ti->hd = n->hi;
   n->hi = Ti;
  }
}

void Insertar_HD( tnodo n, tarbol Td, tarbol T ){

if (Td !=NULL) {
   Td->p = n->p;
   Td->hd = n->hd;
   n->hd = Td;
  }
}

tarbol Podar_HI( tnodo n, tarbol T ){
tarbol aux;


   aux = n->hi;
   if (aux!=NULL) {
     n->hi = n->hi->hd;
     aux->p = NULL;
     aux->hd = NULL;
     }
   return aux;
}

tarbol Podar_HD( tnodo n, tarbol T ){
tarbol aux;

   aux = n->hd;
   if (aux!=NULL) {
     n->hd = n->hd->hd;
     aux->p = NULL;
     aux->hd = NULL;
     }
   return aux;
}

 
   





