#include "registro.h"

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

// Inserci?n del registro proporcionado en la lista.
// Devuelve true si se ha podido y false si la lista est? llena.
void insertar(tLista &lista, tRegistro registro, bool &ok);

// Eliminaci?n del registro en la posici?n indicada.
// Devuelve true si se ha podido y false si la posici?n no es v?lida.
void eliminar(tLista &lista, int pos, bool &ok); // pos = 1..N

// Localiza el registro con ese nombre.
// Devuelve la posici?n, o -1 si no se encuentra.
int buscar(tLista lista, string nombre);

// Muestra la lista completa.
void mostrar(const tLista &lista);

// Carga los datos del archivo de base de datos en la lista.
void cargar(tLista &lista, bool &ok);

// Guarda los datos de la lista en el archivo de base de datos.
void guardar(tLista lista);
