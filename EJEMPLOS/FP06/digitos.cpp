#include <iostream>
using namespace std;
#include <cstdlib> // srand() y rand()
#include <ctime> // time()

int digitos(int dato);

int main() {
   const int NUM = 100;
   typedef int tNum[NUM]; // Exactamente 100 n�meros
   const int DIG = 5;
   typedef int tDig[DIG]; // Posici�n i --> cantidad de n�meros de i+1 d�gitos
   tNum numeros;
   tDig numDig = { 0 };
   
   srand(time(NULL)); // Inicializa el generador de n�meros aleatorios
   
   for (int i = 0; i < NUM; i++) { // Creamos la secuencia de enteros
      numeros[i] = rand(); // Entre 0 y 32766
   }
   
   for (int i = 0; i < NUM; i++) { // Recorremos la secuencia de enteros
      numDig[digitos(numeros[i]) - 1]++;
   }
  
   for (int i = 0; i < DIG; i++) { // Recorremos la secuencia de contadores
      cout << "De " << i + 1 << " dig. = " << numDig[i] << endl;
   }
   
   return 0;
}

int digitos(int dato) {
// dato seguro que tiene entre 1 y 5 d�gitos
   int n_digitos = 1; // Al menos tiene un d�gito
   
   // Recorremos la secuencia de d�gitos...
   while (dato >= 10) {
      dato = dato / 10;
      n_digitos++;
   }
   
   return n_digitos;
}
