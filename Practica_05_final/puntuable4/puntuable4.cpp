#include <iostream>
#include <ABB.h>

using namespace std;

void listar_abb (const ABB<int>& a){
  ABB<int>::Iterador it;

  cout << "Arbol con " << a.size() << " elementos:" << endl;
  for (it=a.primero(); it!=a.final(); it=a.siguiente(it))
    cout << a.etiqueta(it) << ' ';
  cout << endl;
}


int main (int argc, char *argv[]){

  
  
  return 0;
}
