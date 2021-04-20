#ifndef producto_h
#define producto_h

#include <string>
using namespace std;

typedef struct {
   int id_prod;
   string codigo;
   string nombre;
   double precio;
   int unidades;
} tProducto;

tProducto nuevoProducto();
bool operator<(tProducto opIzq, tProducto opDer); // Por código
void mostrar(tProducto producto);

#endif
