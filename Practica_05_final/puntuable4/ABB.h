/* Fichero: ABB.h */
#include <string>

#ifndef __ABB_h__
#define __ABB_h__

/**
  * @brief T.D.A. ABB (Árbol Binario de Búsqueda)
  *
  * \b Definición: Una instancia \e a del tipo de dato abstracto \e ABB sobre un
  * dominio \e Tbase es un árbol binario con etiquetas en \e Tbase de manera
  * que la etiqueta de un nodo es mayor que la de sus descendientes a la 
  * izquierda y menor que la de sus descendientes a la derecha. Para poder 
  * gestionarlo, debe existir la operación \e menor (<) para el tipo \e Tbase.
  * Dos elementos base, \e e1 y e2, son iguales si no ((e1<e2) ó (e2<e1)).
  *
  * Para poder usar el TDA \e ABB se debe incluir el fichero
  *
  * <tt>\#include ABB.h</tt>
  *
  * El espacio requerido para el almacenamiento es O(n), donde n es el número 
  * de nodos del ABB.
  *
  * @author Antonio Garrido
  * @author Revisado por Javier Abad
  * @date Mayo 2008
  */
       
template <class Tbase>
class ABB {
/**
  * @page repConjunto Rep del TDA ABB
  *
  * @section invConjunto Invariante de la representación
  *
  * Sea \e T un Árbol Binario de Búsqueda sobre el tipo \e Tbase. Entonces el
  * invariante de la representación es
  *
  * Si \e T es vacío, entonces T.laraiz=0 y T.nelementos=0, y si no:
  *
  * - T.laraiz->padre = 0 y
  * - \f$ \forall \f$ n nodo de \e T, n->izqda \f$ \neq \f$ n->drcha y
  * - \f$ \forall \f$ n, m nodos de \e T, si n->izqda=m ó n->drcha=m, entonces
  * m->padre=n y
  * - \f$ \forall \f$ n, m nodos de \e T, si n->izqda=m, entonces 
  * n->etiqueta > m->etiqueta y
  * - \f$ \forall \f$ n, m nodos de \e T, si n->drcha=m, entonces
  * n->etiqueta < m->etiqueta y
  * - T.nelementos = N(T.laraiz), donde N(n) = 1+N(n->izqda)+(N->drcha),
  * con N(0) = 0
  *
  * @section faConjunto Función de abstracción
  *
  * Sea @e T un Árbol Binario de Búsqueda sobre el tipo @e Tbase. Entonces, si
  * lo denotamos también Arbol(T.laraiz), es decir, como el árbol que cuelga de
  * su raíz, entonces este árbol del conjunto de valores en la representación
  * se aplica al árbol
  *
  * {T.laraiz->etiqueta,
  * {Arbol(T.laraiz->izqda)},
  * {Arbol(T.laraiz->drcha)}},
  *
  * donde {0} es el árbol vacío.
  */      
  private:
    /**
      * @brief Nodo
      *
      * En cada  estructura nodo se almacena una etiqueta del ABB, que se 
      * implementa como un conjunto de nodos enlazados segú la relación 
      * padre-hijo
      */
    struct nodo {
        
      /**
        * @brief Elemento almacenado
        *
        * En este campo se almacena la etiqueta que corresponde a este nodo.
        */
      Tbase etiqueta;
      
	  /**
	    * @brief Puntero al hijo izquierdo
        *
        * En este campo se almacena un puntero al nodo raíz del subárbol 
        * izquierdo, o el valor 0 si no tiene.
        */
      struct nodo *izqda;
      
      /**
        * @brief Puntero al hijo derecho
        *
        * En este campo se almacena un puntero al nodo raíz del subárbol 
        * derecho, o el valor 0 si no tiene.
        */
      struct nodo *drcha;
      
	  /**
        * @brief Puntero al padre
        *
        *En este campo se almacena un puntero al nodo padre, o el valor 0 
        * si es la raíz.
        */
      struct nodo *padre;
    };
      
    /**
      * @brief Puntero a la raíz.
      *
      * Este miembro es un puntero al primer nodo, que corresponde a la raíz
      * del ABB. Vale 0 si el ABB es vacío.
      */
    struct nodo *laraiz;

