// ****************************************************

// Prueba de evaluacion del dia 22 de junio de 2020
// Alumno/a: Nieves Núñez Ugena
// email:  nievesnu@ucm.es
// ****************************************************

#include "iostream"
#include "pescaderia.h"
using namespace std;

int main() {
	tListaProductos catalogo;
	tCesta cesta;
	float costeCompra;


	if (cargarListaProductos(catalogo) && cargarCestaCompra(cesta)) {
		mostrarListaProductos(catalogo);
		mostrarCestaCompra(cesta);
		cout << endl << "Y ahora veamos cuanto cuesta la compra y como queda el catalogo" << endl << endl;
		// INCORPORA AQU� EL C�DIGO NECESARIO PARA LLEVAR A CABO LOS PASOS (c), (d) y (e) DEL PROGRAMA PRINCIPAL
		hazLaCompra(catalogo, cesta);
		valorCompra(cesta);
		liberar(catalogo);
	}
	else
		cout << "cargas fallidas" << endl;

	return 0;
}


