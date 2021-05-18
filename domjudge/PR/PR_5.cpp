//Autor/a: Nieves Nuñez Ugena y Rodrigo Sosa Saez
// email: nievesnu@ucm.es
// Compilador y S.O. utilizado: visual studio 2019
// Nombre del problema: PR1
// Comentario general sobre la solución

#include <iostream>
#include <string>
#include <fstream>

typedef struct {
	int fila;
	int columna;
}tCoor;

const int incF[] = { 1,1,0,-1,-1,-1,0,1 };  //sirven para elegir las celdas
const int incC[] = { 0,1,1,1,0,-1,-1,-1 };   //que estan contiguas a la elegida

const int DIM_MAX = 64;

typedef unsigned char uint8;

typedef struct {
	int filas;                      //numero de filas
	int cols;                       //numero de columnas
	uint8 matriz[DIM_MAX][DIM_MAX]; //valor de cada celda
}tMatrizChar;

uint8 matriz[DIM_MAX][DIM_MAX]; //valor de cada celda

void mostrar(tMatrizChar mat) {
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.cols; j++) {
			std::cout << mat.matriz[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool cargar(tMatrizChar& mat, std::istream& ent) {
	bool cargado = true;
	ent >> mat.filas;
	ent >> mat.cols;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.cols; j++) {
			ent >> mat.matriz[i][j];
		}
	}
	return cargado;
}

void rotarD(tMatrizChar& mat) {
	tMatrizChar aux;
	aux.filas = mat.cols;
	aux.cols = mat.filas;

	for (int i = 0; i < aux.filas; i++) {
		for (int j = 0; j < aux.cols; j++) {
			aux.matriz[i][(aux.cols - 1) - j] = mat.matriz[j][i];
		}
	}
	mat = aux;
}

void resolver(tMatrizChar& matriz) {
	std::string op;
	int cont, n;
	std::cin >> cont;
	for (int i = 0; i < cont; i++) {
		std::cin >> op;
		if (op == "RD") {
			std::cin >> n;
			rotarD(matriz);
		}
	}
}

void resuelveCaso() {
	tMatrizChar m;
	// leer los datos de la entrada
	if (cargar(m, std::cin)) {
		resolver(m);
		mostrar(m);
	}
	std::cout << "---" << std::endl;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif
	return 0;
}