#include <iostream>
using namespace std;

void func(int n);

void func(int n) {
   if (n > 0) {
      cout << "Entrando (" << n << ")" << endl; // C?digo anterior
      func(n - 1);                              // Llamada recursiva
      cout << "Saliendo (" << n << ")" << endl; // C?digo posterior
   }
}


int main() {
   func(5);

   return 0;
}
