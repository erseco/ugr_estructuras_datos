/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Fichero para probar el T.D.A. ArbolGeneral
 *
 ******************************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>

#include "ArbolGeneral.h"


void insertar_palabra(stringstream & palabra, ArbolGeneral<char> & T)
{


//     tnodo p,nuevo_nodo;
//     telemento x;

//     int salir = 0;

//     if (cad[i]=='\0') {
//      x = Etiqueta(n,T);
//      x.contador ++;
//      Reetiquetar(n,x,T);
//  }
//  else  {
//      p=Hijo_Izquierda(n,T);
//      while ( p!=NODO_NULO && !salir){
//         x = Etiqueta(p,T);
//         if (x.caracter == cad[i]) salir = 1;
//         else p=Hermano_Derecha(p,T);
//     }
//     if (salir)
//         Insertar_Cadena(cad,++i,p,T);
//     else {
//        x.caracter = cad[i];
//        x.contador = 0;
//        nuevo_nodo = Crear(x);
//        Insertar_HI(n, nuevo_nodo,T);
//        Insertar_Cadena(cad,++i,nuevo_nodo,T);
//    }
// }
}

// void Imprimir_Cadena( tarbol T );

// void escribe( telemento x){
//     printf("%c",x.caracter);
// }

// void preorden( tarbol T ){
//     tarbol m;

//     if (T==AV) return;
//     else {
//        escribe( Etiqueta( Raiz(T),T ) );
//        for ( m= Hijo_Izquierda( Raiz(T),T ); m!= AV ; m=Hermano_Derecha(m,T) )
//         preorden(m);
// }
// }


int main(int argc, char * argv[])
{
    // Definimos un arbol;
    ArbolGeneral<char> T;


    vector<char> v;
   // v.push_back('h');
    // v.push_back('o');
    // v.push_back('l');
    // v.push_back('a');
   // T.insertar(v);

    stringstream palabra;
    palabra << "hnonlnonrx";
    palabra >> T;

  //  palabra << "hnonlnonrx";
    palabra >> T;

    cout << "size: " << T.size() << endl;
    // insertar_palabra("hola", T);

    // exit(0);


    // const char *palabras[4] = {"hola", "holor", "agregar", "add"};

    // // Le insertamos palabras
    // for (int i = 0; i < 4; i++)
    //     insertar_palabra(palabras[i], T);

    // Pintamos el arbol
    cout << T << endl;

}





