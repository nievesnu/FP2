#ifndef listaventas_h
#define listaventas_h

#include <string>
using namespace std;

#include "venta.h"
#include "listaclientes.h"
#include "listaproductos.h"

const int NVENTAS = 3000;

typedef struct {
   tVenta ventas[NVENTAS];
   int cont;
} tListaVentas;

void inicializar(tListaVentas &lista);
void cargar(tListaVentas &lista);
void insertar(tListaVentas &lista, tVenta venta, bool &ok);
void buscar(const tListaVentas &lista, int id, tVenta &venta, bool &ok);
void eliminar(tListaVentas &lista, int id, bool &ok);
void ventasPorClientes(const tListaVentas &lista);
void ventasPorProductos(const tListaVentas &lista);
double totalVentas(const tListaVentas &ventas, string nif, const tListaClientes &clientes, const tListaProductos &productos);
void stock(const tListaVentas &ventas, const tListaClientes &clientes, const tListaProductos &productos);

#endif
