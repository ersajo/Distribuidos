#include "Coordenada.h"
#include "PoligonoIrreg.h"

#include <vector>
#include <iostream>

using namespace std;


int PoligonoIrreg::vecesVer = 0;

PoligonoIrreg::PoligonoIrreg(int numC){
  v.reserve(numC);
  vertices = 0;
}

void PoligonoIrreg::agregarCord(Coordenada c){
  v[vertices] = c;
  vecesVer++;
  vertices++;
}

void PoligonoIrreg::imprimeCord(){
  cout << "Vertices: " << vertices << endl;
  for(unsigned int i=0; i < vertices; i++){
    v[i].imprimeCord();
    cout << "Magnitud del vertice " << i << ": " << v[i].obtenerMagnitud() << endl;
	}
  cout << endl;
}
