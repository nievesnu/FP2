/* Recorremos las letras de la primera palabra y las buscamos en la segunda
Cuando se encuentra, se borra de la segunda cadena para evitar problemas con las letras repetidas */
#include <iostream>
#include <string>
using namespace std;

// Índice del primer caracter c en cad; -1 si no está
int buscaCaracter(string cad, char c);

int main() {
	string cad1, cad2;
	bool sonAnagramas = true;
	int numCar, posEnCad2;

	// Leemos las cadenas de teclado
	cout << "Introduce la primera cadena: ";
	getline(cin, cad1);
	cout << "Introduce la segunda cadena: ";
	getline(cin, cad2);

	// Si las cadenas tienen distinta longitud no son anagramas
	if (cad1.length() != cad2.length()) {
		sonAnagramas = false;
   }
	else {
		numCar = 0;  // Contador que recorre los caracteres de la primera cadena
		while (sonAnagramas && (numCar < cad1.length())) {
			posEnCad2 = buscaCaracter(cad2, cad1.at(numCar));
			if (posEnCad2 == -1) { // No se ha encontrado el caracter
				sonAnagramas = false;
         }
			else {
				cad2.erase(posEnCad2, 1);
         }
			numCar++;
		}
	}

	// Mostramos el resultado
	if (sonAnagramas) {
		cout << "Las palabras introducidas son anagramas" << endl;
   }
	else {
		cout << "Las palabras introducidas NO son anagramas" << endl;
   }

	return 0;
}

int buscaCaracter(string cad, char c) {
	int pos = 0, lon = cad.length();
	bool encontrado = false;
   
	while ((pos < lon) && !encontrado) {
		if (cad.at(pos) == c) {
			encontrado = true;
      }
      else {
         pos++;
      }
	}
	if (!encontrado) {
		pos = -1;
   }
   
	return pos;
}
