#include <iostream>
#include <cstdlib>
#include <cstdint>

using namespace std;

int const MAX = 50;

const int incF[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int incC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef struct 
{
	int filas;
	int col;
	int matriz[MAX][MAX];

}tMatriz;

void suman21(const tMatriz& matriz);
void mayor_cruz(const tMatriz& matriz);
bool dentro_matriz(tMatriz m, int x, int y);

//posición valida de la matriz

void suman21(const tMatriz& matriz) {
	int suma = 0;
	bool  es = false;
	for (int i = 0; i < matriz.filas; i++)
	{
		for (int j = 0; j < matriz.col; j++)
		{
			suma = 0;
			for (int dir = 0; dir < 8; dir++) {
				if (dentro_matriz(matriz, i + incF[dir], j + incC[dir])) {
					suma += matriz.matriz[i + incF[dir]][j + incC[dir]];
				}
			}
			if (suma == 21)
			{
				cout << "(" << i << "," << j << ")" << endl;
				es = true;
			}
			//cout << endl;
		}

	}
	if (!es)
	{
		cout << "NO" << endl;
	}
	
}

bool dentro_matriz(tMatriz m, int x, int y) {
	if (x >= 0 && x < m.filas && y >= 0 && y < m.col) {
		return true;
	}
	else {
		return false;
	}
}

int sumar(tMatriz matriz, int fila, int col) {
	int suma1 = 0;
	int suma2 = 0;
	int total = 0;
	for (int i = 0; i < matriz.filas; i++)
	{
		suma1 += matriz.matriz[i][col]; //9
	}
	for (int j = 0; j < matriz.col; j++)
	{
		suma2 += matriz.matriz[fila][j]; //12
	}
	suma1 -= matriz.matriz[fila][col];
	//suma2 -= matriz.matriz[fila][col];
	total = suma1 + suma2;
	return total;
}

void mayor_cruz(const tMatriz& matriz) {
	int aux=0;
	tMatriz valores;
	int maxElemento = matriz.matriz[0][0];
	int posFilaMax = 0;
	int posColumnaMax = 0;
	for (int i = 0; i < matriz.filas; i++)
	{
		for (int j = 0; j < matriz.col; j++)
		{
			aux = sumar(matriz, i, j);
			//aux = aux - 2* (matriz, i, j);
			valores.matriz[i][j] = aux;
			

			if (valores.matriz[i][j] > maxElemento) {
				maxElemento = valores.matriz[i][j];
				posFilaMax = i;
				posColumnaMax = j;
			}
		}
	}
	cout << maxElemento << " (" << posFilaMax << "," << posColumnaMax << ")" << endl;
}

int main() {
	tMatriz m;
	//suman21(m);
	m.matriz[0][0] = 1;
	m.matriz[0][1] = 2;
	m.matriz[1][0] = 3;
	m.matriz[1][1] = 4;
	m.matriz[2][0] = 5;
	m.matriz[2][1] = 6;
	m.filas = 3;
	m.col = 2;
	suman21(m);
	mayor_cruz(m);
}