    /**
      * @brief Número de elementos
      *
      * Este entero almacena el número de elementos del ABB. 
      * Coincide con el número de nodos enlazados.
      */
    int nelementos;
    /**
      * @brief Destruye el subárbol
      * @param n Nodo que destruir, junto con sus descendientes
      * Libera los recursos que ocupan \e n y sus descendientes.
      */
    void destruir(nodo * n);
    
    /**
      * @brief Copia un subárbol
      * @param dest Referencia al puntero del que cuelga la copia
      * @param orig Puntero a la raíz del subárbol a copiar
      *
      * Hace una copia de todo el subárbol que cuelga de \e orig en el puntero
      * \e dest. Es importante ver que en \e dest->padre (si existe) no se 
      * asigna ningún valor, pues no se conoce.
      */
    void copiar(nodo *& dest, nodo * orig);
    
    /**
      * @brief Reconstruye un ABB equilibrándolo
      * @param p_raiz Puntero a la raíz del ABB a construir
      * @param v Vector con los punteros a los nodos
      * @param n Número de elementos en v. n > 1
      *
      * Reconstruye un ABB colgando en p_raiz, los \e n nodos que apunta el 
      * vector \e v, asegurando que en la raíz de cada subárbol siempre se 
      * posiciona la mediana de los elementos a colgar. El subárbol obtenido 
      * está totalmente equilibrado.
      */
    void enganchar (nodo* & p_raiz, nodo **v, int n);
    
  public:
    /**
      * @brief Constructor por defecto
      *
      * Reserva los recursos e iniciliza el ABB a vacío, {}. 
      * La operación se realiza en tiempo O(1).
      */
    ABB();
    
    /**
      * @brief Constructor de copias
      * @param a ABB a copiar
      *
      * Construye el ABB duplicando el contenido de \e v en el ABB receptor.
      * La operación se realiza en tiempo O(n), donde n es el número de 
      * elementos de \e v.
      */
    ABB (const ABB<Tbase>& a);
    
    /**
      * @brief Destructor
      *
      * Libera los recursos ocupados por el ABB receptor. 
      * La operación se realiza en tiempo O(n), donde n es el número de 
      * elementos del ABB receptor.
      */
    ~ABB();
    
    /**
      * @name Iteradores
      *
      * Definición de los iteradores de la clase ABB
      */
      
    /** @brief Tipo Iterador
      *
      * Este tipo nos permite iterar por cada uno de los elementos del ABB.
      * Los valores que tomará seran tantos como nodos en el ABB (para poder 
      * referirse a cada uno de ellos) más una posición adicional (detrás de 
      * la última) para indicar el fin, que llamaremos \e final.
      *
      * Una variable \e it de este tipo se declara
      * <tt>ABB::Iterador it;</tt>
      *
      * Una variable de tipo iterador es válida aunque se modifique el ABB 
      * que contiene el elemento al que se refiere. El único iterador que se 
      * invalida es el que apunta a un elemento que se borra.
      * 
      * Las operaciones válidas sobre el tipo Iterador son:
      *
      * - Operador de Asignación (=)
      * - Operador de comprobación de igualdad (==)
      * - Operador de comprobación de desigualdad (!=)
      */
//@{
    
    typedef nodo * Iterador;
    
    /**
      * @brief Iterador primero
      * @return Iterador indicando el primer elemento del ABB receptor
      *
      * Devuelve la posición del primer elemento, que coincide con la posición 
      * \e final si el ABB está vacío. El primer elemento es el más pequeno 
      * según el operador "<" del tipo \e Tbase.
      * La operación se realiza en tiempo O(n), donde n es el número de 
      * elementos del ABB.
      */
    Iterador primero() const;
    
    /**
      * @brief Iterador siguiente
      * @param it Iterador del que se quiere obtener el siguiente
      * @pre \e it no es el \e final del ABB
      * @return Iterador siguiente a \e it
      *
      * El siguiente elemento corresponde al siguiente según la operación "<" 
      * del tipo \e Tbase.
      * La operacion se realiza en tiempo O(n), amortizado O(1).
      */      
    Iterador siguiente(Iterador it) const;

