#ifndef _listaPicos
#define _listaPicos
#include<string>
#include "Parque.h"
using namespace std;


// Define la estructura

typedef struct 
{
	string nombre;
	int altura;
	tParque* nombre;

}tPico;

typedef tPico * tPicos;

typedef struct 
{
	tPicos picos;
	int cont;
	int max;
}tListaPicos;

//Prototipos
void cargar(tListaPicos& lista);
void mostarPorNombre(tPico pico);
void mostarPorAltura(tPico pico);
void liberar(tListaPicos& lista);
#endif
