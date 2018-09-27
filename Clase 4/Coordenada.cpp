#include "Coordenada.h"
#include <iostream>
#include <math.h>

using namespace std;

Coordenada::Coordenada(float rr, float angle) :r(rr), theta(angle), x(rr*cos(angle)), y(rr*sin(angle)){}

double Coordenada::obtenerX(){
  return x;
}

double Coordenada::obtenerY(){
  return y;
}

float Coordenada::obtenerR(){
  return r;
}

float Coordenada::obtenerTheta(){
  return theta;
}
