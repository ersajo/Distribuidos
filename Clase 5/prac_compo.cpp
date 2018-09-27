#include "Coordenada.h"
#include "PoligonoIrreg.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int main( ){

  int n = 10000;
  int m = 20;
  vector<PoligonoIrreg> v;
  v.reserve(n);
  for (int i = 0; i < n; ++i)
  {
    int r = rand() % m;
    PoligonoIrreg Poligono(r);
    for (int e = 0; e < (r-1); ++e)
    {
  	   Coordenada cord1(rand()%100,rand()%100);
  		 Poligono.agregarCord(cord1);
  	}
  	v[i] = Poligono;
  }

  cout << PoligonoIrreg::vecesVer<<endl;
  return 0;
}
