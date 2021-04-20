#ifndef cliente_h
#define cliente_h

#include <string>
using namespace std;

typedef struct {
   int id_cli;
   string nif;
   string nombre;
   string telefono;
} tCliente;

tCliente nuevoCliente();
bool operator<(tCliente opIzq, tCliente opDer); // Por NIF
void mostrar(tCliente cliente);

#endif
