//-*-Mode: C++;-*-

/**
  @file tree.template
  @brief TDA tree
  
 */

/*
************************************************************ 
* Implementación
************************************************************
*/

/*
  Función de Abstracción:
  ----------------------------

  Invariante de Representación:
  ----------------------------
  
*/


#include <cassert>
#include <iostream>

using namespace std;


/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <typename T>
void tree<T>::destroy(typename tree<T>::node n)
{  
  if (!n.null()) {
    destroy(n.left());
    destroy(n.next_sibling());
    n.remove();
  }
}


template <typename T>
void tree<T>::copy(typename tree<T>::node &dest, const typename tree<T>::node &orig, const typename tree<T>::node &pad)
{
    
  if (orig.null()) {
    dest = typename tree<T>::node();
  }
  else {
      dest = node(*orig);
      typename tree<T>::node aux(dest.left());
      copy (aux, orig.left(), dest);
      if (!aux.null()) {
        aux.parent(dest);
      }
      dest.left(aux);
      
      aux = dest.next_sibling();
      copy (aux, orig.next_sibling(), pad);
      if (!aux.null()) {
        aux.parent(pad);
      }
      dest.next_sibling(aux);
    }
}


template <typename T>
typename tree<T>::size_type
tree<T>::count(typename tree<T>::node n) const
{
  if (n.null())
    return 0;
  else
    return 1 + count(n.left()) + count(n.next_sibling());
}


template <typename T>
bool tree<T>::equals(typename tree<T>::node n1, typename tree<T>::node n2) const
{
  if (n1.null() && n2.null())
    return true;
  if (n1.null() || n2.null())
    return false;
  if (*n1 != *n2)
    return false;
  if (!equals(n1.left(),n2.left()))
    return false;
  if (!equals(n1.next_sibling(),n2.next_sibling()))
    return false;
  return true;
}


/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <typename T>
inline tree<T>::tree()
{
}


template <typename T>
tree<T>::tree(const T & e) : laraiz(e)
{
}


template <typename T>
typename tree<T>::node tree<T>::setroot(const T & e){
  if (!laraiz.null())
    laraiz.elnodo->etiqueta = e;
  else
      laraiz = typename tree<T>::node(e);
  return laraiz; 
}


template <typename T>
tree<T>::tree (const tree<T> & a)
{
  copy(laraiz, a.laraiz, typename tree<T>::node());
  if (!laraiz.null())
    laraiz.parent(typename tree<T>::node());
}

template <typename T>
void tree<T>::assign_subtree(const tree<T> & a, typename tree<T>::node n)
{
 if (&a != this) {
   destroy(laraiz);
   typename tree<T>::node aux;
   copy(laraiz, n, typename tree<T>::node());
   if (!laraiz.next_sibling().null()) {
       destroy(laraiz.next_sibling());
       laraiz.next_sibling(aux);
   }
   if (!laraiz.null())
     laraiz.parent(typename tree<T>::node());
 }
 else {  // Reemplazar el receptor por un subarbol suyo.
   typename tree<T>::node nod;
   typename tree<T>::node aux;
   copy(nod, n, typename tree<T>::node());
   destroy(laraiz);
   laraiz = nod;
   if (!nod.next_sibling().null()) {
       destroy(nod.next_sibling());
       laraiz.next_sibling(aux);
   }
   if (!laraiz.null())
     laraiz.parent(typename tree<T>::node());
 }
} 

template <typename T>
inline tree<T>::~tree()
{
  destroy(laraiz);
}


template <typename T>
tree<T>& 
tree<T>::operator=(const tree<T> & a)
{
  if (&a != this) {
    destroy(laraiz);
    copy(laraiz, a.laraiz, typename tree<T>::node());
    if (!laraiz.null())
      laraiz.parent(typename tree<T>::node());
  }
  return *this;
}


template <typename T>
inline typename tree<T>::node tree<T>::root() const
{
  return laraiz;
}


template <typename T>
void tree<T>::prune_left(typename tree<T>::node n, tree<T> & dest)
{
  if (!n.left().null()){
  	destroy(dest.laraiz);
  	dest.laraiz=n.left();
  	n.left(n.left().next_sibling());
  	dest.laraiz.parent(typename tree<T>::node());
  	dest.laraiz.next_sibling(typename tree<T>::node());
  }
}


