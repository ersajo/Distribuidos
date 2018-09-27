PaqueteDatagrama::PaqueteDatagrama(char * datos, unsigned int longitud, char* ip, int puerto){
  this->datos = datos;
  this->longitud = longitud;
  this->ip = ip;
  this->puerto = puerto;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud){}

PaqueteDatagrama::~PaqueteDatagrama(){}

char* PaqueteDatagrama::getDireccion(){
  return ip;
}

unsigned int PaqueteDatagrama::getLongitud(){
  return longitud;
}

int PaqueteDatagrama::getPuerto(){
  return puerto;
}

char* PaqueteDatagrama::getDatos(){
  return datos;
}

void PaqueteDatagrama::inicializaPuerto(int puerto){}

void PaqueteDatagrama::inicializaIp(char *ip){}

void PaqueteDatagrama::inicializaDatos(char *datos){}
