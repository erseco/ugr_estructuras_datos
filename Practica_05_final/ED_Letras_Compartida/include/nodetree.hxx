//-*-Mode: C++;-*-

#include <cassert>

//
// Operaciones de nodewrapper
//
template <typename T>
inline
tree<T>::nodewrapper::nodewrapper()
{
    pad= izda= hermanodcha= 0;
}


template <typename T>
inline
tree<T>::nodewrapper::nodewrapper(const T & e)
  : etiqueta(e)
{
}


//
// Operaciones de node
//

template <typename T>
inline
tree<T>::node::node()
{
  elnodo = 0;
}


template <typename T>
inline
tree<T>::node::node(const T & e)
{
  elnodo = new nodewrapper(e);
}


template <typename T>
inline
tree<T>::node::node(const typename tree<T>::node & n)
  : elnodo(n.elnodo)
{
}

template <typename T>
inline
tree<T>::node::node(typename tree<T>::node *n)
{
  if (n != 0)
    elnodo = n->elnodo;
  else
    elnodo = 0;
}

template <typename T>
inline
typename tree<T>::node &
tree<T>::node::operator=(const typename tree<T>::node & n)
{
  if (&n != this) {
    if (n.null())
      elnodo = 0;
    else
      elnodo = n.elnodo;
   }

  return *this;
}

template <typename T>
inline
bool tree<T>::node::null() const
{
  return (elnodo == 0);
}

template <typename T>
inline
void tree<T>::node::setlabel(const T& e)
{
  elnodo->etiqueta = e;
}

template <typename T>
inline
void tree<T>::node::parent(typename tree<T>::node n)
{
  elnodo->pad = n;
}

template <typename T>
inline
void tree<T>::node::left(typename tree<T>::node n)
{
  elnodo->izda = n;
}

template <typename T>
inline
void tree<T>::node::next_sibling(typename tree<T>::node n)
{
  elnodo->hermanodcha = n;
}

template <typename T>
inline
typename tree<T>::node
tree<T>::node::parent() const
{
  return (elnodo->pad);
}

template <typename T>
inline
typename tree<T>::node tree<T>::node::left() const
{
  return (elnodo->izda);
}

template <typename T>
inline
typename tree<T>::node tree<T>::node::next_sibling() const
{
  return (elnodo->hermanodcha);
};

template <typename T>
inline
T & tree<T>::node::operator*()
{
  return elnodo->etiqueta;
};

template <typename T>
inline
const T & tree<T>::node::operator*() const
{
  return elnodo->etiqueta;
};

template <typename T>
void tree<T>::node::remove()
{
  delete elnodo;
  elnodo = 0;
};

template <typename T>
inline
bool tree<T>::node::operator==(const node & n) const
{
  return (elnodo == n.elnodo);
};

template <typename T>
inline
bool tree<T>::node::operator!=(const node & n) const
{
  return elnodo != n.elnodo;
};

/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
// CONST_NODE
/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//
// Operaciones de const_node
//

template <typename T>
inline
tree<T>::const_node::const_node()
{
  elnodo = 0;
}




template <typename T>
inline
tree<T>::const_node::const_node(const typename tree<T>::const_node & n)
  : elnodo(n.elnodo)
{
}


template <typename T>
inline
tree<T>::const_node::const_node(const typename tree<T>::node & n)
  : elnodo(n.elnodo)
{
}

template <typename T>
inline
tree<T>::const_node::const_node(typename tree<T>::const_node *n)
{
  if (n != 0)
    elnodo = n->elnodo;
  else
    elnodo = 0;
}

template <typename T>
inline
typename tree<T>::const_node &
tree<T>::const_node::operator=(const typename tree<T>::const_node & n)
{
  if (&n != this) {
    if (n.null())
      elnodo = 0;
    else
      elnodo = n.elnodo;
   }

  return *this;
}

template <typename T>
inline
bool tree<T>::const_node::null() const
{
  return (elnodo == 0);
}




template <typename T>
inline
typename tree<T>::const_node
tree<T>::const_node::parent() const
{
  return (elnodo->pad);
}

template <typename T>
inline
typename tree<T>::const_node tree<T>::const_node::left() const
{
  return (elnodo->izda);
}

template <typename T>
inline
typename tree<T>::const_node tree<T>::const_node::next_sibling() const
{
  return (elnodo->hermanodcha);
};

template <typename T>
inline
const T & tree<T>::const_node::operator*() const
{
  return elnodo->etiqueta;
};


template <typename T>
inline
bool tree<T>::const_node::operator==(const const_node & n) const
{
  return (elnodo == n.elnodo);
};

template <typename T>
inline
bool tree<T>::const_node::operator!=(const const_node & n) const
{
  return elnodo != n.elnodo;
};




