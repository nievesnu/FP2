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

bool operator==(tCoor c1, tCoor c2) {
	bool eq = false;
	if ((c1.fila == c2.fila) && (c1.columna == c2.columna)) {
		eq = true;
	}
	return eq;
}

bool operator!=(tCoor c1, tCoor c2) {
	bool dif = true;
	if ((c1.fila == c2.fila) && (c1.columna == c2.fila)) {
		dif = false;
	}
	return dif;
}

tCoor operator + (tCoor c1, tCoor c2) {
	tCoor suma;
	suma.fila = c1.fila + c2.fila;
	suma.columna = c1.columna + c2.columna;
	return suma;
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

bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool ok = true;
	tCoor aux;
	tCoor aux2;
	tCoor resul1;
	tCoor resul2;
	for (int i = 0; i < 8; i++) {
		aux.fila = incF[i];
		aux.columna = incC[i];
		resul1 = operator+(pos1, aux);
		if (resul1.fila < 0 || resul1.columna < 0 || resul1.fila >= mat.filas || resul1.columna >= mat.cols) {
			ok = false;
		}
		else {
			for (int j = 0; j < 8; j++) {
				aux2.fila = incF[j];
				aux2.columna = incC[j];
				resul2 = operator+(pos2, aux2);
				if (resul2.fila < 0 || resul2.columna < 0 || resul2.fila >= mat.filas || resul2.columna >= mat.cols) {
					ok = false;
				}
				else if (operator==(resul1, resul2)) {
					ok = false;
				}
			}
		}
	}
	if (ok) {
		for (int a = 0; a < 8; a++) {
			aux.fila = incF[a];
			aux.columna = incC[a];
			resul1 = operator+(pos1, aux);
			resul2 = operator+(pos2, aux);
			ok = swap(mat, resul1, resul2);
		}
	}
	return ok;
}

void resolver(tMatrizChar& matriz) {
	std::string op;
	int cont;
	tCoor pos1, pos2;
	std::cin >> cont;
	for (int i = 0; i < cont; i++) {
		std::cin >> op;
		if (op == "SA") {
			std::cin >> pos1.fila;
			std::cin >> pos1.columna;
			std::cin >> pos2.fila;
			std::cin >> pos2.columna;
			if (!swapAdy(matriz, pos1, pos2)) {
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