#ifndef RESPUESTA_H
#define RESPUESTA_H
#include "mensaje.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
class Respuesta
{
public:
	Respuesta(int pl);
	struct mensaje getRequest(void);
	void sendReply(char * respuesta, char* ipCliente, int puertoCliente);
private:
	SocketDatagrama *socketLocal;
};
#endif
