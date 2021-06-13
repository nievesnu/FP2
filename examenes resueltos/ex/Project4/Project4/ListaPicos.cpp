#include "ListaPicos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void ampliar(tListaPicos& lista) {
	// nueva capacidad
	lista.tam = lista.tam*2;
	// nuevo array din·mico
	tPico** nuevo = new tPico*[lista.tam];
	for (int i = 0; i < lista.cont; i++)
		nuevo[i] = lista.picos[i];
	// ActualizaciÛn del puntero a datos
	delete[] lista.picos;
	lista.picos = nuevo;
}

// Implementa el resto de funciones

void liberar(tListaPicos& lista)
{
	delete[] lista.picos;
	lista.picos = nullptr;
	lista.cont = 0;
	lista.max = 0;
}
