#ifndef SOLICITUD_H
#define SOLICITUD_H
#include "mensaje.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
class Solicitud
{
public:
	Solicitud();
	char * doOperation(char * IP, int puerto, int operationId, char * arguments);
private:
	SocketDatagrama *socketLocal;
};
#endif
