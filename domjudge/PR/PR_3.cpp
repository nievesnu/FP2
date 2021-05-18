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

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool ok = (pos1.fila < mat.filas) && (pos1.fila > -1) && (pos1.columna < mat.cols) && (pos1.columna > -1) && (pos2.fila < mat.filas) && (pos2.fila > -1) && (pos2.columna < mat.cols) && (pos2.columna > -1);
	uint8 aux;
	if (ok) {
		aux = mat.matriz[pos1.fila][pos1.columna];
		mat.matriz[pos1.fila][pos1.columna] = mat.matriz[pos2.fila][pos2.columna];
		mat.matriz[pos2.fila][pos2.columna] = aux;
	}
	return ok;
}

bool swapD(tMatrizChar& mat, int d) {
	tCoor dplus;
	tCoor dminus;
	bool ok = false;
	if (mat.filas == mat.cols) {
		int i = 0;
		while (i + abs(d) < mat.filas) {
			if (d < 0) {
				dminus.fila = i;
				dminus.columna = abs(d) + i;
				dplus.fila = abs(d) + i;
				dplus.columna = i;
			}
			else {
				dplus.fila = i;
				dplus.columna = d + i;
				dminus.fila = d + i;
				dminus.columna = i;
			}
			ok = swap(mat, dplus, dminus);
			i++;
		}
	}
	else {
		ok = false;
	}
	return ok;
}

bool voltearD(tMatrizChar& mat, int d) {
	tCoor ini;
	tCoor fin;
	bool ok = true;
	int i = 0;
	if (mat.filas == mat.cols) {
		if (d >= 0 && d < mat.filas) {
			while (d + i <= mat.filas - d - i) {
				ini.fila = i;
				ini.columna = d + i;
				fin.fila = (mat.filas - 1) - d - i;
				fin.columna = (mat.cols - 1) - i;
				ok = swap(mat, ini, fin);
				i++;
			}
		}
		else if (d < 0 && abs(d) < mat.filas) {
			while (abs(d) + i <= mat.filas - abs(d) - i) {
				ini.fila = abs(d) + i;
				ini.columna = i;
				fin.fila = (mat.filas - 1) - i;
				fin.columna = (mat.cols - 1) - abs(d) - i;
				ok = swap(mat, ini, fin);
				i++;
			}
		}
		else {
			ok = false;
		}
	}
	else {
		ok = false;
	}
	return ok;
}

void resolver(tMatrizChar& matriz) {
	std::string op;
	int cont, n;
	std::cin >> cont;
	for (int i = 0; i < cont; i++) {
		std::cin >> op;
		if (op == "SD") {
			std::cin >> n;
			if (!swapD(matriz, n)) {
				std::cout << "DATOS INCORRECTOS" << std::endl;
			}
		}
		else if (op == "VD") {
			std::cin >> n;
			if (!voltearD(matriz, n)) {
				std::cout << "DATOS INCORRECTOS" << std::endl;
			}
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