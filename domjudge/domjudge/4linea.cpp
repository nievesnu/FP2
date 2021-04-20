//Autor / a: Nieves N��ez
// email: nievesnu@ucm.es
// Compilador y S.O. utilizado: visual studio 2019 - windows 10
// Nombre del problema: mapa topografico
// Comentario general sobre la soluci�n: 

#include <iostream>
#include <fstream>

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

// función que resuelve el problema
bool resolver(Datos datos) {
    bool ok = false;

    return ok;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada

    Solucion sol = resolver(datos);

    // escribir solución
}