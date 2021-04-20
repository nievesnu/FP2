#include <iostream>
using namespace std;
#include "registrofin.h"
#include "listaEN.h"
using namespace des;

int menu();

int main() {
   tLista lista;
   bool ok;
   int op, pos;
   
   cargar(lista, ok);
   if (!ok) {
      cout << "No se pudo abrir el archivo!" << endl;
   }
   else {
      do {
         mostrar(lista);
         op = menu();
         if (op == 1) {
            tRegistro registro = nuevo();
            insertar(lista, registro, ok);
            if (!ok) {
               cout << "Error: Lista llena!" << endl;
            }
         }
         else if (op == 2) {
            cout << "PosiciÃ³n: ";
            cin >> pos;
            eliminar(lista, pos, ok);
            if (!ok) {
               cout << "Error: Posición inexistente!" << endl;
            }
         }
         else if (op == 3) {
            string nombre;
            cin.sync();
            cout << "Nombre: ";
            cin >> nombre;
            pos = buscar(lista, nombre);
            if (pos == -1) {
               cout << "No se ha encontrado!" << endl;
            }
            else  {
               cout << "Encontrado en la posición " << pos << endl;
            }
         }
      } while (op != 0);
      guardar(lista);
   }
   
   return 0;
}

int menu() {
   cout << endl;
   cout << "1 - Insertar" << endl;
   cout << "2 - Eliminar" << endl;
   cout << "3 - Buscar" << endl;
   cout << "0 - Salir" << endl;
   int op;
   do { 
      cout << "Opción: ";
      cin >> op;
   } while ((op < 0) || (op > 3));
   return op;
}
