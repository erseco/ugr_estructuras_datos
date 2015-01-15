/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano <erseco@correo.ugr.es>
 * ---------------------------------------------
 *
 *  Implementación del T.D.A Diccionario
 *
 ******************************************************************************/

Diccionario::Diccionario()
{

    // Creamos el nodo que sera el raiz, le ponemos '_' por poner algo
    info nodo_raiz('*', false);


    // datos = ArbolGeneral<info>(nodo_raiz);
    datos = tree<info>(nodo_raiz);

}

vector<string> Diccionario::PalabrasLongitud(int longitud)
{

    vector<string> palabras;





    return palabras;

}

bool Diccionario::Esta(string palabra)
{

    return true;

}

// void Diccionario::insertar_cadena( char *cad, int i, tnodo n, tarbol T)
// {

//     tnodo p,nuevo_nodo;
//     telemento x;
//     int salir = 0;

//     if (cad[i]=='\0')
//     {
//         x = Etiqueta(n,T);
//         x.contador ++;
//         Reetiquetar(n,x,T);
//     }
//     else
//     {
//         p=Hijo_Izquierda(n,T);
//         while ( p!=NODO_NULO && !salir)
//         {
//             x = Etiqueta(p,T);
//             if (x.caracter == cad[i])
//                 salir = 1;
//             else
//                 p=Hermano_Derecha(p,T);
//         }
//         if (salir)
//             Insertar_Cadena(cad,++i,p,T);
//         else
//         {
//             x.caracter = cad[i];
//             x.contador = 0;
//             nuevo_nodo = Crear(x);
//             Insertar_HI(n, nuevo_nodo,T);
//             Insertar_Cadena(cad,++i,nuevo_nodo,T);
//         }
//     }
// }

void Diccionario::Agrega(string palabra)
{

    // Con tree
    tree<info>::node n = datos.root();

    int i_letra = 0;

    bool salir = false;

    if (!datos.empty())
    {
        while (!salir)
        {

            char letra = palabra[i_letra];
            bool ultima = (i_letra == palabra.size() - 1);

            if (letra == (n.etiqueta)->.c)  // Letra encontrada, pasamos al siguiente hijo izquierda
            {
                i_letra++;
                n = n.left();

            }
            else if (n.next_sibling() == 0) // Hemos llegado al ultimo hermano No está la letra, habrá que añadirla
            {
                salir = true;
            }
            else        // Pasamos al de al lado
            {
                n = n.next_sibling();

            }

        }
    }

    while (i_letra < palabra.size())
    {

        char letra = palabra[i_letra];
        bool ultima = (i_letra == palabra.size() - 1);


        info inf(letra, ultima);

        // Creamos un nuevo arbol con el nodo nuevo
        tree<info> aux(inf);

        // Lo insertamos en el arbol
        if (datos.empty())
        {
            datos.root().insert_left(aux);
        }
        else
        {
            n.insert_left(aux);
        }

        // Nos pasamos a ese hijo recien insertado
        n = n.left();

        // pasamos a la letra siguiente
        i_letra++;

    }

    cout << datos;

    // Con Arbol General
    // ArbolGeneral<info>::Nodo n = datos.raiz();

    // int i_letra = 0;

    // bool salir = false;

    // if (!datos.empty())
    // {
    //     while (!salir)
    //     {

    //         char letra = palabra[i_letra];
    //         bool ultima = (i_letra == palabra.size() - 1);

    //         if (letra == n->etiqueta.c)  // Letra encontrada, pasamos al siguiente hijo izquierda
    //         {
    //             i_letra++;
    //             n = datos.hijomasizquierda(n);

    //         }
    //         else if (datos.hermanoderecha(n) == 0) // Hemos llegado al ultimo hermano No está la letra, habrá que añadirla
    //         {
    //             salir = true;
    //         }
    //         else        // Pasamos al de al lado
    //         {
    //             n = datos.hermanoderecha(n);

    //         }

    //     }
    // }

    // while (i_letra < palabra.size())
    // {

    //     char letra = palabra[i_letra];
    //     bool ultima = (i_letra == palabra.size() - 1);


    //     info inf(letra, ultima);

    //     // Creamos un nuevo arbol con el nodo nuevo
    //     ArbolGeneral<info> aux(inf);

    //     // Lo insertamos en el arbol
    //     if (datos.empty())
    //     {
    //         datos.insertar_hijomasizquierda(datos.raiz(), aux);
    //     }
    //     else
    //     {
    //         datos.insertar_hijomasizquierda(n, aux);
    //     }

    //     // Nos pasamos a ese hijo recien insertado
    //     n = datos.hijomasizquierda(n);

    //     // pasamos a la letra siguiente
    //     i_letra++;

    // }

    // cout << datos;


}


istream& operator>> (istream & is,Diccionario &D)
{
    // Recorremos el stream

    string palabra;

    // Vamos obteniendo palabras
    while (getline(is, palabra))
    {





        //if (!D.Esta(palabra))
            D.Agrega(palabra);

    }


    //     // Bandera para salir del bucle cuando se llegue al salto de linea
    //     // se utiliza este sistema para no usar break
    //     bool salir = false;

    //     // Recorre el stream
    //     while (!salir && is)
    //     {
    //         string translation;

    //         // Obtenemos la siguiente palabra (usamos como separador el punto y coma)
    //         getline(is, translation, ';');


    //         // Si detectamos un salto de linea...
    //         if (is.peek() == '\n')
    //         {
    //             // ...obtenemos el siguiente caracter (salto) y salimos del bucle
    //             is.get();
    //             salir = true;
    //         }

    //         // Agregamos la traduccion a la colección de traducciones ya que [] si no existe lo crea
    //         t.datos[palabra].add(translation);

    //     }
    // }

    // Devolvemos la referencia al flujo
    return is;
}



ostream & operator<<(ostream & os, const Diccionario &D)
{


    //ArbolGeneral<info>::iter_preorden it;

    // for (it=D.datos.begin(); it!= D.datos.end(); ++it)
    // {
    //     //os << (*it)->c << " \\";
    // }


    // Devolvemos la referencia al flujo
    return os;
}