    /**
      * @brief Iterador final
      * @return Posición \e final, detrás de la última, del ABB receptor.
      *
      * Devuelve la posición \e final (detrás de la última), que coincide 
      * con la posicion primera si el ABB esta vacío.
      * La operacion se realiza en tiempo O(1).
      */
    Iterador final() const;
//@}
    
    
    /**
      * @brief Operador de asignación
      * @param a ABB a copiar
      * @return Referencia al ABB receptor.
      *
      * Asigna el valor del ABB duplicando el contenido de \e a en el ABB
      * receptor. La operación se realiza en tiempo O(n), donde n es el número
      * de elementos de \e a.
      */
    ABB<Tbase>& operator = (const ABB<Tbase> &a);

    /**
      * @brief Etiqueta indicada por el iterador
      * @param it Iterador que indica el elemento.
      * @pre \e it no es \e final
      * @return Referencia constante al elemento.
      *
      * Devuelve una referencia al elemento que indica el iterador \e it. Es 
      * constante y por tanto no se puede modificar el valor.
      * La operacion se realiza en tiempo O(1).
      */
    const Tbase& etiqueta(const Iterador it) const;
    
    /**
      * @brief Búsqueda de elemento
      * @param etiq Etiqueta a buscar en el ABB receptor.
      * @return Iterador que se refiere al nodo del ABB que contiene la 
      * etiqueta \e etiq. El iterador \e final si \e etiq no está en el ABB.
      *
      * Devuelve el iterador que apunta a la posición del ABB donde se 
      * encuentra el elemento buscado, \e etiq. Si no se encuentra, devuelve la 
      * posición \e final, detrás de la última.
      * La operación se realiza en tiempo O(n).
      */
    Iterador buscar(const Tbase& etiq) const;
    
    /**
      * @brief Inserción de un elemento
      * @param etiq Etiqueta a insertar en el ABB receptor.
      * @return Devuelve true se ha producido una inserción en el ABB y false
      * si el elemento ya se encontraba en el árbol.
      *
      * Busca el elemento \e etiq en el ABB receptor. Si lo encuentra, lo 
      * reescribe de nuevo y devuelve false. Si no, crea un nuevo nodo en el 
      * ABB conteniendo esta etiqueta y devuelve true. La operación se 
      * realiza en tiempo O(n), donde n es el número de elementos del ABB.
      */
    bool insertar(const Tbase& etiq);
    
    /**
      * @brief Borrado de un elemento
      * @param it Iterador al elemento a borrar.
      * @pre \e it no es \e final.
      * @return Iterador al siguiente elemento
      *
      * Borra el elemento que se almacena en el iterador \e it y devuelve el 
      * siguiente elemento a \e it por medio de un iterador. La operación se 
      * realiza en tiempo O(n), donde n es el número de elementos del ABB.
      */
    Iterador borrar(const Iterador it);
    
    /**
      * @brief Equilibra el ABB
      *
      * Equilibra el Árbol Binario de Búsqueda receptor. La operación se 
      * realiza en tiempo O(n), donde n es el número de elementos del ABB.
      */
    void equilibrar();
    
    /**
      * @brief Borra todos los elementos del ABB
      *
      * Borra todos los elementos del ABB receptor. Cuando termina, el ABB está
      * vacío. La operación se realiza en tiempo O(n), donde n es el número de 
      * elementos del ABB.
      */
    void clear();
    
    /** @brief Número de elementos
      * @return El número de elementos del ABB receptor.
      *
      * La operación se realiza en tiempo O(1).
      */
    int size() const;
    
    /**
      * @brief Comprueba si el ABB está vacío
      * @return Devuelve \e true si el número de elementos del ABB receptor es 
      * cero, y \e false en caso contrario.
      *
      * La operacion se realiza en tiempo O(1).
      */
    bool empty() const;

    /**
      * @brief Operador de comparación de igualdad
      * @param otro ABB con el que se desea comparar.
      * @return Devuelve \e true si el ABB receptor tiene los mismos elementos
      * y en el mismo orden, y \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      */
    bool operator==(const ABB<Tbase>& otro) const;
    
    /**
      * @brief Operador de comparación de desigualdad
      * @param otro ABB con el que se desea comparar.
      * @return Devuelve \e true si el ABB receptor no tiene los mismos 
      * elementos y en el mismo orden, y \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      */
    bool operator!=(const ABB<Tbase>& otro) const;
};



