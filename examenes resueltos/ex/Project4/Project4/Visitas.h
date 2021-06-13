#ifndef _visitas
#define _visitas
#include<string>
#include "Parque.h"
#include "ListaParques.h"
using namespace std;

const int MAX = 20;

typedef struct{
	tParque visitas[MAX][MAX];
	int num_filas;
	int num_columnas;
}tVisitas;


bool cargar(tVisitas & v);
//Resto de funciones solicitadas
bool buceo(int n, tVisitas& v);
int nivelPrincipiante(int d, tVisitas& v);
bool tresMiles(tVisitas v);
int listaParques(tVisitas& v, string comunidad, tListaParques lista);

#endif
