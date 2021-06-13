#include "ListaParques.h"
#include <math.h>  // abs
using namespace std;

void crearVacia(tListaParques & l)
{
	l.cont = 0;
}

bool esVacia(const tListaParques & l)
{
	return l.cont == 0;
}

// Implementa el resto de funciones

