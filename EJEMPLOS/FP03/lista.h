#include <string>
using namespace std;

const int N = 100;

// Estructura para los datos individuales de la lista:
typedef struct {
   int codigo;
   string nombre;
   double sueldo;
} tRegistro;

// Array de registros:
typedef tRegistro tArray[N];

// Lista: array y contador
typedef struct {
   tArray registros;
   int cont;
} tLista;

// Constante global con el nombre del archivo de base de datos:
const string BD = "bd.txt";

// Muestra en una línea la información del registro proporcionado
// precedida por su posición en la lista.
void mostrar(int pos, tRegistro registro);

// Muestra la lista completa.
void mostrar(const tLista &lista);

// Operador relacional para comparar registros.
// Basado en el campo nombre.
bool operator>(tRegistro opIzq, tRegistro opDer);

// Operador relacional para comparar registros.
// Basado en el campo nombre.
bool operator<(tRegistro opIzq, tRegistro opDer);

// Lectura de los datos de un nuevo registro.
tRegistro nuevo();

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
