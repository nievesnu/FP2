// ****************************************************
// Prueba de evaluación del día 22 de junio de 2020
// Alumno/a: 
// email:  @ucm.es
// ******

#ifndef pescaderia_h
#define pescaderia_h

#include <string>
using namespace std;

const int MAX_PRODUCTOS = 50;
const int MAX_PETICIONES = 20;


typedef struct {
	string nombre;
	float cantidad_disponible, precio;
} tProducto;

typedef tProducto* tPtrProducto;

typedef struct {
	tPtrProducto productos[MAX_PRODUCTOS];
	int contador;
} tListaProductos;

typedef struct {
	string nombre;
	float cantidad_pedida;
} tPeticion;

typedef tPeticion* tPtrPeticion;

typedef struct {
	tPtrPeticion productos;
	int contador;
} tCesta;

// carga el catálogo de productos desde fichero
bool cargarListaProductos(tListaProductos& catalogo);

// carga una cesta de la compra desde fichero
bool cargarCestaCompra(tCesta& cesta);

// muestra el catálogo de productos por pantalla
void mostrarListaProductos(const tListaProductos& catalogo);

// muestra la cesta de la compra por pantalla
void mostrarCestaCompra(const tCesta& cesta);

// PROTOTIPOS NECESARIOS SEGÚN ENUNCIADO

//borrar array
void borrado(tCesta& cesta, int pos);
//buscar elemento
int busqueda(tListaProductos& cesta, string st);
//hacer la compra
int hazLaCompra(tListaProductos& catalogo, tCesta& cesta);

//coste de la compra
int valorCompra(const tCesta& cesta);

//lib mem dinamica
void liberar(tListaProductos& lista);

#endif