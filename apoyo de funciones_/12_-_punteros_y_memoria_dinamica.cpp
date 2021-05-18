#include <iostream>
using namespace std;


int main() {
	system("chcp 1252"); system("cls");
	// Punteros básicos
	/* Dibujo de un bloque de memoria
		#1[                       ]
		#2[                       ]
		#3[                       ]
		#4[                       ]
		#5[                       ]
		#6[                       ]

		Cada casilla tiene un número asignado (una dirección)

		Si hacemos int coso = 14;
		Se me guarda en la memoria el valor
		(en el número que pille más disponible, en este caso el 3)

		#1[                       ]
		#2[                       ]
		#3[        14			  ]
		#4[                       ]
		#5[                       ]
		#6[                       ]

		Pero en lugar de esto, se puede decir que quiero guardar la dirección de otra variable
		en estas casillitas, esto es muy útil

		int *coso2 = &coso; <- Esto signfica que en lugar de guardar el 14, guardamos la dirección donde está el valor de coso;

		#1[                       ]
		#2[                       ]
		#3[        14			  ] <- aqui tenemos coso
		#4[                       ]
		#5[                       ]
		#6[        #3             ] <- aqui tenemos coso2 que es un puntero a coso (guarda la dirección de memoria de coso)

		&cualquier_cosa <- significa "recoger" la dirección donde se guarda «cualquier_cosa»
	*/

	// Ejercicio 1, mostrar la dirección donde se guarda un valor
	int coso = 14;
	cout << "El valor de coso es: " << coso << " pero, la dirección de coso es: " << &coso <<
		"\n Para mostrar la dirección de coso hemos usado &coso\n\n";
	system("pause");

	// Ejercicio 2, guardar ese valor en un puntero
	int* coso2 = &coso;
	cout << "El valor que guarda coso2 es: " << coso2 <<
		" Esto es debido a que hemos guardado con éxito la dirección de memoria\n\n";
	system("pause");

	// Ejercicio 3, imprimir dirección de coso2
	cout << "La dirección coso2 es: " << &coso2 <<
		" Esto es debido a que tiene su propio hueco en la memoria\n\n";
	system("pause");

	// Ejercicio 4, el valor de coso2 apuntado
	cout << "El valor al que apunta coso2 es: " << *coso2 <<
		" Para esto, tenemos que poner un * a coso2 a la hora de mostrarlo u operar con ello\n\n";
	system("pause");

	// Ejercicio 5, cambiar el valor de coso
	coso = 16;
	cout << "El valor de coso ha cambiado, ahora es: " << coso << " su dirección de memoria es: " << &coso << endl;
	cout << "Entonces coso2, tendrá la dirección guardada de: " << coso2 << endl;
	cout << "Y el valor apuntado por coso2 es: " << *coso2 << endl << endl;
	system("pause");

	// Ejercicio 6, Uso de arrays como si fueran punteros sin tamaño inicial
	int a[] = { -10,2,4,5,6,7,8 };
	cout << "Mostramos la primera posición: " << a[1] << " con la dirección: " << &a[1] << "\n";
	cout << "Y el valor, es el mismo que imprimir *(a+1)\n [que significa, imprimir el valor que hay en la posición del array +1]: " <<
		*(a + 1) << endl;
	cout << "Ahora imprimo la dirección de (a+1) con &(*(a+1)): " << &(*(a + 1)) << " para que veamos que concuerda" << endl;
	//Importante: int* b[7] = { -10,2,4,5,6,7,8 }; <- no funcionará

	// Ejercicio 7, memoria dinámica con punterización
	// Esto sirve para generar un array sin tamaño final, antes teníamos arrays de tamaño fijo, ahora no, ahora podemos hacerlo
	// Con el tamaño que nos indiquen por entrada de consola, y modificarlo en un futuro
	int tamanio;
	cout << "Mete un tamaño para un array: ";
	cin >> tamanio;
	int* dinamico = new int[tamanio]; // esto me da una dirección nueva del tamaño que quiero
	cout << "Hemos creado un array en tiempo de ejecución de tamaño: " << tamanio << endl;
	cout << "La dirección donde comienza nuestro array dinámico es: " << dinamico << endl;
	cout << "Ahora, vamos a introducir elementos de forma normal en el array\n\n" << endl;
	for (int i = 0; i < tamanio; ++i) cin >> dinamico[i];
	cout << "Y lo mostramos por pantalla: ";
	for (int i = 0; i < tamanio; ++i) cout << dinamico[i] << ", ";

	// Ejercicio 8, BORRAR MEMORIA, IMPORTANTE
	/*
		Todo new necesita un delete para evitar fugas de memoria
		El ordenador es amable, nos deja posiciones de memoria de forma dinámica, pero cuando yo deje de usarlas
		tengo que decirle al ordenador que ya no quiero usarlas, ¿Cómo? haciendo un delete
	*/
	delete[] dinamico; //Elimina array dinamico
	//Hay que tener cuidado para no confundir un array dinamico con un array estático de datos dinámicos;
	//En el supuesto caso de tener lo segundo, habrá que hacer un for para borrar cada una de las posiciones


	return 0;
}

