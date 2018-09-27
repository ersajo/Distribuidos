#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Respuesta.h"
#include "mensaje.h"
#include <iostream>
#include <sstream>
using namespace std;

int nbd = 0;

int opLectura()
{
    return nbd;
}

int opEscritura(int c){
    nbd +=c;
    return nbd;
}

int main(){
	Respuesta r(7300);
	struct mensaje msg;
	int cantidad;
    char num[TAM_MAX_DATA];
    string stx="";
    stringstream cvstr;
    while(1){
        msg = r.getRequest();
        cantidad=atoi(msg.arguments);
    	if(msg.operationId==1){
            cvstr<<opLectura();
    	}
        if(msg.operationId==2){
            cvstr<<opEscritura(cantidad);
        }
        stx=cvstr.str().c_str();
        strcpy(num,stx.c_str());
    	  r.sendReply(num,msg.IP,msg.puerto);
        cvstr.str("");
    }
	return 0;
}
