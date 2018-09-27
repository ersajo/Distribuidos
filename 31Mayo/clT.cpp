#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int numeroIte=atoi(argv[1]);
	Solicitud s;
	int total=0;
	int aux;
	for (int i = 0; i < numeroIte; i++)
	{
		aux=atoi( s.doOperation("10.100.70.230",7201,1,"0"));
		aux=atoi(s.doOperation("127.0.0.1",7300,1,"0"));
		printf("Consulta %d\n",aux);
		if(aux==total){
			printf("Agregamos 1, confirmación:  %s\n", s.doOperation("10.100.70.230",7201,2,"1"));
			//printf("Agregamos 1, confirmación:  %s\n", s.doOperation("127.0.0.1",7300,2,"1"));
			total+=1;
		}else{
			printf("Error no coinciden las cuentas\n");
			break;
		}
	}
	return 0;
}
