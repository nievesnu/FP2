#include <iostream>
#include <string>
using namespace std;

const int NCLI = 100;
const int NPROD = 200;
const int NVENTAS = 3000;

typedef struct {
   int id_cli;
   string nif;
   string nombre;
   string telefono;
} tCliente;

typedef struct {
   tCliente clientes[NCLI];
   int cont;
} tListaClientes;

typedef struct {
   int id_prod;
   string codigo;
   string nombre;
   double precio;
   int unidades;
} tProducto;

typedef struct {
   tProducto productos[NPROD];
   int cont;
} tListaProductos;

typedef struct {
   int id;
   int id_prod;
   int id_cli;
   int unidades;
} tVenta;

typedef struct {
   tVenta ventas[NVENTAS];
   int cont;
} tListaVentas;

tCliente nuevoCliente();
bool valida(tCliente cliente); // Función interna
bool operator<(tCliente opIzq, tCliente opDer); // Por NIF
void mostrar(tCliente cliente);
void inicializar(tListaClientes &lista);
void cargar(tListaClientes &lista);
void insertar(tListaClientes &lista, tCliente cliente, bool &ok);
void buscar(const tListaClientes &lista, string nif, tCliente &cliente, bool &ok);
void eliminar(tListaClientes &lista, string nif, bool &ok);
void mostrar(const tListaClientes &lista);
tProducto nuevoProducto();
bool valida(tProducto producto); // Función interna
bool operator<(tProducto opIzq, tProducto opDer); // Por código
void mostrar(tProducto producto);
void inicializar(tListaProductos &lista);
void cargar(tListaProductos &lista);
void insertar(tListaProductos &lista, tProducto producto, bool &ok);
void buscar(const tListaProductos &lista, string codigo, tProducto &producto, bool &ok);
void eliminar(tListaProductos &lista, string codigo, bool &ok);
void mostrar(const tListaProductos &lista);
tVenta nuevaVenta(int id_prod, int id_cli, int unidades);
bool valida(tVenta venta); // Función interna
void mostrar(tVenta venta, const tListaClientes &clientes, const tListaProductos &productos);
void inicializar(tListaVentas &lista);
void cargar(tListaVentas &lista);
void insertar(tListaVentas &lista, tVenta venta, bool &ok);
void buscar(const tListaVentas &lista, int id, tVenta &venta, bool &ok);
void eliminar(tListaVentas &lista, int id, bool &ok);
void ventasPorClientes(const tListaVentas &lista);
void ventasPorProductos(const tListaVentas &lista);
double totalVentas(const tListaVentas &ventas, string nif, const tListaClientes &clientes, const tListaProductos &productos);
void stock(const tListaVentas &ventas, const tListaClientes &clientes, const tListaProductos &productos);
int menu();

int main() {
   tListaClientes clientes;
   inicializar(clientes);
   cargar(clientes);
   tListaProductos productos;
   inicializar(productos);
   cargar(productos);
   tListaVentas ventas;
   inicializar(ventas);
   cargar(ventas);
   int op;
   do {
      op = menu();
      //...
   } while (op != 0);

   return 0;
}

tCliente nuevoCliente() {
   tCliente cliente;
   // ...
   return cliente;   
}

bool valida(tCliente cliente) {
   //...
   return true;
}

bool operator<(tCliente opIzq, tCliente opDer) {
   return opIzq.nif < opDer.nif;
}

void mostrar(tCliente cliente) {
   // ...
}

void inicializar(tListaClientes &lista) {
   lista.cont = 0;
}

void cargar(tListaClientes &lista) {
   // ...
}

void insertar(tListaClientes &lista, tCliente cliente, bool &ok) {
   // ...
}

void buscar(const tListaClientes &lista, string nif, tCliente &cliente, bool &ok) {
   // ...
}

void eliminar(tListaClientes &lista, string nif, bool &ok) {
   // ...
}

void mostrar(const tListaClientes &lista) {
   // ...
}

tProducto nuevoProducto() {
   tProducto producto;
   // ...
   return producto;
}

bool valida(tProducto producto) {
   //...
   return true;
}

bool operator<(tProducto opIzq, tProducto opDer) {
   return opIzq.codigo < opDer.codigo;
}

void mostrar(tProducto producto) {
   // ...
}

void inicializar(tListaProductos &lista) {
   lista.cont = 0;
}

void cargar(tListaProductos &lista) {
   // ...
}

void insertar(tListaProductos &lista, tProducto producto, bool &ok) {
   // ...
}

void buscar(const tListaProductos &lista, string codigo, tProducto &producto, bool &ok) {
   // ...
}

void eliminar(tListaProductos &lista, string codigo, bool &ok) {
   // ...
}

void mostrar(const tListaProductos &lista) {
   // ...
}

tVenta nuevaVenta(int id_prod, int id_cli, int unidades) {
   tVenta venta;
   // ...
   return venta;
}

bool valida(tVenta venta) {
   //...
   return true;
}

void mostrar(tVenta venta, const tListaClientes &clientes, const tListaProductos &productos) {
   // ...
}

void inicializar(tListaVentas &lista) {
   lista.cont = 0;
}

void cargar(tListaVentas &lista) {
   // ...
}

void insertar(tListaVentas &lista, tVenta venta, bool &ok) {
   // ...
}

void buscar(const tListaVentas &lista, int id, tVenta &venta, bool &ok) {
   // ...
}

void eliminar(tListaVentas &lista, int id, bool &ok) {
   // ...
}

void ventasPorClientes(const tListaVentas &lista) {
   // ...
}

void ventasPorProductos(const tListaVentas &lista) {
   // ...
}

double totalVentas(const tListaVentas &ventas, string nif, const tListaClientes &clientes, const tListaProductos &productos) {
   double total = 0;
   // ...
   return total;
}

void stock(const tListaVentas &ventas, const tListaClientes &clientes, const tListaProductos &productos) {
   // ...
}

int menu() {
   int op;
   // ...
   return op;
}
