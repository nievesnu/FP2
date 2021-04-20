#include <iostream>
using namespace std;

#include "producto.h"

bool valida(tProducto producto); // Función interna

tProducto nuevoProducto() {
   tProducto producto;
   // ...
   return producto;
}

bool valida(tProducto producto) {
   //...
   return true;
}

bool operator<(tProducto opIzq, tProducto opDer) {
   return opIzq.codigo < opDer.codigo;
}

void mostrar(tProducto producto) {
   // ...
}
