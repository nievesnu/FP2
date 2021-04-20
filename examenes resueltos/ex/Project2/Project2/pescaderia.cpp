#include "pescaderia.h"
#include "fstream"
#include "iostream"
#include <cmath>
using namespace std;


// IMPLEMENTA AQUÍ LOS SUBPROGRAMAS PEDIDOS 

int valorCompra(const tCesta& cesta) {
	int total = 0;
	for (int i = 0; i < cesta.contador; i++) {
		total += cesta.productos[i].cantidad_pedida; //multiplicamos los productos y la cantidad pedida y lo añadimos a total
	}
	cout << "El coste de la compra asciende a: "<< total << " euros." << endl; 
	return total;
}

int busqueda(tListaProductos& cesta, string st) { // hacemos una busqueda secuencial para ver si está el nombre en la cesta y si no está buscado es negativo
	int buscado = -1;
	for (int i = 0; i < cesta.contador; i++)
	{
		if (st == cesta.productos[i]->nombre)
		{
			buscado = i;
		}
	}
	return buscado;
}

void borrado(tCesta& cesta, int pos) {
	for (int i = pos; i < cesta.contador; i++)
	{
		cesta.productos[i] = cesta.productos[i + 1];
	}
	delete cesta.productos[cesta.contador];
	cesta.contador--;
}

int hazLaCompra(tListaProductos& catalogo, tCesta& cesta) { //si se encuentra el nombre y la cantidad pedida puede ser mayor o,  menor o igual a la que tenemos disponible
	int suma = 0;
	for (int i = 0; i < catalogo.contador; i++)
	{
		int pos = busqueda(catalogo, cesta.productos[i].nombre);
		if (pos != -1)
		{
			suma += catalogo.productos[pos]->cantidad_disponible * catalogo.productos[pos]->precio; // si es mayor borramos la pos y el producto desaparece
			borrado(cesta, pos);
		}
		else
		{
			suma += cesta.productos[i].cantidad_pedida * catalogo.productos[pos]->precio; //sumamos cantidad pedida multiplicada por el precio y actualizamos la disponible
			catalogo.productos[pos]->cantidad_disponible += cesta.productos[i].cantidad_pedida;
		}
	}
	return suma;
}

void liberar(tListaProductos& lista) {
	delete[] lista.productos;
	lista.productos = nullptr;
	lista.contador = 0;
}

// carga el catálogo de productos desde fichero
bool cargarListaProductos(tListaProductos& catalogo) {
	ifstream fichero;
	bool ok = true;
	tProducto producto;
	int numProductos;

	fichero.open("catalogo.txt");
	if (!fichero.is_open()) ok = false;
	else {
		catalogo.contador = 0;
		fichero >> numProductos;
		for (int i = 0; i < numProductos; i++) {
			fichero >> producto.nombre;
			fichero >> producto.cantidad_disponible;
			fichero >> producto.precio;
			fichero.ignore();
			catalogo.productos[i] = new tProducto(producto);
			catalogo.contador = catalogo.contador + 1;
		}
		fichero.close();
	}
	return ok;
}

// carga una cesta de la compra desde fichero
bool cargarCestaCompra(tCesta& cesta) {
	ifstream fichero;
	bool ok = true;
	int numProductos;

	fichero.open("cesta.txt");
	if (!fichero.is_open()) ok = false;
	else {
		cesta.contador = 0;
		cesta.productos = new tPeticion[MAX_PETICIONES];
		fichero >> numProductos;
		for (int i = 0; i < numProductos; i++) {
			fichero >> cesta.productos[cesta.contador].nombre;
			fichero >> cesta.productos[cesta.contador].cantidad_pedida;
			cesta.contador = cesta.contador + 1;
			fichero.ignore();
		}
		fichero.close();
	}
	return true;
}

// muestra el catálogo de productos por pantalla
void mostrarListaProductos(const tListaProductos& catalogo) {
	cout << "********* CATALOGO DE PRODUCTOS *********" << endl;
	for (int i = 0; i < catalogo.contador; i++)
		cout << catalogo.productos[i]->nombre << " - "
			<< catalogo.productos[i]->cantidad_disponible << " kg - "
			<< catalogo.productos[i]->precio << " euros" << endl;
	cout << endl;
}

// muestra la cesta de la compra por pantalla
void mostrarCestaCompra(const tCesta& cesta) {
	cout << "*********  CESTA DE LA COMPRA   *********" << endl;
	for (int i = 0; i < cesta.contador; i++)
		cout << cesta.productos[i].nombre << " - " << cesta.productos[i].cantidad_pedida << " kg" << endl;
	cout << endl;
}