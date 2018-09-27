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

  double num_random1;
  double num_random2;
  srand48(time(NULL));

  vector<PoligonoIrreg> v;
  v.reserve(n);
  for (int i = 0; i < n; ++i)
  {
    int r = rand() % m;
    PoligonoIrreg Poligono(r);
    for (int e = 0; e < (r-1); ++e)
    {
       num_random1 = drand48() * (100.0 + 100.0) - 100.0;
       num_random2 = drand48() * (100.0 + 100.0) - 100.0;
  	   Coordenada cord1(num_random1, num_random2);
  		 Poligono.agregarCord(cord1);
  	}
  	v[i] = Poligono;
    Poligono.imprimeCord();
  }

  return 0;
}