/***************************************************************/
/* DEFINICIONES DE LAS FUNCIONES */
/***************************************************************/

#include <cassert>


/***************************************************************/
//               FUNCIONES PRIVADAS
/***************************************************************/

template <class Tbase>
void ABB<Tbase>::destruir(nodo * n){
  if (n!=0){              //Si el puntero no es nulo,
    destruir(n->izqda);   //borramos el hijo izquierdo,
    destruir(n->drcha);   //borramos el hijo derecho,
    delete n;             //y borramos el nodo
  }
}

/***************************************************************/

template <class Tbase>
void ABB<Tbase>::copiar(nodo *& dest, nodo * orig){
  
  if (orig==0)                        //Si el ABB original es vacío
    dest = 0;                         //Inicializamos dest como vacío
  else{                               //Si el ABB original no es vacío
    dest = new nodo;                  //Creamos la raíz
    dest->etiqueta = orig->etiqueta;  //Copiamos la etiqueta de la raíz
    copiar(dest->izqda, orig->izqda); //Copiamos recursivamente el hijo izqda
    copiar(dest->drcha, orig->drcha); //Copiamos recursivamente el hijo drcha
    if (dest->izqda!=0)               //Si el hijo izqda no es vacío,
      dest->izqda->padre= dest;       //actualizamos su padre
    if (dest->drcha!=0)               //Si el hijo drcha no es vacío,
      dest->drcha->padre= dest;       //actualizamos su padre
  }
}

/***************************************************************/

template <class Tbase>
void ABB<Tbase>::enganchar (nodo* & p_raiz, nodo **v, int n){
  int i;

  i = n/2;
  p_raiz = v[i];                         //p_raiz contiene la mediana
  if (i>0){                              //Si quedan elementos menores,
    enganchar(p_raiz->izqda, v, i);      //llamada recursiva dicotómica
    p_raiz->izqda->padre = p_raiz;       //Actualizamos el padre del hijo izqda
  }
  else                                   //Si no quedan elementos menores
    p_raiz->izqda = 0;                   //El subárbol izquierdo es vacío
    
  if (n-i-1>0){                             //Si quedan elementos mayores,
    enganchar(p_raiz->drcha, v+i+1, n-i-1); //llamada recursiva dicotómica
    p_raiz->drcha->padre = p_raiz;       //Actualizamos el padre del hijo drcha
  }
  else                                      //Si no quedan elementos mayores
    p_raiz->drcha = 0;                      //El subárbol derecho es vacío
}


/***************************************************************/
//               FUNCIONES PUBLICAS
/***************************************************************/

template <class Tbase>
inline ABB<Tbase>::ABB(){
  laraiz = 0;
  nelementos = 0;
}

/***************************************************************/

template <class Tbase>
ABB<Tbase>::ABB (const ABB<Tbase>& a){
  copiar (laraiz, a.laraiz);  //Copiamos recursivamente desde la raíz
  if (laraiz!=0)              //Si el ABB copiado no es vacío,
    laraiz->padre = 0;        //actualizamos el padre a 0
  nelementos = a.nelementos;  //Actualizamos nelementos
}

/***************************************************************/

template <class Tbase>
inline ABB<Tbase>::~ABB(){
  destruir(laraiz);
}

/***************************************************************/

template <class Tbase>
typename ABB<Tbase>::Iterador  ABB<Tbase>::primero() const {
  nodo *p;
  
  if (laraiz==0)        //Si el ABB es vacío,
    return 0;           //devolvemos 0
  else{                 //Si no es vacío,
    p = laraiz;         //p apunta a la raíz
    while (p->izqda!=0) //Mientras no lleguemos a una hoja,
      p = p->izqda;     //descendemos por el hijo a la izquierda
    return p;           //Devolvemos la dirección del nodo más a la izquierda
  }
}
  
/***************************************************************/

