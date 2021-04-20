#include <iostream>
using namespace std;

void cambio(double precio, double pago, int &euros, int &cent50,
   int &cent20, int &cent10, int &cent5, int &cent2, int &cent1,
   bool &error);

int main() {
   double precio, pago;
   int euros, cent50, cent20, cent10, cent5, cent2, cent1;
   bool error;
   cout << "Precio: ";
   cin >> precio;
   cout << "Pago: ";
   cin >> pago;
   cambio(precio, pago, euros, cent50, cent20, cent10, cent5, cent2,
          cent1, error);
   if (error) {
      cout << "Error: El pago es inferior al precio" << endl;
   }
   else {
      cout << "Cambio: " << euros << " euros, " 
           << cent50 << " x 50c., " 
           << cent20 << " x 20c., " 
           << cent10 << " x 10c., " 
           << cent5 << " x 5c., " 
           << cent2 << " x 2c. y " 
           << cent1 << " x 1c." << endl;
   }

   return 0;
}

void cambio(double precio, double pago, int &euros, int &cent50,
   int &cent20, int &cent10, int &cent5, int &cent2, int &cent1,
   bool &error) {
   
   if (pago < precio) { // Cantidad insuficiente
      error = true;
   }
   else {
      error = false;
      int cambio = int(100.0 * (pago - precio) + 0.5);
      euros = cambio / 100;
      cambio %= 100;
      cent50 = cambio / 50;
      cambio %= 50;
      cent20 = cambio / 20;
      cambio %= 20;
      cent10 = cambio / 10;
      cambio %= 10;
      cent5 = cambio / 5;
      cambio %= 5;
      cent2 = cambio / 2;
      cent1 = cambio % 2;
   }
}
