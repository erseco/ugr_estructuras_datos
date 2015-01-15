#include <stdio.h>
#include <ctype.h>

#include "td_arb_g.h"


void Insertar_Cadena( char *cad, int i, tnodo n, tarbol T)
{
tnodo p,nuevo_nodo;
telemento x;
int salir = 0;
  if (cad[i]=='\0') {
       x = Etiqueta(n,T);
       x.contador ++;
       Reetiquetar(n,x,T);
       }
  else  {
   p=Hijo_Izquierda(n,T);
   while ( p!=NODO_NULO && !salir){
        x = Etiqueta(p,T);
        if (x.caracter == cad[i]) salir = 1;
        else p=Hermano_Derecha(p,T);
        }
   if (salir)
        Insertar_Cadena(cad,++i,p,T);
   else {
         x.caracter = cad[i];
         x.contador = 0;
         nuevo_nodo = Crear(x);
         Insertar_HI(n, nuevo_nodo,T);
         Insertar_Cadena(cad,++i,nuevo_nodo,T);
         }
 }
}

void Imprimir_Cadena( tarbol T );

void escribe( telemento x){
printf("%c",x.caracter);
}

void preorden( tarbol T ){
tarbol m;

  if (T==AV) return;
  else {
	escribe( Etiqueta( Raiz(T),T ) );
	for ( m= Hijo_Izquierda( Raiz(T),T ); m!= AV ; m=Hermano_Derecha(m,T) )
	   preorden(m);
	}
}


int main(){
int cont;
tarbol T;
char cadena[20];
telemento x;
FILE *fp;

x.caracter='*';
x.contador =0;

T = Crear(x);

fp = fopen("cadenas","r");
if (fp==NULL) {
     printf("Error de Apertura del fichero\n");
     return 0;
    }
while ( (cont = fscanf(fp,"%s",cadena))!=EOF )
         Insertar_Cadena(cadena,0,Raiz(T),T);

/* Imprimir_Cadena(T); */

preorden(T);

fclose(fp);

return 0;
}





