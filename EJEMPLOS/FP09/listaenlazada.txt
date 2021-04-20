#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include "listaenlazada.h"

void insertar(tLista &lista, tRegistro registro, bool &ok) { // por el final
   ok = true;
   tLista nuevo = new tNodo;
   if (nuevo == NULL) {
      ok = false; // No hay más memoria dinÃ¡mica
   }
   else {
      nuevo->reg = registro;
      nuevo->sig = NULL;
      if (lista == NULL) { // Lista vacía
         lista = nuevo;
      }
      else {
         tLista p = lista;
         // Localizamos el último nodo...
         while (p->sig != NULL) {
            p = p->sig;
         }
         p->sig = nuevo;
      }
   }
}

void eliminar(tLista &lista, int code, bool &ok) {
   ok = true;
   tLista p = lista;
   if (p == NULL) {
      ok = false; // Lista vacía
   }
   else if (p->reg.codigo == code) { // El primero
      lista = p->sig;
      delete p;
   }
   else {
      tLista ant = p;
      p = p->sig;
      bool encontrado = false;
      while ((p != NULL) && !encontrado) {
         if (p->reg.codigo == code) {
            encontrado = true;
         }
         else {
            ant = p;
            p = p->sig;
         }
      }
      if (!encontrado) {
         ok = false; // No existe ese código
      }
      else {
         ant->sig = p->sig;
         delete p;
      }
   }
}

tLista buscar(tLista lista, int code) {
// Devuelve un puntero al nodo, o NULL si no se encuentra
   tLista p = lista;
   bool encontrado = false;
   while ((p != NULL) && !encontrado) {
      if (p->reg.codigo == code) {
         encontrado = true;
      }
      else {
         p = p->sig;
      }
   }
   return p;
}

void mostrar(tLista lista) {
   cout << endl
        << "Elementos de la lista:" << endl
        << "----------------------" << endl;
   tLista p = lista;
   while (p != NULL) {
      mostrar(p->reg);
      p = p->sig;
   }
}

void cargar(tLista &lista, bool &ok) {
   ifstream archivo;
   char aux;
   ok = true;
   lista = NULL;
   archivo.open(BD.c_str());
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      tRegistro registro;
      tLista ult = NULL;
      archivo >> registro.codigo;
      while (registro.codigo != -1) {
         archivo >> registro.valor;
         archivo.get(aux); // Saltamos el espacio
         getline(archivo, registro.nombre);
         if (lista == NULL) {
            lista = new tNodo;
            ult = lista;
         }
         else {
            ult->sig = new tNodo;
            ult = ult->sig;
         }
         ult->reg = registro;
         ult->sig = NULL;
         archivo >> registro.codigo;
      }
      archivo.close();
   }
} 

void guardar(tLista lista) {
   ofstream archivo;
   archivo.open(BD.c_str());
   tLista p = lista;
   while (p != NULL) {
      archivo << p->reg.codigo << " ";
      archivo << p->reg.valor << " ";
      archivo << p->reg.nombre << endl;
      p = p->sig;
   }
   archivo << -1 << endl;
   archivo.close();
}

void destruir(tLista &lista) {
   tLista p;
   while (lista != NULL) {
      p = lista;
      lista = lista->sig;
      delete p;
   }
}
