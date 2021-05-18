#include <iostream>
using namespace std;

const int N = 10;
typedef int buscar[N];

void mostrarPasos(int a[]);
int busquedaBinaria(const int a[], int b, int c);
void ordenar(int a[]);
void intercambiar(int& a, int& b);

int main() {
	system("chcp 1252"); system("cls");
	buscar coso = {-15,6,3,2,7,-10,4,-6,9,1};
	cout << "Elementos sin ordenar\n";
	mostrarPasos(coso);

	//Paso 1 - Hay que ordenar el array «Coso» para que funcione la Búsqueda Binaria
	ordenar(coso); 
	cout << "Elementos ordenados\n";
	mostrarPasos(coso);

	//Paso 2 - Pedimos al usuario un valor para buscar
	int dato;
	cout << "Introduce un valor para buscar: ";
	cin >> dato;

	//Paso 3 - invocamos la función de búsqueda binaria y nos devuelve el valor
	int valor_encontrado = busquedaBinaria(coso, N, dato);
	cout << "\n\nDato encontrado en: " << valor_encontrado << " posicion";


	return 0;
}

void intercambiar(int& a, int& b){
	int tmp = b;
	b = a;
	a = tmp;
}

int busquedaBinaria(const int a[], int b, int c) {
	/*
		Pasos busqueda binaria:
			1 - Se ponen un par de índices delimitantes, uno arriba y otro abajo del array
			2 - Se pone un centro
			3 - Si el centro es el elemento buscado, pepino, en caso contrario vamos al paso 4
			4 - Si el elemento del centro es mayor, gracias a que lo hemos ordenado, miramos en la mitad adecuada
			o arriba o abajo, cambiando los índices de arriba y abajo
			5 - reasignamos los valores de arriba y abajo para buscar en el array
	
	*/
	int Iarriba = b - 1;
	int Iabajo = 0;
	int Icentro;
	int i = 1;
	while (Iabajo <= Iarriba){
		Icentro = (Iarriba + Iabajo) / 2;
		cout << "Paso " << i << " Indice superior:" << Iarriba << " Indice inferior:" << Iabajo << " Centro a comprobar:"
			<< Icentro << " Valor a buscar: " << c << " posición centro en el array: " << a[Icentro] << endl;
		if (a[Icentro] == c) {
			cout << "Como el valor a buscar " << c << " es igual al elemento que hay en la posición " << Icentro << " se dice que lo hemos encontrado";
			return Icentro;
		}
		else {
			cout << "Como el valor a buscar  " << c << " es distinto al que está en el centro, reasignamos valores\n";
			if (c < a[Icentro]) {
				cout << "Como el valor es menor que el que tenemos en el centro, cambiamos el iterador de arriba\n";
				Iarriba = Icentro - 1;
			}
			else {
				cout << "Como el valor es mayor que el que tenemos en el centro, cambiamos el iterador de abajo\n";
				Iabajo = Icentro + 1;
			}
			++i;
		}
		system("pause");
	}
	return -1;
}

void ordenar(int a[]){
	// De qué os suena esto :D ?
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			if (a[j] > a[j + 1]) intercambiar(a[j], a[j + 1]);
	// BURBUJA CHACHI
}

void mostrarPasos(int a[]) {
	for (int i = 0; i < N; i++) cout << "a[" << i << "]=" << a[i] << endl;
}



