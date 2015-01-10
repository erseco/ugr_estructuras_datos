/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Implementación del T.D.A Arbol Genral
 *
 ******************************************************************************/

template <class Tbase>
void ArbolGeneral<Tbase>::insertar(vector<Tbase> & v)
{
    nodo * nod = laraiz;


    ArbolGeneral<Tbase>& rama = *this;

    for (int i = 0; i < v.size(); i++)
    {
        nod= new nodo;             //Reservamos un nuevo nodo
        nod->etiqueta = v[i];       //Leemos la etiqueta

        insertar_hijomasizquierda(nod, rama);

        // nod = nod->izqda;  //Leemos recursivamente el hijo izquierda
        // nod = nod->drcha;  //Leemos recursivamente el hijo derecha

        //if (nod->izqda!=0)         //Si hay hijo izquierda,
          //nod->izqda->padre=nod;   //actualizamos su padre

        //if (nod->drcha!=0)         //Si hay hijo derecha,
          //nod->drcha->padre=nod;   //actualizamos su padre
    }

}


/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral <Tbase> :: destruir (nodo * n){
  if (n!=0){             //Si no es un nodo nulo,
    destruir(n->izqda);  //destruimos recursivamente su hijo izquierda y
    destruir(n->drcha);  //destruimos recursivamente su hijo derecha
    delete n;            //Una vez borrados los descendientes, borramos el nodo
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo * & dest, nodo * orig){
  if (orig == 0)                      //Si el nodo origen es nulo,
    dest = 0;
  else{                               //Si no es el nodo nulo,
    dest = new nodo;                  //Reservamos el nodo destino
    dest->etiqueta = orig->etiqueta;  //Copiamos la etiqueta
    copiar(dest->izqda, orig->izqda); //Copiamos recursivamente el hijo izqda
    copiar(dest->drcha, orig->drcha); //Copiamos recursivamente el hijo drcha
    if (dest->izqda != 0)             //Si hay hijo izquierda,
      dest->izqda->padre = dest;      //actualizamos su padre
    if (dest->drcha != 0)             //Si hay hijo derecha,
      dest->drcha->padre = dest;      //actualizamos su padre
  }
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const
{
  if (n==0)      //Si es el nodo nulo,
    return 0;    //devuelve 0
  else
    return 1+contar(n->izqda)+contar(n->drcha); //Caso general (recursivo)
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const
{
  if (n1==0 && n2==0)                        //Si los dos nodos son nulos,
    return true;                             //devolvemos true
  else if (n1==0 || n2==0)                   //Si uno es nulo y el otro no
    return false;                            //devolvemos false
  else if (n1->etiqueta!=n2->etiqueta)       //Si sus etiquetas son distintas
    return false;                            //devolvemos false
  else if (!soniguales(n1->izqda,n2->izqda)) //Si los hijos izquierda no son =
    return false;                            //devolvemos false
  else if (!soniguales(n1->drcha,n2->drcha)) //Si los hijos derecha no son =
    return false;                            //devolemos false
  else                                       //En otro caso
    return true;                             //devolvemos true
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral <Tbase>::lee_arbol(std::istream& in, nodo * & nod){
  char c;
  in >> c;                     //Lectura de un carácter
  if (c=='n'){                 //Si es 'n'
    nod= new nodo;             //Reservamos un nuevo nodo
    in >> nod->etiqueta;       //Leemos la etiqueta
    lee_arbol(in,nod->izqda);  //Leemos recursivamente el hijo izquierda
    lee_arbol(in,nod->drcha);  //Leemos recursivamente el hijo derecha
    if (nod->izqda!=0)         //Si hay hijo izquierda,
      nod->izqda->padre=nod;   //actualizamos su padre
    if (nod->drcha!=0)         //Si hay hijo derecha,
      nod->drcha->padre=nod;   //actualizamos su padre
  }
  else nod= 0;                 //Si no es 'n' hay un error en la entrada
                               //o no hay más caracteres que leer,
                               //y devolvemos un árbol nulo
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
  if (nod==0)                            //Si el nodo es nulo
    out << "x ";                         //escribimos 'x'
  else {                                 //Si el nodo no es nulo
    out << "n "<< nod->etiqueta << " ";  //escribimos su etiqueta
    escribe_arbol(out,nod->izqda);    //Escribimos el hijo izqda recursivamente
    escribe_arbol(out,nod->drcha);    //Escribimos el hijo drcha recursivamente
  }
}

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <class Tbase>
inline ArbolGeneral<Tbase>::ArbolGeneral(){
  laraiz = 0;  //El constructor por defecto crea un árbol vacío
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
  laraiz = new nodo;      //Crea el nodo raíz
  laraiz->padre =         //No tiene padre,
  laraiz->izqda =         //hijo izquierda
  laraiz->drcha = 0;      //ni hijo derecha.
  laraiz->etiqueta = e;   //Asignamos valor a la etiqueta de la raíz
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral (const ArbolGeneral<Tbase>& v){
  copiar (laraiz,v.laraiz); //Llamamos a copiar desde la raíz
  if (laraiz!=0)            //Si no es el árbol vacío
    laraiz->padre= 0;       //actualizamos el padre
}

/*____________________________________________________________ */

template <class Tbase>
inline ArbolGeneral<Tbase>::~ArbolGeneral(){
  destruir(laraiz);  //Destruye llamando a destruir desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase> &
ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase>&v){
  if (this!=&v){              //Comprobación de rigor. Si no es el mismo objeto
    destruir(laraiz);         //destruimos el objeto *this
    copiar (laraiz,v.laraiz); //Llamamos a copiar desde la raíz
    if (laraiz!=0)            //Si no es el árbol vacío
      laraiz->padre= 0;       //actualizamos el padre
  }
  return *this; //Devolvemos *this para permitir encadenamientos (a=b=c)
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
  destruir(laraiz);     //Destruye el árbol actual
  laraiz = new nodo;    //Reservamos el nodo raíz
  laraiz->padre =       //No tiene padre,
  laraiz->izqda =       //ni hijo izquierda,
  laraiz->drcha = 0;    //ni hijo derecha.
  laraiz->etiqueta= e;  //Damos valor a la etiqueta de la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo
                ArbolGeneral<Tbase>::raiz() const{
  return laraiz;
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo
                ArbolGeneral<Tbase>::hijomasizquierda(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->izqda);
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->drcha);
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->padre);
}

/*____________________________________________________________ */

template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo p){
  assert(p!=0);          //El nodo no debe ser nulo
  return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo p) const{
  assert(p!=0);          //El nodo no debe ser nulo
  return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig,
                                           const Nodo nod){
  destruir(laraiz);    //Destruye el árbol actual
  copiar(laraiz,nod);  //Copiamos el subárbol que cuelga de nod en la raíz
  if (laraiz!=0)       //Si el subárbol copiado no es vacío,
    laraiz->padre=0;   //actualizamos el padre
}


/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(dest.laraiz);    //Destruimos el árbol destino
  dest.laraiz=n->izqda;     //Copia el hijo izquierda de n en la raíz de dest
  if (dest.laraiz!=0) {     //Si el subárbol copiado no es vacío,
    dest.laraiz->padre=0;   //actualizamos el padre
    n->izqda=0;             //y actualizamos el hijo a la izquierda
  }
}


/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(dest.laraiz);    //Destruimos el árbol destino
  dest.laraiz=n->drcha;     //Copia el hijo derecha de n en la raíz de dest
  if (dest.laraiz!=0) {     //Si el subárbol copiado no es vacío,
    dest.laraiz->padre=0;   //actualizamos el padre
    n->drcha=0;             //y actualizamos el hijo a la derecha
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(n->izqda);       //Destruimos el hijo izquierda
  n->izqda=rama.laraiz;     //Copia la rama en el hijo izquierda
  if (n->izqda!=0) {        //Si la rama copiada no es vacía,
    n->izqda->padre= n;     //actualizamos el padre
    rama.laraiz=0;          //y actualizamos la raíz en rama
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(n->drcha);       //Destruimos el hijo izquierda
  n->drcha=rama.laraiz;     //Copia la rama en el hijo derecha
  if (n->drcha!=0) {        //Si la rama copiada no es vacía,
    n->drcha->padre= n;     //actualizamos el padre
    rama.laraiz=0;          //y actualizamos la raíz en rama
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
  destruir(laraiz);    //Destruimos el árbol recursivamente desde la raíz
  laraiz= 0;           //Actualizamos la raíz del árbol
}

/*____________________________________________________________ */

template <class Tbase>
inline int ArbolGeneral<Tbase>::size() const{
  return contar(laraiz);  //Contamos los nodos recursivamente desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolGeneral<Tbase>::empty() const{
  return (laraiz==0);
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator==(const ArbolGeneral<Tbase>& v) const{
  return soniguales(laraiz,v.laraiz); //Comparamos los árboles desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator!=(const ArbolGeneral<Tbase>& v) const{
  return !(*this==v); //Comparamos los árboles desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline istream& operator>> (istream& in, ArbolGeneral<Tbase>& v){
  v.lee_arbol(in,v.laraiz); //Lee el árbol
  return in;                //Devuelve in para permitir encadenamientos
}

/*____________________________________________________________ */

template <class Tbase>
inline ostream& operator<< (ostream& out, const ArbolGeneral<Tbase>& v){
  v.escribe_arbol(out,v.laraiz); //Escribe el árbol
  return out;                    //Devuelve out para permitir encadenamientos
}

/*____________________________________________________________ */



