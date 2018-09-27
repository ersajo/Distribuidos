#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
private:
  double x;
  double y;
  float r;
  float theta;
public:
  Coordenada(float = 0, float = 0);
  Coordenada(double = 0, double = 0);
  double obtenerX();
  double obtenerY();
  float obtenerR();
  float obtenerTheta();
};
#endif
