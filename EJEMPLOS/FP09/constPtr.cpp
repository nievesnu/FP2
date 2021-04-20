#include <iostream>
using namespace std;

int main() {
   typedef const int *intCtePtr; // Puntero a dato constante
   typedef int *const intPtrCte; // Puntero constante
   int entero1 = 5, entero2 = 13;
   intCtePtr punt_a_cte = &entero1;
   intPtrCte punt_cte = &entero1;
   cout << *punt_a_cte << "   " << *punt_cte << endl;
   // (*punt_a_cte)++; // ERROR: ¡Dato constante no modificable!
   punt_a_cte = &entero2; // Sin problema: el puntero no es cte.
   (*punt_cte)++; // Sin problema: el puntero no apunta a cte.
   // punt_cte = &entero2; // ERROR: ¡Puntero constante!
   cout << *punt_a_cte << "   " << *punt_cte << endl;

   return 0;
}