template <typename T>
void tree<T>::prune_right_sibling(typename tree<T>::node n, tree<T> & dest)
{
  if (!n.next_sibling().null()){
  	destroy(dest.laraiz);
  	dest.laraiz=n.next_sibling();
  	n.next_sibling(n.next_sibling().next_sibling());
  	dest.laraiz.parent(typename tree<T>::node());
  	dest.laraiz.next_sibling(typename tree<T>::node());
  }
}


template <typename T>
typename tree<T>::node tree<T>::insert_left(typename tree<T>::node n, const T & e)
{
  typename tree<T>::node nuevo(e);
  
  nuevo.next_sibling(n.left());
  nuevo.parent(n);
  n.left(nuevo);
  
  return nuevo;
}


template <typename T>
typename tree<T>::node tree<T>::insert_left(typename tree<T>::node n, tree<T> & rama)
{
  if (!rama.empty()){
  	typename tree<T>::node nuevo(*(rama.laraiz));
  	nuevo.left(rama.laraiz.left());
  	
  	typename tree<T>::node aux=rama.laraiz.left();
  	while(!aux.null()){
  		aux.parent(nuevo);
  		aux=aux.next_sibling();
  	}
  	rama.laraiz.remove();
  	
  	nuevo.next_sibling(n.left());
  	nuevo.parent(n);
  	n.left(nuevo);
  	
  	return nuevo;
  }
  
  return typename tree<T>::node();
}


template <typename T>
typename tree<T>::node tree<T>::insert_right_sibling(typename tree<T>::node n, const T & e)
{
  typename tree<T>::node nuevo(e);
  
  nuevo.next_sibling(n.next_sibling());
  n.next_sibling(nuevo);
  nuevo.parent(n.parent());
  
  return nuevo;
}


template <typename T>
typename tree<T>::node tree<T>::insert_right_sibling(typename tree<T>::node n, tree<T> & rama)
{
	typename tree<T>::node nuevo;
	if (!rama.empty()){
		nuevo = *(rama.laraiz);
		nuevo.left(rama.laraiz.left());
		
		typename tree<T>::node aux=rama.laraiz.left();
		while(!aux.null()){
			aux.parent(nuevo);
			aux=aux.next_sibling();
		}
		rama.laraiz.remove();
		
		nuevo.next_sibling(n.next_sibling());
		nuevo.parent(n.parent());
		n.next_sibling(nuevo);  	
  	}
  	return nuevo;
}


template <typename T>
void tree<T>::clear()
{
  destroy(laraiz);
  laraiz = typename tree<T>::node();
}


template <typename T>
inline
typename tree<T>::size_type
tree<T>::size() const
{
  return count(laraiz);
}


template <typename T>
inline bool tree<T>::empty() const
{
  return laraiz == typename tree<T>::node();
}


template <typename T>
inline bool tree<T>::operator==(const tree<T>& a) const
{
  return equals(laraiz, a.laraiz);
}


template <typename T>
inline bool tree<T>::operator!=(const tree<T>& a) const
{
  return !(*this == a);  
}

/*
  ************************************************************
  Iteradores
  ************************************************************
  */


/*
  Iterador para recorrido en Preorder
*/

template <typename T>
inline tree<T>::preorderiterator::preorderiterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::preorderiterator::preorderiterator(
  typename tree<T>::node n): elnodo(n)
{
}

template <typename T>
inline bool tree<T>::preorderiterator::operator!=(
const tree<T>::preorderiterator & i) const
{
  return elnodo != i.elnodo;
}


template <typename T>
inline bool tree<T>::preorderiterator::operator==(
const tree<T>::preorderiterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline T& tree<T>::preorderiterator::operator*()
{
  return *elnodo;
}


template <typename T>
typename tree<T>::preorderiterator &
tree<T>::preorderiterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.left().null()) {
  	 elnodo = elnodo.left();
  }
  else if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
  }
  else {
    while ((!elnodo.parent().null()) &&
	       (elnodo.parent().next_sibling() == elnodo ||
	        elnodo.parent().next_sibling().null()))
      elnodo = elnodo.parent();
    if (elnodo.parent().null())
      elnodo = typename tree<T>::node();
    else
      elnodo = elnodo.parent().next_sibling();
  }

  return *this;
}

