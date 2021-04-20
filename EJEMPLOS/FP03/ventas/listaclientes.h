#ifndef listaclientes_h
#define listaclientes_h

#include <string>
using namespace std;

#include "cliente.h"

const int NCLI = 100;

typedef struct {
   tCliente clientes[NCLI];
   int cont;
} tListaClientes;

void inicializar(tListaClientes &lista);
void cargar(tListaClientes &lista);
void insertar(tListaClientes &lista, tCliente cliente, bool &ok);
void buscar(const tListaClientes &lista, string nif, tCliente &cliente, bool &ok);
void eliminar(tListaClientes &lista, string nif, bool &ok);
void mostrar(const tListaClientes &lista);

#endif
