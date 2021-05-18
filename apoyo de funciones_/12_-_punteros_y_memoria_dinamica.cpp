#include <iostream>
using namespace std;


int main() {
	system("chcp 1252"); system("cls");
	// Punteros b�sicos
	/* Dibujo de un bloque de memoria
		#1[                       ]
		#2[                       ]
		#3[                       ]
		#4[                       ]
		#5[                       ]
		#6[                       ]

		Cada casilla tiene un n�mero asignado (una direcci�n)

		Si hacemos int coso = 14;
		Se me guarda en la memoria el valor
		(en el n�mero que pille m�s disponible, en este caso el 3)

		#1[                       ]
		#2[                       ]
		#3[        14			  ]
		#4[                       ]
		#5[                       ]
		#6[                       ]

		Pero en lugar de esto, se puede decir que quiero guardar la direcci�n de otra variable
		en estas casillitas, esto es muy �til

		int *coso2 = &coso; <- Esto signfica que en lugar de guardar el 14, guardamos la direcci�n donde est� el valor de coso;

		#1[                       ]
		#2[                       ]
		#3[        14			  ] <- aqui tenemos coso
		#4[                       ]
		#5[                       ]
		#6[        #3             ] <- aqui tenemos coso2 que es un puntero a coso (guarda la direcci�n de memoria de coso)

		&cualquier_cosa <- significa "recoger" la direcci�n donde se guarda �cualquier_cosa�
	*/

	// Ejercicio 1, mostrar la direcci�n donde se guarda un valor
	int coso = 14;
	cout << "El valor de coso es: " << coso << " pero, la direcci�n de coso es: " << &coso <<
		"\n Para mostrar la direcci�n de coso hemos usado &coso\n\n";
	system("pause");

	// Ejercicio 2, guardar ese valor en un puntero
	int* coso2 = &coso;
	cout << "El valor que guarda coso2 es: " << coso2 <<
		" Esto es debido a que hemos guardado con �xito la direcci�n de memoria\n\n";
	system("pause");

	// Ejercicio 3, imprimir direcci�n de coso2
	cout << "La direcci�n coso2 es: " << &coso2 <<
		" Esto es debido a que tiene su propio hueco en la memoria\n\n";
	system("pause");

	// Ejercicio 4, el valor de coso2 apuntado
	cout << "El valor al que apunta coso2 es: " << *coso2 <<
		" Para esto, tenemos que poner un * a coso2 a la hora de mostrarlo u operar con ello\n\n";
	system("pause");

	// Ejercicio 5, cambiar el valor de coso
	coso = 16;
	cout << "El valor de coso ha cambiado, ahora es: " << coso << " su direcci�n de memoria es: " << &coso << endl;
	cout << "Entonces coso2, tendr� la direcci�n guardada de: " << coso2 << endl;
	cout << "Y el valor apuntado por coso2 es: " << *coso2 << endl << endl;
	system("pause");

	// Ejercicio 6, Uso de arrays como si fueran punteros sin tama�o inicial
	int a[] = { -10,2,4,5,6,7,8 };
	cout << "Mostramos la primera posici�n: " << a[1] << " con la direcci�n: " << &a[1] << "\n";
	cout << "Y el valor, es el mismo que imprimir *(a+1)\n [que significa, imprimir el valor que hay en la posici�n del array +1]: " <<
		*(a + 1) << endl;
	cout << "Ahora imprimo la direcci�n de (a+1) con &(*(a+1)): " << &(*(a + 1)) << " para que veamos que concuerda" << endl;
	//Importante: int* b[7] = { -10,2,4,5,6,7,8 }; <- no funcionar�

	// Ejercicio 7, memoria din�mica con punterizaci�n
	// Esto sirve para generar un array sin tama�o final, antes ten�amos arrays de tama�o fijo, ahora no, ahora podemos hacerlo
	// Con el tama�o que nos indiquen por entrada de consola, y modificarlo en un futuro
	int tamanio;
	cout << "Mete un tama�o para un array: ";
	cin >> tamanio;
	int* dinamico = new int[tamanio]; // esto me da una direcci�n nueva del tama�o que quiero
	cout << "Hemos creado un array en tiempo de ejecuci�n de tama�o: " << tamanio << endl;
	cout << "La direcci�n donde comienza nuestro array din�mico es: " << dinamico << endl;
	cout << "Ahora, vamos a introducir elementos de forma normal en el array\n\n" << endl;
	for (int i = 0; i < tamanio; ++i) cin >> dinamico[i];
	cout << "Y lo mostramos por pantalla: ";
	for (int i = 0; i < tamanio; ++i) cout << dinamico[i] << ", ";

	// Ejercicio 8, BORRAR MEMORIA, IMPORTANTE
	/*
		Todo new necesita un delete para evitar fugas de memoria
		El ordenador es amable, nos deja posiciones de memoria de forma din�mica, pero cuando yo deje de usarlas
		tengo que decirle al ordenador que ya no quiero usarlas, �C�mo? haciendo un delete
	*/
	delete[] dinamico; //Elimina array dinamico
	//Hay que tener cuidado para no confundir un array dinamico con un array est�tico de datos din�micos;
	//En el supuesto caso de tener lo segundo, habr� que hacer un for para borrar cada una de las posiciones


	return 0;
}

