#ifndef listaproductos_h
#define listaproductos_h

#include <string>
using namespace std;

#include "producto.h"

const int NPROD = 200;

typedef struct {
   tProducto productos[NPROD];
   int cont;
} tListaProductos;

void inicializar(tListaProductos &lista);
void cargar(tListaProductos &lista);
void insertar(tListaProductos &lista, tProducto producto, bool &ok);
void buscar(const tListaProductos &lista, string codigo, tProducto &producto, bool &ok);
void eliminar(tListaProductos &lista, string codigo, bool &ok);
void mostrar(const tListaProductos &lista);

#endif
