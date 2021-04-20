#ifndef registrofin_h
#define registrofin_h

#include <string>
using namespace std;

// Estructura para los datos de cada registro:
typedef struct {
   int codigo;
   string nombre;
   double sueldo;
} tRegistro;

// Lectura de los datos de un nuevo registro.
tRegistro nuevo();

// Operador relacional para comparar registros.
// Basado en el campo nombre.
bool operator>(tRegistro opIzq, tRegistro opDer);

// Operador relacional para comparar registros.
// Basado en el campo nombre.
bool operator<(tRegistro opIzq, tRegistro opDer);

// Muestra en una línea la información del registro proporcionado
// precedida por su posición en la lista.
void mostrar(int pos, tRegistro registro);

#endif
