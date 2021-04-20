#ifndef listaenlazada_h
#define listaenlazada_h

#include "registro.h"

struct tNodo; // Declaraci�n anticipada
typedef tNodo *tLista;
struct tNodo {
   tRegistro reg;
   tLista sig;
};

// Constante global con el nombre del archivo de base de datos:
const string BD = "bd.txt";

// Muestra la lista completa.
void mostrar(tLista lista);

// Inserci�n del registro proporcionado en la lista.
// Devuelve true si se ha podido y false si la lista est� llena.
void insertar(tLista &lista, tRegistro registro, bool &ok);

// Eliminaci�n del registro con el c�digo indicado.
// Devuelve true si se ha podido y false si no est�.
void eliminar(tLista &lista, int code, bool &ok);

// Localiza el registro con ese nombre.
// Devuelve un puntero al nodo, o NULL si no se encuentra.
tLista buscar(tLista lista, int code);

// Carga los datos del archivo de base de datos en la lista.
void cargar(tLista &lista, bool &ok);

// Guarda los datos de la lista en el archivo de base de datos.
void guardar(tLista lista);

// Destruye todas las variables din�micas.
void destruir(tLista &lista);

#endif
