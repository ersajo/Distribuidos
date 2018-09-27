#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

#include <vector>
using namespace std;

class PoligonoIrreg{
private:
  vector<Coordenada> v;
  int vertices;
public:
  PoligonoIrreg(int numC);
  void agregarCord(Coordenada);
  void imprimeCord();
  static int vecesVer;
};
#endif
