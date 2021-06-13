#include <iostream>
#include <string>

using namespace std;

typedef enum { chasis, motor}tAveria;
typedef enum {no, repa, fin}tReparacion;

int const MAX_SECCION = 3;

typedef struct {
	string matricula;
	tAveria averia;
	tReparacion repara;
}tCoche;

typedef struct {
	tCoche* arrayPunt;
	int cont;
}tListaCoches;

typedef struct {
	tCoche* seccion[MAX_SECCION];
	int cont;
}tListaSeccion;

int main() {
	tAveria a;
	//tCoche coche;
	//tListaCoches lista;
	//tListaSeccion seccion;
	a = 0;
	cout << a << endl;
}