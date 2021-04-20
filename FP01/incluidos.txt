#include <iostream>
using namespace std;

const int N = 3;
const int M = 10;
typedef char tVector1[N];
typedef char tVector2[M];

bool esta(char dato, const tVector2 v2);
bool vectorIncluido(const tVector1 v1, const tVector2 v2);

int main() {
   tVector1 v1 = { 'a', 'b', 'c' };
   tVector2 v2 = { 'a', 'r', 'e', 't', 'z', 's', 'a', 'h', 'b', 'x' };

   bool ok = vectorIncluido(v1, v2);

   if (ok) {
      cout << "OK: v1 esta incluido en v2" << endl;
   }
   else {
      cout << "NO: v1 no esta incluido en v2" << endl;
   }

   return 0;
}

bool esta(char dato, const tVector2 v2) {
   int i = 0;
   bool encontrado = (dato == v2[0]);
   while (!encontrado && (i < M - 1)) {
      i++;
      encontrado = (dato == v2[i]);
   }
   return encontrado;
}

bool vectorIncluido(const tVector1 v1, const tVector2 v2) {
   int i = 0;
   bool encontrado = esta(v1[0], v2);
   while(encontrado && (i < N - 1)) {
      i++;
      encontrado = esta(v1[i], v2);
   }
   return encontrado;
}
