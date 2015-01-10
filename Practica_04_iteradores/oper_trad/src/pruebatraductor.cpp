#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con las traducciones"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Traductor T;
   f>>T; //Cargamos en memoria, en el traductor.

   string a;
   cout<<"Dime una palabra en el idioma origen:";
   getline(cin,a);

   vector<string> trads=T.GetTraducciones(a);

   /* Escrbimos*/
   cout<<a<<"-->";
   for (int i=0;i<trads.size(); ++i)
     cout<<trads[i]<<';';
   cout<<endl;

}