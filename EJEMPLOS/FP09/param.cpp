#include <iostream>
using namespace std;

void incrementa(int *punt);

void incrementa(int *punt) {
   (*punt)++;
}

int main() {
   int entero = 5;
   incrementa(&entero);
   cout << entero << endl;

   return 0;
}