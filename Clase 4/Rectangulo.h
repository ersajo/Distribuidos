#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Coordenada.h"
class Rectangulo{
private:
  Coordenada superiorIzq;
  Coordenada inferiorDer;
public:
  Rectangulo();
  Rectangulo(Coordenada sup, Coordenada inf);
  void imprimeEsq();
  Coordenada obtieneSupIzq();
  Coordenada obtieneInfDer();
  void obtenerArea();
};
#endif
