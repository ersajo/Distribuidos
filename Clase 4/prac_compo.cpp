#include "Rectangulo.h"
#include "Coordenada.h"

#include <iostream>
#include <math.h>

using namespace std;

int main( ){
  float r1, angle1, r2, angle2;

  r1 = 3.605551275;
  angle1 = 0.9827937232;
  r2 = 5.099019514;
  angle2 = 0.1973955598;

  Rectangulo rectangulo1(Coordenada(r1,angle1),Coordenada(r2,angle2));

  rectangulo1.obtenerArea();

  return 0;
}
