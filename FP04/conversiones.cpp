#include <iostream>
using namespace std;
// Prototipos
int menu();
double pulgACm(double pulg);
double lbAGr(double libras);
double grFAGrC(double grF);
double galALtr(double galones);

int main() {
   double valor;
   int op = -1;
   while (op != 0) {
      op = menu();
      switch (op) {
      case 1:
         {
            cout << "Pulgadas: ";
            cin >> valor;
            cout << "Son " << pulgACm(valor) << " cm." << endl;
         }
         break;
      case 2:
         {
            cout << "Libras: ";
            cin >> valor;
            cout << "Son " << lbAGr(valor) << " gr." << endl;
         }
         break;
      case 3:
         {
            cout << "Grados Fahrenheit: ";
            cin >> valor;
            cout << "Son " << grFAGrC(valor) << " ºC" << endl;
         }
         break;
      case 4:
         {
            cout << "Galones: ";
            cin >> valor;
            cout << "Son " << galALtr(valor) << " l." << endl;
         }
         break;
      }
   }
   return 0;
}

int menu() {
   int op = -1;

   while ((op < 0) || (op > 4)) {
      cout << "1 - Pulgadas a Cm." << endl;
      cout << "2 - Libras a Gr." << endl;
      cout << "3 - Fahrenheit a ºC" << endl;
      cout << "4 - Galones a L." << endl;
      cout << "0 - Salir" << endl;
      cout << "Elige: ";
      cin >> op;
      if ((op < 0) || (op > 4)) {
         cout << "Opción no válida" << endl;
      }
   }

   return op;
}

double pulgACm(double pulg) {
   const double cmPorPulg = 2.54;
   return pulg * cmPorPulg;
}

double lbAGr(double libras) {
   const double grPorLb = 453.6;
   return libras * grPorLb;
}

double grFAGrC(double grF) {
   return ((grF - 32) * 5 / 9);
}

double galALtr(double galones) {
   const double ltrPorGal = 4.54609;
   return galones * ltrPorGal;
}
         