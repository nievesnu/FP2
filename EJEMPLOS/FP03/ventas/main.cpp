#include <iostream>
#include <string>
using namespace std;

#include "cliente.h"
#include "producto.h"
#include "venta.h"
#include "listaclientes.h"
#include "listaproductos.h"
#include "listaventas.h"

int menu();

int main() {
   tListaClientes clientes;
   inicializar(clientes);
   cargar(clientes);
   tListaProductos productos;
   inicializar(productos);
   cargar(productos);
   tListaVentas ventas;
   inicializar(ventas);
   cargar(ventas);
   int op;
   do {
      op = menu();
      //...
   } while (op != 0);

   return 0;
}

int menu() {
   int op;
   // ...
   return op;
}
