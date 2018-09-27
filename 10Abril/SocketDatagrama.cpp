SocketDatagrama::SocketDatagrama(int puertoLocal){
  s = socket(AF_INET, SOCK_DGRAM, 0);
  bzero((char *)&direccionForanea, sizeof(direccionForanea));
  direccionForanea.sin_family = AF_INET;
  direccionForanea.sin_addr.s_addr = inet_addr("10.100.69.219");
  direccionForanea.sin_port = htons(puerto);

  bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){}

int SocketDatagrama::recibe(PaqueteDatagrama & p){
  recvfrom(s, p.getDatos(), sizeof(int), 0, NULL, NULL);
}

int SocketDatagrama::envia(PaqueteDatagrama & p){
  sendto(s, p.getDatos(), p.getLongitud(), 0, direccionForanea, sizeof(direccionForanea));
}
