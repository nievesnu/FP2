#ifndef _parque
#define _parque
#include<string>
using namespace std;
typedef struct
{
	string nombre;
	string comunidad;
	float cota_max, cota_min;
} tParque;

bool operator<(const tParque& p1, const tParque& p2);
string nombre(const tParque& p);
string comunidad(const tParque& p);
float cotaMax(const tParque& p);
float cotaMin(const tParque& p);
void mostrarParque(const tParque& p);
tParque parque(string nombre, string comunidad, float cotaMin, float cotaMax);

#endif