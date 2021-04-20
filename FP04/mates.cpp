#include <iostream>
using namespace std;

// Prototipos
long long int factorial(int n);
int sumatorio(int n);

int main() {
   int num;
   cout << "Num: ";
   cin >> num;
   cout << "Factorial de "
        << num << ": "
        << factorial(num)
        << endl
        << "Sumatorio de 1 a " 
        << num << ": " 
        << sumatorio(num)
        << endl;

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

int sumatorio(int n) {
   int sum = 0;

   for (int i = 1; i <= n; i++) {
      sum = sum + i;
   }

   return sum;
}
