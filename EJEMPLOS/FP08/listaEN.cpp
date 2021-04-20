#include <iostream>
using namespace std;
#include <fstream>
#include "listaEN.h"

// IMPLEMENTACIÓN DE LOS SUBPROGRAMAS COMUNES

void eliminar(tLista &lista, int pos, bool &ok) { // pos = 1..
   ok = true;
   if ((pos < 1) || (pos > lista.cont)) {
      ok = false; // Posición inexistente
   }
   else {
      pos--; // Pasamos a índice del array
      for (int i = pos + 1; i < lista.cont; i++) { // Desplazamos a la izquierda
         lista.registros[i - 1] = lista.registros[i];
      }
      lista.cont--;
   }
}

void mostrar(const tLista &lista) {
   for (int i = 0; i < lista.cont; i++) {
      mostrar(i + 1, lista.registros[i]);
   }
}

// IMPLEMENTACIÓN DE LOS SUBPROGRAMAS DEL ESPACIO DE NOMBRES ord

void ord::insertar(tLista &lista, tRegistro registro, bool &ok) {
   ok = true;
   if (lista.cont == N) {
      ok = false; // Lista llena
   }
   else {
      int i = 0;
      while ((i < lista.cont) && (lista.registros[i] < registro)) {
         i++;
      }
      // Insertamos en la posición i
      for (int j = lista.cont; j > i; j--) { // Desplazamos a la derecha
         lista.registros[j] = lista.registros[j - 1];
      }
      lista.registros[i] = registro;
      lista.cont++;
   }
}

int ord::buscar(tLista lista, string nombre) {
// Devuelve -1 si no se ha encontrado
   int ini = 0, fin = lista.cont - 1, mitad;
   bool encontrado = false;
   
   while ((ini <= fin) && !encontrado) {
      mitad = (ini + fin) / 2;
      if (nombre == lista.registros[mitad].nombre) {
         encontrado = true;
      }
      else if (nombre < lista.registros[mitad].nombre) {
         fin = mitad - 1;
      }
      else {
         ini = mitad + 1;
      }
   }
   if (encontrado) {
      mitad++; // Pasamos a posición de usuario
   }
   else {
      mitad = -1;
   }
   
   return mitad;
}

void ord::cargar(tLista &lista, bool &ok) {
   ok = true;
   ifstream archivo;
   lista.cont = 0;
   archivo.open(BD.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tRegistro reg;
      archivo >> reg.codigo;
      while ((lista.cont < N) && (reg.codigo != -1)) {
         archivo >> reg.nombre;
         archivo >> reg.sueldo;
         lista.registros[lista.cont] = reg;
         lista.cont++;
         archivo >> reg.codigo;
      }
      archivo.close();
   }
} 

void ord::guardar(tLista lista) {
   ofstream salida;
   salida.open(BD.c_str());
   for (int i = 0; i < lista.cont; i++) {
      salida << lista.registros[i].codigo << " "
             << lista.registros[i].nombre << " "
             << lista.registros[i].sueldo << endl;
   }
   salida << -1 << endl;
   salida.close();
}

// IMPLEMENTACIÓN DE LOS SUBPROGRAMAS DEL ESPACIO DE NOMBRES des

void des::insertar(tLista &lista, tRegistro registro, bool &ok) {
   ok = true;
   if (lista.cont == N) {
      ok = false; // Lista llena
   }
   else {
      lista.registros[lista.cont] = registro;
      lista.cont++;
   }
}

int des::buscar(tLista lista, string nombre) {
// Devuelve -1 si no se ha encontrado
   int pos = 0;
   bool encontrado = false;
   
   while ((pos < lista.cont) && !encontrado) {
      if (nombre == lista.registros[pos].nombre) {
         encontrado = true;
      }
      else {
         pos++;
      }
   }
   if (encontrado) {
      pos++; // Pasamos a posición de usuario
   }
   else {
      pos = -1;
   }
   
   return pos;
}

void des::cargar(tLista &lista, bool &ok) {
   ok = true;
   ifstream archivo;
   lista.cont = 0;
   archivo.open(BD.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tRegistro reg;
      archivo >> reg.codigo;
      while ((lista.cont < N) && (reg.codigo != -1)) {
         archivo >> reg.nombre;
         archivo >> reg.sueldo;
         lista.registros[lista.cont] = reg;
         lista.cont++;
         archivo >> reg.codigo;
      }
      archivo.close();
   }
} 

void des::guardar(tLista lista) {
   ofstream salida;
   salida.open(BD.c_str());
   for (int i = 0; i < lista.cont; i++) {
      salida << lista.registros[i].codigo << " "
             << lista.registros[i].nombre << " "
             << lista.registros[i].sueldo << endl;
   }
   salida << -1 << endl;
   salida.close();
}
