#include <iostream>
using namespace std;

#include "listaclientes.h"

void inicializar(tListaClientes &lista) {
   lista.cont = 0;
}

void cargar(tListaClientes &lista) {
   // ...
}

void insertar(tListaClientes &lista, tCliente cliente, bool &ok) {
   // ...
}

void buscar(const tListaClientes &lista, string nif, tCliente &cliente, bool &ok) {
   // ...
}

void eliminar(tListaClientes &lista, string nif, bool &ok) {
   // ...
}

void mostrar(const tListaClientes &lista) {
   // ...
}
