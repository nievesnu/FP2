#include "Parque.h"
#include "checkML.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool operator<(const tParque& p1, const tParque& p2)
{
	//Define este operador
    
}


string nombre(const tParque& p)
{
	return p.nombre;
}
string comunidad(const tParque& p)
{
	return p.comunidad;
}
float cotaMax(const tParque& p)
{
	return p.cota_max;
}
float cotaMin(const tParque& p)
{
	return p.cota_min;
}

void mostrarParque(const tParque& p){

	cout << "Nombre del parque: " << p.nombre<<endl;
	cout << "Cota maxima: " << setw(4) << p.cota_max << "  Cota minima: " << setw(4) << p.cota_min<<endl;
	cout << "Desnivel: " << setw(4) << abs(p.cota_max - p.cota_min) << endl;
}

tParque parque(string nombre, string comunidad, float cotaMin, float cotaMax)
{
	tParque p;
	p.nombre = nombre;
	p.comunidad = comunidad;
	p.cota_min = cotaMin;
	p.cota_max = cotaMax;
	return p;
}

