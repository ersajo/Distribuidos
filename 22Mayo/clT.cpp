#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	Solicitud s;
	printf("%s\n", s.doOperation("127.0.0.1",7300,1,"Hola mundo esto es una prueba"));
	return 0;
}
