#include <iostream>
using namespace std;

#include "listaventas.h"

void inicializar(tListaVentas &lista) {
   lista.cont = 0;
}

void cargar(tListaVentas &lista) {
   // ...
}

void insertar(tListaVentas &lista, tVenta venta, bool &ok) {
   // ...
}

void buscar(const tListaVentas &lista, int id, tVenta &venta, bool &ok) {
   // ...
}

void eliminar(tListaVentas &lista, int id, bool &ok) {
   // ...
}

void ventasPorClientes(const tListaVentas &lista) {
   // ...
}

void ventasPorProductos(const tListaVentas &lista) {
   // ...
}

double totalVentas(const tListaVentas &ventas, string nif, const tListaClientes &clientes, const tListaProductos &productos) {
   double total = 0;
   // ...
   return total;
}

void stock(const tListaVentas &ventas, const tListaClientes &clientes, const tListaProductos &productos) {
   // ...
}
