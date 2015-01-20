 


 template<class Tbase>
 void ArbolGeneral<T>::destruir(nodo * nodo){
 	
 	if(n!=0){
 		nodo *n,*aux;
 		n=nodo->izqda;
 		while(n!=0){
 			aux=n;
 			n=n->drcha;
 			destruir(aux);
 		}
 		delete nodo;
 	}
 	
}

template<class Tbase>
void ArbolGeneral<T>::copiar(nodo *& dest, nodo * orig)
{
		
	if (ori!=0)
	{
		nodo *aux;
		aux->padre=dest->padre;
		aux->drcha=dest->drcha;
		
	}
	


}


template<class Tbase>
 void ArbolGeneral<T>::AsignaRaiz(const Tbase& e){
 	
 	nodo n=new nodo;
 	n->etiqueta=e;
 	n->padre=n->izqda=n->drcha=0;
 	
 }

