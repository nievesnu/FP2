#ifndef venta_h
#define venta_h

#include "listaclientes.h"
#include "listaproductos.h"

typedef struct {
   int id;
   int id_prod;
   int id_cli;
   int unidades;
} tVenta;

tVenta nuevaVenta(int id_prod, int id_cli, int unidades);
void mostrar(tVenta venta, const tListaClientes &clientes, const tListaProductos &productos);

#endif
