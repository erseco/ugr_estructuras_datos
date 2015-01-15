#ifndef ARB_GEN 
#define ARB_GEN 

/*****************************************************************************/
/****************  TDA ARBOL GENERAL *****************************************/

                                      
/* DEFINICION DEL TIPO ELEMENTO */
typedef struct {
    char caracter;
    int contador;
    } telemento;

/* Definicion de Estructura y Tipos */

#define AV NULL
#define NODO_NULO NULL
 

typedef struct nodo {
     telemento dato;
     struct nodo *hi;
     struct nodo *hd;
     struct nodo *p;
     } *tnodo;

typedef tnodo tarbol;


/* Definicion de Primitivas */

tnodo Crear( telemento x );
/* Prec: Ninguna 							*/
/* Post: Crea un nodo, donde almacena el elemento x,                    */
/*       El resto de los campos los mantiene como arbol vacio           */


 
tarbol  Crear_n(telemento x,...);
/* Prec:  Los parametros de entrada son un tipo elemente y una secuencia */
/*        de nodos o arboles que previamente han sido creados,           */
/*        Esta secuencia debe terminar FORZOSAMENTE en arbol vacio AV    */
/*           Por ejemplo =>  Crear_n(x,a1,a2,a3,AV);			 */
/* Post:  Crea un nodo, que sera la raiz de un arbol y que tendra como   */
/*        como descendientes (en orden) el conjunto de arboles que recibe*/
  
 
void Destruir( tarbol T );
/* Prec: T es un arbol previamente creado                                */
/* Post: Libera los recursos de memoria almacenados en T                 */

tnodo Padre( tnodo n, tarbol T );
/* Prec: T es un arbol previamente creado, n es un nodo en T             */
/* Post: Devuelve el nodo que es padre de n en T, si n es la raiz        */
/*       devuelve el nodo nulo                                           */

 
tnodo Hijo_Izquierda( tnodo n, tarbol T ) ;
/* Prec: n es un nodo de un arbol T previamente creado                  */
/* Post: Devuelve el hijo izquierda de n en T                           */
 
tnodo Hermano_Derecha( tnodo n, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/* Post: Devuelve el hemano derecha del nodo n en T                     */


telemento Etiqueta( tnodo n, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/* Post: Devuelve el elemento almacenado en el nodo n de T              */

void Reetiquetar( tnodo n, telemento x, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/* Post: Almacena la etiqueta x en el nodo n                            */



tnodo Raiz( tarbol T );
/* Prec: T es un arbol previamente creado                               */
/* Post: Devuelve el nodo que es raiz de T                              */



void Insertar_HI( tnodo n, tarbol Ti, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/*       Ti es un arbol que no pertenece a T                            */
/* Post: Inserta Ti como hijo izquierda del nodo n en T                 */
/*       Si n tiene hijo izquierda lo desplaza una posicion a la dcha  */

 
void Insertar_HD( tnodo n, tarbol Td, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/*       Td es un arbol que no pertenece a T                            */
/* Post: Inserta Td como hermano a la derecha  del nodo n en T          */
/*       Si n tiene mas hermano a la derecha, estos son desplazados     */
/*       una posicion a la dcha                                         */


tarbol Podar_HI( tnodo n, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/* Post: Poda el subarbol situado a la izquierda del nodo n en T        */
/*       El primer hermano a la decha. pasa a ser el hijo izquierda de n*/

tarbol Podar_HD( tnodo n, tarbol T );
/* Prec: n es un nodo de un arbol T previamente creado                  */
/* Post: Poda el subarbol situado a la decha del nodo n en T            */
/*       Si n tiene mas hermano a la derecha, estos son desplazados     */
/*       una posicion a la izquierda                                    */

#endif

             

   





