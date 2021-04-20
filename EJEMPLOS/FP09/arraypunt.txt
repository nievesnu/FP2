#include <iostream>
using namespace std;

const int MAX = 100;
typedef int tArray[MAX];
typedef struct {
   tArray elementos;
   int cont;
} tLista;
typedef int* tIntPtr;

void inserta(tLista &lista, int dato);

int main() {
   tLista lista;
   lista.cont = 0;
   inserta(lista, 4);
   inserta(lista, 13);
   inserta(lista, 3);
   inserta(lista, 47);
   inserta(lista, 53);
   inserta(lista, 19);
   inserta(lista, 7);
   inserta(lista, 48);
   tIntPtr punt = lista.elementos;
   for (int i = 0; i < lista.cont; i++) {
      cout << *punt << endl;
      punt++;
   }

   return 0;
}

void inserta(tLista &lista, int dato) {
   if (lista.cont < MAX) {
      lista.elementos[lista.cont] = dato;
      lista.cont++;
   }
}