template <class Tbase>
typename ABB<Tbase>::Iterador  ABB<Tbase>::siguiente(Iterador it) const {
  nodo *padre;
  bool subir;
  
  assert(it!=0);                    //Si el iterador no es el final del ABB
  //Caso 1: Existe el subárbol derecho. El siguiente será el nodo más a la
  //izquierda del subárbol derecho.
  if (it->drcha!=0){                //Si el existe el hijo derecha,
    it = it->drcha;                 //descendemos por la derecha
    while (it->izqda!=0)            //Mientras haya hijos a la izquierda,
      it = it->izqda;               //descendemos por la izquierda
  }
  //Caso 2: No existe el subárbol derecho. Tendremos que ascender por el ABB
  else {
    subir = true;
    while (subir) {
      padre = it->padre;
      if (padre==0){                //Si hemos llegado a la raíz,
	    it = 0;                     //devolvemos final!
	    subir = false;              //y desactivamos subir
      }
      else if (padre->drcha!=it) {  //si el nodo es hijo izquierda del padre,
        it = padre;                 //el padre es el siguiente en el orden
        subir = false;              //y desactivamos subir
      }
      else                          //si el nodo es hijo derecha del padre,
        it = padre;                 //ascendemos por el ABB y seguimos iterando
    }
  }
  return it;
}

/***************************************************************/

template <class Tbase>
inline typename  ABB<Tbase>::Iterador  ABB<Tbase>::final() const {
  return 0;
}
  
  
/***************************************************************/

template <class Tbase>
ABB<Tbase>& ABB<Tbase>::operator = (const ABB<Tbase>& a){
  if (this!=&a) {              //Comprobación de rigor
    destruir(laraiz);          //Destruimos el ABB desde la raíz
    copiar (laraiz,a.laraiz);  //Copiamos recursivamente
    if (laraiz!=0)             //Si el ABB copiado no es vacío,
      laraiz->padre= 0;        //actualizamos el padre a 0
    nelementos=a.nelementos;   //Actualizamos nelementos
  }
  return *this; //Devolvemos una referencia a *this para 
                //permitir encadenamientos (a=b=c) 
}

/***************************************************************/

template <class Tbase>
inline const Tbase& ABB<Tbase>::etiqueta(const Iterador it) const{
  assert(it!=0);          //El iterador no es final
  return (it->etiqueta);
}

/***************************************************************/

template <class Tbase>
typename ABB<Tbase>::Iterador ABB<Tbase>::buscar(const Tbase& etiq) const{
  Iterador it;
  
  it = laraiz;                    //Partimos de la raíz del ABB
  while (it!=0) {                 //Mientras no lleguemos a una hoja
    if (it->etiqueta < etiq)      //Si la etiqueta actual es menor,
      it = it->drcha;             //descendemos por el hijo derecho
    else if (etiq < it->etiqueta) //Si la etiqueta actual es mayor,
      it = it->izqda;             //descendemos por el hijo izquierdo
    else                          //En otro caso,
      return it;                  //habremos encontrado el elemento
  }
  return final(); //Si alcanzamos esta línea, no hemos encontrado la etiqueta
}

/***************************************************************/

template <class Tbase>
inline bool ABB<Tbase>::insertar(const Tbase& etiq){
  bool fin,dev;
  nodo *p;
  
  if (laraiz == 0){                //Si es el ABB vacío
    laraiz = new nodo;             //Reservamos la matriz
    laraiz->padre =                //Actualizamos el padre,
    laraiz->izqda =                //el hijo izquierdo,
    laraiz->drcha = 0;             //y el hijo derecho
    laraiz->etiqueta = etiq;       //Almacenamos la etiqueta
    nelementos++;                  //Incrementamos nelementos
    dev = true;                    //Devolvemos true (se ha insertado)
  }
  else{                            //Si el ABB no es vacío
    p = laraiz;                    //Empezamos por la raíz
    fin = false;
    while (!fin){                  //Mientras no hayamos realizado la inserción
      if (etiq < p->etiqueta){     //Si la etiqueta actual es mayor,
                                   //descendemos por el hijo izquierdo
	    if (p->izqda == 0) {       //Si no hay hijo izquierdo,
	      p->izqda = new nodo;     //lo creamos
	      p->izqda->padre = p;     //Actualizamos el padre
	      p = p->izqda;            //Descendemos al hijo izquierdo
          p->drcha = p->izqda = 0; //Actualizamos los hijos izqda y drcha
          fin = true;              //Activamos fin
          dev = true;              //Devolveremos true (se ha insertado)
	    }
        else                       //Si el hijo izquierdo existe,
          p = p->izqda;            //descenderemos por él
      }
      else if (p->etiqueta < etiq){//Si la etiqueta actual es menor,
	    if (p->drcha == 0) {       //Si no hay hijo derecho,
	      p->drcha = new nodo;     //lo creamos
          p->drcha->padre = p;     //Actualizamos el padre
          p = p->drcha;            //Descendemos al hijo derecho
          p->drcha = p->izqda = 0; //Actualizamos los hijos izqda y drcha
          fin = true;              //Activamos fin
          dev= true;               //Devolveremos true (se ha insertado)
        }
        else                       //Si el hijo derecho existe,
          p = p->drcha;            //descenderemos por él
      }
      else{                        //La etiqueta ya se encuentra en el árbol
        fin = true;                //Activamos fin
        dev = false;               //Devolveremos false (no se ha insertado)
      }
    }
    //Al llegar aquí, habremos alcanzado el nodo 
    //donde está o debe estar la etiqueta
    p->etiqueta = etiq;            //Almacenamos la etiqueta
    if (dev)                       //Si dev vale true,
      nelementos++;                //incrementamos nelementos
  }
  return dev;                    //Devolvemos dev
}
    