template <typename T>
typename tree<T>::preorderiterator  
tree<T>::preorderiterator::operator++(int i)
{
  typename  tree<T>::preorderiterator aux(*this);
  ++(*this);
  return aux;
}


template <typename T>
inline typename tree<T>::preorderiterator
tree<T>::beginPreorder()
{
  return preorderiterator(laraiz);
}

template <typename T>
inline typename tree<T>::preorderiterator
tree<T>::endPreorder()
{
  return preorderiterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador para recorrido en Inorder
*/

template <typename T>
inline tree<T>::inorderiterator::inorderiterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::inorderiterator::inorderiterator(typename tree<T>::node n)
{
    if (n.null()) {
        elnodo = n;
    }
    else {
        bool que = (n.left().null());
        pila_nodos.push(pair<node,bool>(n,que));
        pair<node,bool> aux = pila_nodos.top();
        
        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;     
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
}

template <typename T>
inline bool tree<T>::inorderiterator::operator!=(
const typename tree<T>::inorderiterator & i) const
{
  return !(*this==i);
}


template <typename T>
inline bool tree<T>::inorderiterator::operator==(
const typename tree<T>::inorderiterator & i) const
{
  return ((elnodo == i.elnodo) && (pila_nodos == i.pila_nodos));
}

template <typename T>
inline T& tree<T>::inorderiterator::operator*()
{
  return *elnodo;
}

template <typename T>
typename tree<T>::inorderiterator &
tree<T>::inorderiterator::operator++()
{
    if (pila_nodos.size() > 0) {
        bool que;
        pair<node,bool> aux = pila_nodos.top();
        
        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;     
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
    else {
        elnodo = typename tree<T>::node();
    }

  return *this;
}

template <typename T>
inline typename tree<T>::inorderiterator
tree<T>::beginInorder()
{
  return inorderiterator(root());
}


template <typename T>
inline typename tree<T>::inorderiterator
tree<T>::endInorder()
{
  return inorderiterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador para recorrido en Postorder
*/


template <typename T>
inline tree<T>::postorderiterator::postorderiterator()
{
  elnodo = typename tree<T>::node();
}

template <typename T>
inline tree<T>::postorderiterator::postorderiterator(
  typename tree<T>::node n)
  : elnodo(n)
{
}

template <typename T>
inline bool tree<T>::postorderiterator::operator!=(
const tree<T>::postorderiterator & i) const
{
  return elnodo != i.elnodo;
}

template <typename T>
inline bool tree<T>::postorderiterator::operator==(
const tree<T>::postorderiterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline T& tree<T>::postorderiterator::operator*()
{
  return *elnodo;
}


template <typename T>
typename tree<T>::postorderiterator &
tree<T>::postorderiterator::operator++()
{
  if (elnodo.parent().null()) {
    elnodo = typename tree<T>::node();
  }
  else
    if (elnodo.parent().left() == elnodo) {
      if (!elnodo.next_sibling().null()) {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        } 
      }
      else {
        elnodo = elnodo.parent();
      }
    }
    else {// elnodo es hijo a la derecha de su padre
      if (elnodo.next_sibling().null()) {
          elnodo = elnodo.parent();
      }
      else {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        } 
      }
    }

  return *this;
}

template <typename T>
inline typename tree<T>::postorderiterator
tree<T>::beginPostorder()
{
  if (!root().null()) {
    node n = root();
    
    while (!n.left().null())
        n = n.left();
    
    return postorderiterator(n);
  }
  else {
      return endPostorder();
  }
}

template <typename T>
inline typename tree<T>::postorderiterator
tree<T>::endPostorder()
{
  return postorderiterator(typename tree<T>::node());
}


/*
  Iterador para recorrido por Niveles
*/

template <typename T>
inline tree<T>::leveliterator::leveliterator()
{
}

template <typename T>
inline tree<T>::leveliterator::leveliterator(
  typename tree<T>::node n) : elnodo(n)
{
    if (!n.null())
        cola_Nodos.push(n);
}
template <typename T>
inline bool tree<T>::leveliterator::operator!=(
const tree<T>::leveliterator & i) const
{
  return !(*this==i);
}

template <typename T>
inline bool tree<T>::leveliterator::operator==(
const tree<T>::leveliterator & i) const
{
  return (elnodo == i.elnodo) && (cola_Nodos == i.cola_Nodos);
}

template <typename T>
inline T& tree<T>::leveliterator::operator*()
{
  return *elnodo;
}


template <typename T>
typename tree<T>::leveliterator &
tree<T>::leveliterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
      if (!elnodo.null() && !elnodo.left().null()) {
        cola_Nodos.push(elnodo);
      }
  }
  else {
      if (cola_Nodos.size() > 0) {
        typename tree<T>::node tope = cola_Nodos.front();
        cola_Nodos.pop();
        elnodo = tope.left();
        if (!elnodo.null() && !elnodo.left().null()) {
            cola_Nodos.push(elnodo);
        }
      }
      else {
        elnodo = typename tree<T>::node();
      }
  }

  return *this;
}


template <typename T>
inline typename tree<T>::leveliterator
tree<T>::beginlevel()
{
  if (!root().null())
    return leveliterator(laraiz);
  else
    return leveliterator();
}

template <typename T>
inline typename tree<T>::leveliterator
tree<T>::endlevel()
{
  return leveliterator(typename tree<T>::node());
}

/*
  ************************************************************
  Iteradores constantes
  ************************************************************
  */


/*
  Iterador cosntante para recorrido en Preorder
*/

template <typename T>
inline tree<T>::const_preorderiterator::const_preorderiterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::const_preorderiterator::const_preorderiterator(
  typename tree<T>::node n): elnodo(n)
{
}

template <typename T>
inline bool tree<T>::const_preorderiterator::operator!=(
const tree<T>::const_preorderiterator & i) const
{
  return elnodo != i.elnodo;
}


template <typename T>
inline bool tree<T>::const_preorderiterator::operator==(
const tree<T>::const_preorderiterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline const T& tree<T>::const_preorderiterator::operator*() const
{
  return *elnodo;
}


template <typename T>
typename tree<T>::const_preorderiterator &
tree<T>::const_preorderiterator::operator++()
{
  if (elnodo.null())
    return *this;

 if (!elnodo.left().null()) {
  	 elnodo = elnodo.left();
  }
  else if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
  }
  else {
    while ((!elnodo.parent().null()) &&
	       (elnodo.parent().next_sibling() == elnodo ||
	        elnodo.parent().next_sibling().null()))
      elnodo = elnodo.parent();
    if (elnodo.parent().null())
      elnodo = typename tree<T>::node();
    else
      elnodo = elnodo.parent().next_sibling();
  }

  return *this;
}


template <typename T>
inline typename tree<T>::const_preorderiterator
tree<T>::beginPreorder() const
{
  return const_preorderiterator(laraiz);
}

template <typename T>
inline typename tree<T>::const_preorderiterator
tree<T>::endPreorder() const
{
  return const_preorderiterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador constante para recorrido en Inorder
*/

template <typename T>
inline tree<T>::const_inorderiterator::const_inorderiterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::const_inorderiterator::const_inorderiterator(typename tree<T>::node n)
{
    if (n.null()) {
        elnodo = n;
    }
    else {
        bool que = (n.left().null());
        pila_nodos.push(pair<node,bool>(n,que));
        pair<node,bool> aux = pila_nodos.top();
        
        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;     
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
}

template <typename T>
inline bool tree<T>::const_inorderiterator::operator!=(
const typename tree<T>::const_inorderiterator & i) const
{
  return !(*this==i);
}


template <typename T>
inline bool tree<T>::const_inorderiterator::operator==(
const typename tree<T>::const_inorderiterator & i) const
{
  return ((elnodo == i.elnodo) && (pila_nodos == i.pila_nodos));
}

template <typename T>
inline const T& tree<T>::const_inorderiterator::operator*() const
{
  return *elnodo;
}

template <typename T>
typename tree<T>::const_inorderiterator &
tree<T>::const_inorderiterator::operator++()
{
    if (pila_nodos.size() > 0) {
        bool que;
        pair<node,bool> aux = pila_nodos.top();
        
        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;     
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
    else {
        elnodo = typename tree<T>::node();
    }

  return *this;
}

template <typename T>
inline typename tree<T>::const_inorderiterator
tree<T>::beginInorder() const
{
  return const_inorderiterator(root());
}


template <typename T>
inline typename tree<T>::const_inorderiterator
tree<T>::endInorder() const
{
  return const_inorderiterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador constante para recorrido en Postorder
*/


template <typename T>
inline tree<T>::const_postorderiterator::const_postorderiterator()
{
  elnodo = typename tree<T>::node();
}

template <typename T>
inline tree<T>::const_postorderiterator::const_postorderiterator(
  typename tree<T>::node n)
  : elnodo(n)
{
}

template <typename T>
inline bool tree<T>::const_postorderiterator::operator!=(
const tree<T>::const_postorderiterator & i) const
{
  return elnodo != i.elnodo;
}

template <typename T>
inline bool tree<T>::const_postorderiterator::operator==(
const tree<T>::const_postorderiterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline const T& tree<T>::const_postorderiterator::operator*() const
{
  return *elnodo;
}


template <typename T>
typename tree<T>::const_postorderiterator &
tree<T>::const_postorderiterator::operator++()
{
  if (elnodo.parent().null()) {
    elnodo = typename tree<T>::node();
  }
  else
    if (elnodo.parent().left() == elnodo) {
      if (!elnodo.next_sibling().null()) {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        } 
      }
      else {
        elnodo = elnodo.parent();
      }
    }
    else {// elnodo es hijo a la derecha de su padre
      if (elnodo.next_sibling().null()) {
          elnodo = elnodo.parent();
      }
      else {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        } 
      }
    }

  return *this;
}

template <typename T>
inline typename tree<T>::const_postorderiterator
tree<T>::beginPostorder() const
{
  if (!root().null()) {
    node n = root();
    
    while (!n.left().null())
        n = n.left();
    
    return postorderiterator(n);
  }
  else {
      return endPostorder();
  }
}

template <typename T>
inline typename tree<T>::const_postorderiterator
tree<T>::endPostorder() const
{
  return const_postorderiterator(typename tree<T>::node());
}


/*____________________________________________________________ */

/*
  Iterador cosntante para recorrido por Niveles
*/


template <typename T>
inline tree<T>::const_leveliterator::const_leveliterator()
{
}

template <typename T>
inline tree<T>::const_leveliterator::const_leveliterator(
  typename tree<T>::node n) : elnodo(n)
{
    if (!n.null())
        cola_Nodos.push(n);
}
template <typename T>
inline bool tree<T>::const_leveliterator::operator!=(
const tree<T>::const_leveliterator & i) const
{
  return !(*this==i);
}

template <typename T>
inline bool tree<T>::const_leveliterator::operator==(
const tree<T>::const_leveliterator & i) const
{
  return (elnodo == i.elnodo) && (cola_Nodos == i.cola_Nodos);
}

template <typename T>
inline const T& tree<T>::const_leveliterator::operator*() const
{
  return *elnodo;
}


template <typename T>
typename tree<T>::const_leveliterator &
tree<T>::const_leveliterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
      if (!elnodo.null() && !elnodo.left().null()) {
        cola_Nodos.push(elnodo);
      }
  }
  else {
      if (cola_Nodos.size() > 0) {
        typename tree<T>::node tope = cola_Nodos.front();
        cola_Nodos.pop();
        elnodo = tope.left();
        if (!elnodo.null() && !elnodo.left().null()) {
            cola_Nodos.push(elnodo);
        }
      }
      else {
        elnodo = typename tree<T>::node();
      }
  }

  return *this;
}


template <typename T>
inline typename tree<T>::const_leveliterator
tree<T>::beginlevel() const
{
  if (!root().null())
    return const_leveliterator(laraiz);
  else
    return const_leveliterator();
}

template <typename T>
inline typename tree<T>::const_leveliterator
tree<T>::endlevel() const
{
  return const_leveliterator(typename tree<T>::node());
}


