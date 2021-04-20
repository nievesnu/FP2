#include<iostream> 
#include<fstream> 
#include<string> 
using namespace std;

const int NF = 5;
const int NC = 10;
typedef int tMatriz[NF][NC];

const int M = 30;

bool cargarMatriz(tMatriz m, string fileName);
void mostrarMatriz(tMatriz m);

//AÑADE AQUÍ EL PROTOTIPO DE TUS FUNCIONES
bool atractivo(tMatriz m, int h);
int maletin(tMatriz m);

int main() {
	system("cls");
	int h=0;

	tMatriz m;
	if (!(cargarMatriz(m, "matriz1.txt"))) {
		cout << "ERROR al cargar la matriz" << endl;
	}
	else {

		mostrarMatriz(m);
		atractivo(m, h);
		

		if (!atractivo(m, h)) {
			cout << "Es atractivo" << endl;
		}
		else
		{
			cout << "no es atractivo" << endl;
		}
		cout << "Numero de maletines poco atractivos" << maletin(m);
		
	}
	cout << endl << "Pulsa Intro para terminar:";
	system("pause");
	return 0;
}

bool cargarMatriz(tMatriz m, string fileName) {
	bool ok = false;
	string s;
	ifstream iFile;
	iFile.open(fileName);
	if (iFile.is_open()) {
		ok = true;
		for (int f = 0; f < NF; f++) {
			for (int c = 0; c < NC; c++) {
				iFile >> m[f][c];
			}
			getline(iFile, s);
		}
	}
	iFile.close();
	return ok;
}

void mostrarMatriz(tMatriz m) {
	cout << "MATRIZ" << endl;
	for (int f = 0; f < NF; f++) {
		for (int c = 0; c < NC; c++) {
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//AÑADE AQUÍ LA IMPLEMENTACIÓN DE TUS FUNCIONES

bool atractivo(tMatriz m, int h)
{
	int ciclos = 0; //entero para contar el nº de ciclos hasta encontrar los atractivos
	bool atractivo;
	for (int i = 0; i < NC; i++) //recorrido por columnas
	{
		ciclos = ciclos + m[h][i]; //sumamos
	}
	if (ciclos > M) // si el nº de veces usudao es menor que la const M poco atractivo, y mayor a M atractivo
	{
		atractivo = true;
	}
	else
	{
		atractivo = false;
	}
	return atractivo;
}

int maletin(tMatriz m)
{
	int ciclos = 0; //entero para contar el nº de ciclos

	for (int i = 0; i < NF; i++) //recorremoslas filas
	{
		if (!atractivo(m, i)) //para buscar la i (que es el maletin) en la que menos veces se ha cogido utilizando la funcion atractivo, 
			//la negamos porque la función busca el más atractivo y queremos el menos atractivo
		{
			ciclos++;
		}
	}
	return ciclos;
}
