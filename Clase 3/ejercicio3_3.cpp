#include "Fecha.h"
#include <iostream>

using namespace std;

int masVieja(Fecha *fecha1, Fecha *fecha2){
  int f1 = fecha1->convierte();
  int f2 = fecha2->convierte();
  if(f1 == f2)
    return 0;
  else if (f1 > f2)
    return 1;
  else if (f2 > f1)
    return -1;
}

int main(){
  Fecha a, b;
  for (int i = 0; i < 100000; i++) {
    b.inicializaFecha( rand() % 31 +1, rand() % 12 +1, rand() % 2018 +1);
    masVieja(&a,&b);
  }
}
