#include "ListaParques.h"
#include "ListaPicos.h"
#include "Parque.h"
#include "Visitas.h"
#include <iostream>
using namespace std;

void pausa()
{
	cout << "Pulsa enter para continuar " << endl;
	cin.sync();
	cin.clear();
	cin.get();
}


//Para leer una opcion en [inf,sup]
int leerOpcion(int inf, int sup)
{
	int i;
	cin >> i;

	while (cin.fail() || (i<inf || i>sup)) {
		cin.clear();
		cin.sync();
		cout << "Opcion incorrecta. Introduce una opcion:";
		cin >> i;
	}

	cin.sync();

	return i;

}

int mostrarMenu()
{
	system("cls");
	cout << "1. Parques" << endl;
	cout << "2. Picos" << endl;
	cout << "0. Salir" << endl;
	return leerOpcion(0, 2);

}

int mostrarMenu1()
{
	system("cls");
	cout << "1. Buceo" << endl;
	cout << "2. Nivel principiante" << endl;
	cout << "3. Mayor desnivel" << endl;
	cout << "4. 3miles" << endl;
	cout << "5. Buscar cota mas cercana" << endl;
	cout << "0. Salir" << endl;
	return leerOpcion(0, 5);

}

int mostrarMenu2()
{
	system("cls");
	cout << "1. Mostrar por nombre" << endl;
	cout << "2. Mostrar por altura" << endl;
	cout << "0. Salir" << endl;
	return leerOpcion(0, 2);

}

void ejecutarOpcion1(const tVisitas &v)
{
	int n = 0;
	int c = mostrarMenu1();
	while (c != 0)
	{
		switch (c)
		{
		case 1: {
					cout << "Introduzca el anyo: ";
					n = leerOpcion(1, v.num_filas);
					if (buceo(v, n-1)) {
						cout << "En el anyo " << n << " visitaras un parque donde podras bucear" << endl;
					}
					else cout << "En el anyo " << n << " no bucearas" << endl;
					pausa();
					break;
			}
		case 2:{
				   cout << "Introduzca la comunidad autonoma: ";
				   string comunidad; int d; tParque p;
				   getline(cin, comunidad);
				   cout << "Introduzca desnivel: ";
				   cin >> d;
				   //Supongo d>=0
				   if (nivelPrincipiante(v, comunidad, d, p)) 
					   mostrarParque(p);
				   else cout << "No hay ningun parque nivel principiante con ese desnivel en esa comunidad"<<endl;		
				   pausa();
				   break;
		}
		case 3:{   float mayor;
			int amayor = mayorDesnivel(v, mayor);
				   cout << "El mayor desnivel acumulado es de " << mayor << " metros,en el anyo " << amayor+1<<endl;
				   pausa();
				   break;
		}
		case 4:{ if (tresMiles(v))
			      cout << "Todos los parques visitados en ultimo lugar son 3miles." << endl;
			     else
				   cout << "No todos los ultimos son 3miles" << endl;
			     pausa();
				 break;
		}
		case 5:{   tListaParques ls;
			       cout << "Introduzca la comunidad autonoma: ";
				   string comunidad; float c;
				   getline(cin, comunidad);
				   listaParques(v, comunidad, ls);
				   cout << "Introduzca la cota buscada: ";
				   cin >> c; 
				   tParque p;
				   if (!esVacia(ls))
				   {
					   cout << "El parque con cota maxima mas cercana es: " << endl;
					   mostrarParque(buscar(ls,c));
				   }
				   else cout << "No hay parques en esta comunidad."<<endl;
				  // mostrar(ls);
				   pausa();
				   break;
		
		}

		}
		c = mostrarMenu1();
	}

}

void ejecutarOpcion2(const tListaPicos &ps)
{
	int c = mostrarMenu2();
	while (c != 0)
	{
		switch (c)
		{
		case 1:{ 
				   mostrarPorNombre(ps);
				   pausa();
				   break;
		}

		case 2:{
				   mostrarPorAltura(ps);
				   pausa();
				   break;	
		}

		}
		c = mostrarMenu2();
	}

}


int main()
{

	tListaPicos ps;
	tVisitas vs;
	cargar(vs);
	cargar(ps);

	int c = mostrarMenu();
	while (c != 0)
	{

		if (c == 1)
		{
			ejecutarOpcion1(vs);
		}
		else if(c==2)
		{
			ejecutarOpcion2(ps);

		}
		else
		{
			cout << "Esa opción no existe" << endl;
		}

		c = mostrarMenu();
	}

	liberar(ps);
}
