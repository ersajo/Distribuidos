#include "Coordenada.h"
#include <iostream>
#include <math.h>

using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy), magnitud(sqrt(pow(xx,2) + pow(yy,2))){}

double Coordenada::obtenerX(){
  return x;
}

double Coordenada::obtenerY(){
  return y;
}

void Coordenada::imprimeCord(){
  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;
}

double Coordenada::obtenerMagnitud(){
  return magnitud;
}
