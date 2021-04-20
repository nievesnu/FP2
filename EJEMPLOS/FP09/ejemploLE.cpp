#include <iostream>
using namespace std;
#include "registro.h"
#include "listaenlazada.h"

int main() {
   tLista lista = NULL;
   bool ok;
   cargar(lista, ok);
   if (ok) {
      mostrar(lista);
      destruir(lista);
   }
   
   return 0;
}