/***************************************************************/

template <class Tbase>
typename ABB<Tbase>::Iterador ABB<Tbase>::borrar(const Iterador it){
  nodo *q, *aux, *dev;
  
  assert(it != final());             //Comprobamos que el iterador no sea final
  dev = siguiente(it);               //Devolveremos el siguiente en el ABB
  
  nelementos--;                      //Decrementamos nelementos
  
  if (it->izqda==0 && it->drcha==0){ //Si no tiene hijos
    if (it == laraiz){               //Si es la raíz
      delete it;                     //Borramos el nodo
      laraiz = 0;                    //El ABB que queda es vacío
    }
    else {                           //Si no es la raíz
      q = it->padre;                 //q apunta al padre
      delete it;                     //Borramos el nodo
      if (q->izqda == it)            //Actualizamos el puntero al hijo
        q->izqda = 0;                
      else q->drcha = 0;
    }
  }
  else if (it->izqda == 0) {         //Si sólo tiene hijo a la derecha
    if (it == laraiz) {              //Si es la raíz
      laraiz = it->drcha;            //promocionamos al hijo a la derecha
      delete it;                     //Borramos el nodo
      laraiz->padre = 0;             //Actualizamos padre
    }
    else {                           //Si no es la raíz
      q = it->padre;                 //q apunta al padre
      if (q->izqda == it) {          //Si es hijo izqda de su padre,
        q->izqda = it->drcha;        //promocionamos a su hijo derecho
        it->drcha->padre = q;        //Actualizamos padre del nodo promocionado
        delete it;                   //Borramos el nodo
      }
      else {                         //Si es hijo drcha de su padre,
        q->drcha = it->drcha;        //promocionamos a su hijo derecho
        it->drcha->padre = q;        //Actualizamos padre del hijo promocionado
        delete it;                   //Borramos el nodo
      }
    }
  }
  else if (it->drcha == 0) {         //Si sólo tiene hijo a la derecha
    if (it == laraiz) {              //Si es la raíz,
      laraiz = it->izqda;            //promocionamos al hijo a la izquierda
      delete it;                     //Borramos el nodo
      laraiz->padre = 0;             //Actualizamos padre
    }
    else {                           //Si no es la raíz
      q = it->padre;                 //q apunta al padre
      if (q->drcha == it) {          //Si es hijo izqda de su padre,
        q->drcha = it->izqda;        //promocionamos a su hijo izquierdo
        it->izqda->padre = q;        //Actualizamos padre del hijo promocionado
        delete it;                   //Borramos el nodo
      }
      else {                         //Si es hijo drcha de su padre,
        q->izqda = it->izqda;        //promocionaos a su hijo izquierdo
        it->izqda->padre = q;        //Actualizamos padre del hijo promocionado
        delete it;                   //Borramos el nodo
      }
    }
  }
  else {                             //Si tiene dos hijos
    q = it->drcha;                   //q apunta al hijo derecho
    while (q->izqda != 0)            //Mientras haya camino por la izquierda,
      q = q->izqda;                  //descendemos 
    // En q esta el siguiente, que ocupara lugar de it
    aux = q->padre;                  //aux apunta al padre del siguiente
    if (q->drcha == 0){              //Si el siguiente no tiene hijo derecho
      if (aux->izqda == q)           //Si el siguiente es hijo izqda de su padre
        aux->izqda = 0;              //actualizamos el puntero en el padre
      else                           //Si el siguiente es hijo drcha de su padre
        aux->drcha = 0;              //actualizamos el puntero en el padre
      //delete q;
    }
    else {                           //Si el siguiente tiene hijo derecha
      if (aux->izqda == q)           //Promocionamos al hijo drcha del siguiente
        aux->izqda = q->drcha;       //para ocupar su lugar
      else
        aux->drcha = q->drcha;
      q->drcha->padre = aux;         //Actualizamos el puntero al padre en el
                                     //nodo promocionado
      //delete q;
    }
    // Ponemos q en el lugar de it
    q->izqda = it->izqda;            //Actualizamos hijo izqda del siguiente
    q->drcha = it->drcha;            //Actualizamos hijo drcha del siguiente
    q->padre = it->padre;            //Actualizamos padre del siguiente
    //Ajustamoa el padre
    if (q->padre != 0) {             //Si q no es la raíz
      aux = q->padre;                //aux apunta al padre
      if (aux->izqda == it)          //Colocamos el siguiente en el lugar de it
        aux->izqda = q;
      else
        aux->drcha = q;
    }
    else
      laraiz = q;                    //Hemos borrado la raiz
    //Ajustamos los hijos
    if (q->izqda != 0)               //Si tiene hijo izquierda,
      q->izqda->padre = q;           //ajustamos su puntero al padre
    if (q->drcha != 0)               //Si tiene hijo derecha,
      q->drcha->padre = q;           //ajustamos su puntero al padre
    // it queda descolgado y ya se puede eliminar
    delete it;
  }  
  return dev;  //Devolveremos el siguiente en el ABB
               //Lo habíamos calculado al principio
}
    
