#ifndef _listaParques
#define _listaParques
#include<string>
#include "Parque.h"
using namespace std;

const int MAX_PARQUES = 400;

// Define la estructura
typedef struct 
{
	tParque arrayParques[MAX_PARQUES];
	int cont;
}tListaParques;

//tListaParques* tListado[MAX_PARQUES];
//Prototipos

void crearVacia(tListaParques& lista);
bool esVacía(tListaParques& lista);
void insertar(tListaParques& lista, tParque & parque);
bool buscar(tListaParques& lista, int c);
void mostrat(tListaParques& lista);

#endif
