#include <iostream>
using namespace std;
#include "registrofin.h"
#include "listafin.h"

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
            cout << "Posici�n: ";
            cin >> pos;
            eliminar(lista, pos, ok);
            if (!ok) {
               cout << "Error: Posici�n inexistente!" << endl;
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
            else {
               cout << "Encontrado en la posici�n " << pos << endl;
            }
         }
      } while (op != 0);
      guardar(lista);
   }
   
   return 0;
}

int menu() {
   int op;
   cout << endl;
   cout << "1 - Insertar" << endl;
   cout << "2 - Eliminar" << endl;
   cout << "3 - Buscar" << endl;
   cout << "0 - Salir" << endl;
   do { 
      cout << "Opci�n: ";
      cin >> op;
   } while ((op < 0) || (op > 3));
   return op;
}
