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

bool swapF(tMatrizChar& mat, int f1, int f2) {
	tCoor c1;
	tCoor c2;
	c1.fila = f1;
	c2.fila = f2;
	bool ok = true;
	for (int i = 0; i < mat.cols; i++) {
		c1.columna = i;
		c2.columna = i;
		ok = swap(mat, c1, c2);
	}
	return ok;
}

bool swapC(tMatrizChar& mat, int c1, int c2) {
	tCoor f1;
	tCoor f2;
	f1.columna = c1;
	f2.columna = c2;
	bool ok = true;
	for (int i = 0; i < mat.filas; i++) {
		f1.fila = i;
		f2.fila = i;
		ok = swap(mat, f1, f2);
	}
	return ok;
}

bool voltearV(tMatrizChar& mat) {
	tCoor ini;
	tCoor fin;
	bool ok = true;
	int i = 0;
	while (i < mat.cols - i) {
		ini.columna = i;
		fin.columna = (mat.cols - 1) - i;
		for (int j = 0; j < mat.filas; j++) {
			ini.fila = j;
			fin.fila = j;
			ok = swap(mat, ini, fin);
		}
		i++;
	}
	return ok;
}

bool voltearH(tMatrizChar& mat) {
	tCoor ini;
	tCoor fin;
	bool ok = true;
	int i = 0;
	while (i < mat.filas - i) {
		ini.fila = i;
		fin.fila = (mat.filas - 1) - i;
		for (int j = 0; j < mat.cols; j++) {
			ini.columna = j;
			fin.columna = j;
			ok = swap(mat, ini, fin);
		}
		i++;
	}
	return ok;
}


bool voltearID(tMatrizChar& mat) {
	bool ok = false;
	tCoor cv;
	tCoor ch;
	if (mat.filas == mat.cols) {
		for (int i = 0; i < mat.filas; i++) {
			for (int j = 0; j < mat.cols; j++) {
				if (i < j) {
					cv.fila = i;
					cv.columna = j;
					ch.fila = j;
					ch.columna = i;
					ok = swap(mat, cv, ch);
				}
			}
		}
	}
	return ok;
}

void resolver(tMatrizChar& matriz) {
	std::string op;
	int cont;
	std::cin >> cont;
	for (int i = 0; i < cont; i++) {
		std::cin >> op;
		if (op == "VV") {
			if (!voltearV(matriz)) {
				std::cout << "DATOS INCORRECTOS" << std::endl;
			}
		}
		else if (op == "VH") {
			if (!voltearH(matriz)) {
				std::cout << "DATOS INCORRECTOS" << std::endl;
			}
		}
		else if (op == "VD") {
			if (!voltearID(matriz)) {
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