// Autor/a: Nieves N��ez
// email: nievesnu@ucm.es
// Compilador y S.O. utilizado: visual studio 2019 - windows 10
// Nombre del problema: mapa topografico
// Comentario general sobre la soluci�n: 

#include <iostream>
#include <fstream>

// Introduce m�s librer�as si son necesarias
using namespace std;
const int MAX_FILAS = 1000;
const int MAX_COLUMNAS = 1000;
//const int nfila, ncol;
typedef int tMatriz[MAX_FILAS][MAX_COLUMNAS];
//typedef int tPos[n][m];

// funci�n que resuelve el problema
int resolver(tMatriz matriz, int fila, int col) {



    return 0;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    tMatriz matriz;
    cin >> n;
    cin >> m;
    cin >> matriz[n][m];
    if (!std::cin)  // fin de la entrada
        return false;


    auto sol = resolver(matriz, n, m);

    // escribir sol

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("mapa.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}
