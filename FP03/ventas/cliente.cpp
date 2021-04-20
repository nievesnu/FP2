#include <iostream>
using namespace std;

#include "cliente.h"

bool valida(tCliente cliente); // Función interna

tCliente nuevoCliente() {
   tCliente cliente;
   // ...
   return cliente;   
}

bool valida(tCliente cliente) {
   //...
   return true;
}

bool operator<(tCliente opIzq, tCliente opDer) {
   return opIzq.nif < opDer.nif;
}

void mostrar(tCliente cliente) {
   // ...
}
