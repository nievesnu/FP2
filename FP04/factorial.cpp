#include <iostream>
using namespace std;

long long int factorial(int n); // Prototipo

int main() {
   int num;
   cout << "Num: ";
   cin >> num;
   cout << "Factorial de " << num << ": " << factorial(num) << endl;
   
   return 0;
}

long long int factorial(int n) {
   long long int fact = 1;
   
   if (n < 0) {
      fact = 0;
   }
   else {
      for (int i = 1; i <= n; i++) {
         fact = fact * i;
      }
   }
   
   return fact;
}
