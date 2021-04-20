#ifndef listaEN_h
#define listaEN_h

#include "registrofin.h"

const int N = 100;

typedef tRegistro tArray[N];
typedef struct {
   tArray registros;
   int cont;
} tLista;

void mostrar(const tLista &lista);
void eliminar(tLista &lista, int pos, bool &ok); // pos = 1..N

namespace ord { // Lista ordenada
   const string BD = "bd.txt";
   void insertar(tLista &lista, tRegistro registro, bool &ok);
   int buscar(tLista lista, string nombre);
   void cargar(tLista &lista, bool &ok);
   void guardar(tLista lista);
} // namespace

namespace des { // Lista desordenada
   const string BD = "bddes.txt";
   void insertar(tLista &lista, tRegistro registro, bool &ok);
   int buscar(tLista lista, string nombre);
   void cargar(tLista &lista, bool &ok);
   void guardar(tLista lista);
} // namespace

#endif
