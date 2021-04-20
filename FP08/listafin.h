#ifndef listafin_h
#define listafin_h

#include "registrofin.h"

const int N = 100;

// Array de registros:
typedef tRegistro tArray[N];

// Tabla: array y contador
typedef struct {
   tArray registros;
   int cont;
} tLista;

// Constante global con el nombre del archivo de base de datos:
const string BD = "bd.txt";

// Muestra la lista completa.
void mostrar(const tLista &lista);

// Inserción del registro proporcionado en la lista.
// Devuelve true si se ha podido y false si la lista está llena.
void insertar(tLista &lista, tRegistro registro, bool &ok);

// Eliminación del registro en la posición indicada.
// Devuelve true si se ha podido y false si la posición no es válida.
void eliminar(tLista &lista, int pos, bool &ok); // pos = 1..N

// Localiza el registro con ese nombre.
// Devuelve la posición, o -1 si no se encuentra.
int buscar(tLista lista, string nombre);

// Carga los datos del archivo de base de datos en la lista.
void cargar(tLista &lista, bool &ok);

// Guarda los datos de la lista en el archivo de base de datos.
void guardar(tLista lista);

#endif
