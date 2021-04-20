#include <iostream>
using namespace std;
#include <stdlib.h>

const int N = 10;
typedef int tVector[N];

//Prototipos

// Desplazamiento a la derecha de todos los elementos del vector
void desplazar(tVector v);

// Suma los elementos del vector en posiciones pares
int sumaPares(const tVector v);

// Identifica la posición del elemento mayor del vector
int encuentraMayor(const tVector v);

// Comprueba si dos vectores son iguales
bool sonIguales(const tVector v1, const tVector v2);  

// Comprueba si algún valor es igual a la suma del resto
// Devuelve el índice del primero encontrado o -1 si no se encuentra
int compruebaSuma(const tVector v);  

// Comprueba si algún valor está repetido
bool hayRepetidos(const tVector v); 

void mostrar(const tVector v);

// Programa principal
int main() {
   tVector v, v2;
   int prueba = 0, indice;
    
   for (int i = 0; i<N; i++) {
      v[i] = rand() % 10;
   }
      
   cout << "Vector original: ";
   mostrar(v);

   desplazar(v);
   cout << "Vector con  los elementos desplazados: ";
   mostrar(v);
   
   prueba = sumaPares(v);
   cout << "Suma de los pares: " << prueba << endl;

   indice = encuentraMayor(v);
   cout << "Índice del mayor: " << indice << endl;

   for (int i = 0; i < N; i++)
      v2[i] = v[i];
   // v[7] = 11;
   if (sonIguales(v, v2)) 
      cout << "Son iguales." << endl;
   else
      cout << "Hay alguna diferencia." << endl;
   
   indice = compruebaSuma(v);
   if (indice != -1) 
      cout << "Encontrado en el índice " << indice << "!" << endl;
   else
      cout << "No encontrado!" << endl;
    
   // v[8] = v[3];
   if (hayRepetidos(v)) 
      cout << "Hay repetidos!" << endl;
   else
      cout << "No hay repetidos." << endl;
    
   return 0;
}

void mostrar(const tVector v) {
   for (int i = 0; i < N; i++)
      cout << v[i] << " ";
   cout << endl;
}

bool hayRepetidos(const tVector v) {
   bool encontrado = false;
   int i = 0, j;
   while ((i < N) && !encontrado) {
      j = i + 1;
      while ((j < N) && !encontrado) {
         encontrado = (v[i] == v[j]);
         j++;
      }
      i++;
   }
   return encontrado;
}

int compruebaSuma(const tVector v) {
// ¿Alguno igual a la suma del resto?
   bool encontrado = false;
   int i = 0;
   int suma;
   while ((i < N) && !encontrado) {
      suma = 0;
      for (int j = 0; j < N; j++) {
         if (j != i) {
             suma = suma + v[j];
         }
      }
      encontrado = (suma == v[i]);
      i++;
   }
   if (!encontrado) {
      i = 0;
   }
   return i - 1;
}

bool sonIguales(const tVector v1, const tVector v2) {
   // Implementación como búsqueda del primer elemento distinto
   bool encontrado = false;
   int i = 0;
   while ((i<N) && !encontrado) {
      encontrado = (v1[i] != v2[i]);
      i++;
   }
   return !encontrado;
} 

int encuentraMayor(const tVector v) {
   int max = v[0], posMayor = 0;
   for (int i = 1; i < N; i++) {
      if (v[i] > max) {
         posMayor = i;
         max = v[i];
      }
   }
   return posMayor;
}

int sumaPares(const tVector v) {
   int suma = 0;
   for (int i = 0; i < N; i = i + 2) {
      suma = suma + v[i];
   }
   return suma;
}

void desplazar(tVector v) {
   int aux = v[N - 1];
   for (int i = N - 1; i > 0; i--) {
      v[i] = v[i - 1];     
   }
   v[0] = aux;
}
