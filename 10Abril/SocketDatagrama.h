#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

class SocketDatagrama{
public:
  SocketDatagrama(int);
  ~SocketDatagrama();
  int recibe(PaqueteDatagrama & p);
  int envia(PaqueteDatagrama & p);
private:
  struct sockaddr_in direccionLocal;
  struct sockaddr_in direccionForanea;
  int s;
};

#endif
