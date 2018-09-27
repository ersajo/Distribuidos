#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Respuesta.h"
#include "mensaje.h"
#include <iostream>
#include <sstream>
using namespace std;

/*int opLectura()
{
    return nbd;
}

int opEscritura(int c){
    nbd +=c;
    return nbd;
}*/

int main(){
	Respuesta r(7300);
	struct mensaje msg;
	char* mensaje;
  char num[TAM_MAX_DATA];
  string stx="";
  stringstream cvstr;
  while(1){
    msg = r.getRequest();
    mensaje = msg.arguments;
    printf("\nrequestId: %d\tmensaje: %s\toperacion: %d\n", msg.requestId, mensaje, msg.operationId);
	  r.sendReply("reply",msg.IP,msg.puerto, msg.requestId);
  }
	return 0;
}
