#include <iostream>
#include <cassert>
#include "ArbolGeneral.h"

using namespace std;


/*************METODOS PRIVADOS*********************/

//Destruir
template <class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo * n){
	if (n != 0){
		destruir(n.izqda);
		destruir(n.drcha);
		delete n;
	}
}

//Copiar
template <class Tbase>
 void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
		if (orig == 0)
			dest = 0;
		else {
			dest = new nodo;
			dest.etiqueta = orig.etiqueta; // Raiz
			copiar (dest.izqda,orig.izqda);
			copiar (dest.drcha,orig.drcha);
				//Para establecer los padres.
			if (dest.izqda != 0)
				dest.izqda.padre = dest;
			if (dest.drcha != 0)
				dest.drcha.padre = dest;
		}
}

//Contar
template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const{
	if (n == 0)
			return n;
	else
		return 1+contar(n.izqda)+contar(n.drcha);
}

//Son Iguales
template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const{
	if (n1==0 && n2==0)
		return true;
	if (n1==0 || n2==0)
		return false;
	if (n1.etiqueta!=n2.etiqueta)
		return false;
	if(!soniguales(n1.izqda,n2.izqda))
		return false;
	if(!soniguales(n1.drcha,n2.drcha))
		return false;

	return true;
}

//Operador <<
template <class Tbase>
  void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
		if (nod == 0)
			out << "x ";
		else {
			out << "n " << nod.etiqueta << " ";
			escribe_arbol(out,nod.izqda);
			escribe_arbol(out,nod.drcha);
	 }
}

//Operador >>
template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod){
	char c;
	in >> c;
	if (c== 'n'){
		nod = new nodo;
		in >> nod.etiqueta;
		lee_arbol(in,nod.izqda);
		lee_arbol(in,nod.drcha);
		if (nod.izqda!=0)
			nod.izqda.padre=nod;
		if(nod.drcha!=0)
			nod.drcha.padre=nod;
	}
	else nod = 0;
}

/*************METODOS PUBLICOS*********************/

//Constructor por defecto
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
	laraiz=0;
}

//Constructor de la raiz
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
	laraiz= new nodo;
	laraiz.padre = laraiz.izqda = laraiz.drcha = 0;
	laraiz.etiqueta = e;
}

//Constructor de copias
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral (const ArbolGeneral<Tbase>& v){
	copiar(laraiz,v.laraiz);
	if (laraiz!=0)
		laraiz.padre=0;
}

//Destructor
template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
	destruir(laraiz);
}

//Operador de asiganacion
template <class Tbase>
ArbolGeneral<Tbase> & ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v){
	if (this!=&v){
		destruir(laraiz);
		copiar(laraiz,v.laraiz);
		if (laraiz!=0)
			laraiz.padre=0;
	}
	return (*this);
}

//Asignar nodo raíz
template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
	destruir(laraiz);
	laraiz = new Nodo;
	laraiz.padre = laraiz.izqda = laraiz.drcha = 0;
	laraiz.etiqueta = e;
}

//Raíz del árbol
template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
	return laraiz;
}

//Hijo más a la izquierda
template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const{
	assert(n!=0);				//El nodo no debe ser nulo
	return (n.izqda);
}

//Hermano derecha
template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const{
	  assert(n!=0);       //El nodo no debe ser nulo
  	return (n.drcha);
}

//Nodo padre
template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const{
	  assert(n!=0);       //El nodo no debe ser nulo
  	return (n.padre);
}

//Etiqueta de un nodo
template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n){
		 assert(n!=0);       //El nodo no debe ser nulo
  	 return (n.etiqueta);
}

//Etiqueta de un nodo
template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const{
		 assert(n!=0);       //El nodo no debe ser nulo
  	 return (n.etiqueta);
}

//Copia subárbol
template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
		destruir(laraiz);
		copiar(laraiz,nod);
		if(laraiz!=0)
			laraiz.padre=0;
}

//Podar subárbol hijo más a la izquierda
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n!=0);
	destruir(dest.laraiz);

	dest.laraiz=n.izqda;

	if (dest.laraiz!=0){
		dest.laraiz.padre=0;
		n.izqda=0;
	}
}

insertar_hijomasizquierda(CeldaArbol *T1, CeldaArbol *n, CeldaArbol *& T2)
{

	if (T2!=0)
	{
		T2->hermderecha = n->hizqda;
		T2->padre = n;
		n->hizqda = T2;
		T2=0; // Dejamos T2 vacio

	}

}
insertar_hermanoderecha(CeldaArbol *T1, CeldaArbol *n, CeldaArbol *& T2)
{

	if (T2!=0)
	{
		T2->hermderecha = n->hermderecha;
		T2->padre = n->padre;
		n->hermderecha = T2;
		T2=0; // Dejamos T2 vacio

	}

}


CeldaArbol * podar_hijomasizquierda(CeldaArbol *T CeldaArbol *n)
{
	CeldaArbol * Res = 0;
	if (n->hizqda!=0)
	{
		Res = n->hizqda;
		n->hizqda = Res->hermderecha;
		Res->padre = Res->hermderecha=0;
	}
	return Res
}

CeldaArbol * podar_hermanoderecha(CeldaArbol *T CeldaArbol *n)
{


	CeldaArbol * Res = 0;

	if (n->hermderecha!=0)
	{

		Res = n->hermderecha;
		n->hermderecha = Res->hermderecha;
		Res->padre = Res->hermderecha=0;

	}


	return Res;

}


//Podar subárbol hermano derecha
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n!=0);
	destruir(dest.laraiz);

	dest.laraiz=n.drcha;

	if(dest.laraiz!=0){
		dest.laraiz.padre=0;
		n.drcha=0;
	}
}

//nsertar subárbol hijo más a la izquierda
template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
	if (rama != 0){
		rama.drcha = n.izqda;
		rama.padre = n;
		n.izqda = rama;
		rama = 0;
	}
}

//Insertar subárbol hermano derecha
template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
		if (rama != 0){
			rama.drcha = n.drcha;
			rama.padre = n.padre;
			n.drcha = rama;
			rama =  0;
		}
}

//Borra todos los elementos
template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
	destruir(laraiz);
	laraiz=0;
}

//Número de elementos
template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
	return contar(laraiz);
}

//Vacío
template <class Tbase>
inline bool ArbolGeneral<Tbase>::empty() const{
	return laraiz==0;
}

//Operador de comparación (igualdad)
template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator == (const ArbolGeneral<Tbase>& v) const{
	return soniguales(laraiz, v.laraiz);
}

//Operador de comparación (diferencia)
template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator != (const ArbolGeneral<Tbase>& v) const{
	return !(*this==v);
}

//Operador de extracción de flujo
template <class Tbase>
inline istream& operator>>(std::istream& in, ArbolGeneral<Tbase>& v){
	v.lee_arbol(in, v.laraiz);
	return in;
}

//Operador de inserción en flujo
template <class Tbase>
inline ostream& operator>>(std::ostream& out, ArbolGeneral<Tbase>& v){
	v.escribe_arbol(out, v.laraiz);
	return out;
}


/*******************************************************/







