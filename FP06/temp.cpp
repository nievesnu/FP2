#include <iostream>
#include <fstream>
using namespace std;
#include <iomanip>

int main() {
   const int MaxDias = 31;
   const int MED = 2; // Nº de medidas
   typedef double tTemp[MaxDias][MED]; // Día x mínima / máxima
   tTemp temp;
   double tMaxMedia = 0, tMinMedia = 0,
          tMaxAbs = -100, tMinAbs = 100;
   int dia = 0;
   double max, min;
   ifstream archivo;
   
   archivo.open("temp.txt");
   if(!archivo.is_open())
      cout << "No se ha podido abrir el archivo." << endl;
   else {
      archivo >> min >> max;
      while(!((min == -99) && (max == -99)) && (dia < MaxDias)) {
            temp[dia][0] = min;
            temp[dia][1] = max;
            dia++;
            archivo >> min >> max;
         }
      archivo.close();
      for(int i = 0; i < dia; i++) {
         tMinMedia = tMinMedia + temp[i][0];
         if(temp[i][0] < tMinAbs) {
            tMinAbs = temp[i][0];
         }
         tMaxMedia = tMaxMedia + temp[i][1];
         if(temp[i][1] > tMaxAbs) {
            tMaxAbs = temp[i][1];
         }
      }
      tMinMedia = tMinMedia / dia;
      tMaxMedia = tMaxMedia / dia;
      cout << "Temperaturas minimas.-" << endl;
      cout << "    Media = " << fixed << setprecision(1) 
           << tMinMedia << " C    Minima absoluta = "
           << setprecision(1) << tMinAbs << " C" << endl;
      cout << "Temperaturas maximas.-" << endl;
      cout << "    Media = " << fixed << setprecision(1) 
           << tMaxMedia << " C    Maxima absoluta = "
           << setprecision(1) << tMaxAbs << " C" << endl;
   }

   return 0;
}
