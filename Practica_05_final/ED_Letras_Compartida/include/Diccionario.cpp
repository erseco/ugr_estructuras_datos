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

}

vector<string> Diccionario::PalabrasLongitud(int longitud)
{

}

bool Diccionario::Esta(string palabra)
{

}

void Diccionario::Agrega(string palabra)
{

    info n = datos.raiz();

    n = datos.hijomasizquierda(n);


    for(int i = 0; i < palabra.size(); i++)
    {
        char letra = palabra[i];
        // Es la ultima letra
        bool ultima = (i == palabra.size() - 1);

        // La letra coincide
        if (n.c == letra)
        {
            // Si es la ultima la marcamos (por si no lo estuviera) y hemos terminado
            if (ultima)
                n.final = true;
            else
                // Si no nos vamos al ihjo mas al a iquierda
                n = datos.hijomasizquierda(n);

        }
        else
        {
             n = datos.hermanoderecha(n);

        }




        // Diccionario::info inf(palabra[i], ultima);

        // ArbolGeneral<Diccionario::info>::Nodo n;
        // n->etiqueta = inf;

        // datos.insertar_hijomasizquierda(n, datos);

    }

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

    // Devolvemos la referencia al flujo
    return os;
}
