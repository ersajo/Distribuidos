#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

class PaqueteDatagrama {
public:
  PaqueteDatagrama(char *, unsigned int, char*, int);
  PaqueteDatagrama(unsigned int);
  ~PaqueteDatagrama();
  char *getDireccion();
  unsigned int getLongitud();
  int getPuerto();
  char *getDatos();
  void inicializaPuerto(int);
  void inicializaIp(char *);
  void inicializaDatos(char *);
private:
  char *datos;
  char ip[6];
  unsigned int longitud;
  int puerto;
};

#endif