/***************************************************************/

template <class Tbase>
void ABB<Tbase>::equilibrar(){
  int i;
  nodo **v;
  nodo *p;
  
  if (nelementos > 1){                //Si hay más de 1 nodo
    v = new nodo*[nelementos];        //Reservamos un vector de punteros a nodo
    for (p=primero(),i=0; p!=final() ;p=siguiente(p),i++)
      v[i] = p;                       //Guardamos los nodos en el vector
    enganchar(laraiz, v, nelementos); //Usamos enganchar para reconstruir el ABB
    laraiz->padre = 0;                //Actualizamos la raíz del padre
    delete [] v;                      //Liberamos el vector
  }
}

/***************************************************************/

template <class Tbase>
inline void ABB<Tbase>::clear(){
  destruir(laraiz);   //Destruimos el ABB
  laraiz= 0;          //Actualizamos laraiz
  nelementos= 0;      //Actualizamos nelementos
}

/***************************************************************/

template <class Tbase>
inline int ABB<Tbase>::size() const{
  return nelementos;
}

/***************************************************************/

template <class Tbase>
inline bool ABB<Tbase>::empty() const{
  return (laraiz==0);
}

/***************************************************************/

template <class Tbase>
inline bool ABB<Tbase>::operator == (const ABB<Tbase>& otro) const{
  Iterador it1,it2;
  
  if (nelementos != otro.nelementos)  //Si nelementos es distinto
    return false;                  //no son iguales
  for (it1=this->primero(),it2=otro.primero(); //Recorremos los dos ABB
       it1!=final(); 
       it1=this->siguiente(it1),it2=otro.siguiente(it2))
    if (this->etiqueta(it1)!=otro.etiqueta(it2)) //Comparamos las etiquetas
      return false;
  return true;  //Si hemos alcanzado esta línea, son iguales
}

/***************************************************************/

template <class Tbase>
inline bool ABB<Tbase>::operator != (const ABB<Tbase>& otro) const{
  return !(*this == otro); //Invocamos el operador ==
}

/***************************************************************/

#endif
