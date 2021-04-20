#include <iostream>
using namespace std;
#include "registro.h"

int main() {
   tRegistro reg;
   reg = nuevo();
   tRegistro *punt = new tRegistro(reg);
   mostrar(*punt);
   delete punt;
   
   return 0;
}

