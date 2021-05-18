#include <iostream>
using namespace std;

typedef struct {
	int dia = 24;
	int mes = 12;
	int anyo = 2014;
}tFecha;

bool operator>(tFecha izq, tFecha der);

int main() {
	tFecha fechaIzq, fechaDer;
	system("chcp 1252"); system("cls");
	cout << "-Bienvenido al sistema de reimplementación 101-\n\n";
	while (true) {
		cout << "Vas a introducir una fecha y la compararemos con el 24 de diciembre de 2014 para ver si es mayor o no";
		cout << "\nIntroduce Día: ";
		cin >> fechaDer.dia;
		cout << "\nIntroduce Mes: ";
		cin >> fechaDer.mes;
		cout << "\nIntroduce Año: ";
		cin >> fechaDer.anyo;
		cout << "Ahora ejecutaremos la comparación sobrecargada (mirar el código fuente)\n\n";
		if (fechaIzq > fechaDer) cout << "La fecha de 24 de diciembre de 2014 es mayor que la tuya\n";
		else cout << "Enorabuena, tu fecha es mayor\n"; 
		system("pause");
		system("cls");
	}
	return 0;
}

bool operator>(tFecha izq, tFecha der) {
	bool mayor = false;
	if(izq.anyo > der.anyo || // Si el año de la izquierda es mayor
		(izq.anyo == der.anyo && (izq.mes > der.mes) || // Si es igual, miramos si el mes es mayor
		(izq.anyo == der.anyo && izq.mes == der.mes && (izq.dia > der.dia)))) // Si ambos son iguales, miramos si el dia es mayor
	mayor = true;
	return mayor;
}