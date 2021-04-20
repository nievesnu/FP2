#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include "registrofin.h"

tRegistro nuevo() {
   tRegistro registro;
   cout << "Introduce el código: ";
   cin >> registro.codigo;
   cout << "Introduce el nombre: ";
   cin >> registro.nombre;
   cout << "Introduce el sueldo: ";
   cin >> registro.sueldo;
   return registro;
}

bool operator>(tRegistro opIzq, tRegistro opDer) {
   return opIzq.nombre > opDer.nombre;
}

bool operator<(tRegistro opIzq, tRegistro opDer) {
   return opIzq.nombre < opDer.nombre;
}

void mostrar(int pos, tRegistro registro) {
   cout << setw(3) << pos << ": "
        << setw(10) << registro.codigo 
        << setw(20) << registro.nombre 
        << setw(12) << fixed << setprecision(2)
        << registro.sueldo << endl;
}
