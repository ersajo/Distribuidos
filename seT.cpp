#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Respuesta.h"
#include "mensaje.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void escrituraBD(char *datos){
	string data(datos);

	ofstream  dimensionsOutfile("Votos.txt", ofstream::app);												
	if(!dimensionsOutfile){
		//cout<<"Cannot load file"<<endl;
		return;
	}
	else{

		dimensionsOutfile << data << '\n';

		printf("Dato guardado\n");

		//cout << "All members have been successfully saved" << endl;
		dimensionsOutfile.close();
	}
}

int main(){
	ofstream dimensionOutfile("Votos.txt", ofstream::out);
	Respuesta r(7300);
	struct mensaje msg;
	char* mensaje;
	char num[TAM_MAX_DATA];
	string stx="";
	stringstream cvstr;
	while(1){
		msg = r.getRequest();
		mensaje = msg.arguments;
		if(msg.operationId==0){
			escrituraBD(msg.arguments);
		}
		printf("\nrequestId: %d\tmensaje: %s\toperacion: %d\n", msg.requestId, mensaje, msg.operationId);
		r.sendReply(msg.arguments, msg.IP, msg.puerto, msg.requestId);
	}
	return 0;
}
