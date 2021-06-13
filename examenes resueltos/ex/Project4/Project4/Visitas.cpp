#include<string>
#include<iostream>
#include<fstream>
#include <Math.h>
#include "Visitas.h"
#include "Parque.h"
#include "ListaParques.h"
#include "checkML.h"


using namespace std;

bool cargar(tVisitas & v)
{

	ifstream is; string nombre, comunidad; char c; float cotaMax, cotaMin;
	is.open("ParquesNacionales.txt");
	if (is.is_open())
	{
		is >> v.num_filas >> v.num_columnas; is.get(c);
		 
		for (int i = 0; i < v.num_filas;i++)
		  for (int j = 0; j < v.num_columnas;j++)
		   {
			getline(is,nombre); 
			getline(is, comunidad); is >> cotaMax >> cotaMin; is.get(c);
			v.visitas[i][j] = parque(nombre, comunidad, cotaMin, cotaMax);
	    	}
		return true;
	}

	else { return false; }

}



//Resto de funciones solicitadas
