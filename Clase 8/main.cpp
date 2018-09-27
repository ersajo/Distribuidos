#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include "Archivo.h"
using namespace std;


int main (){
	Archivo a1("p1.jpg");
	cout << a1.obtieneId() << endl;
	Archivo a2("p2.jpg",O_WRONLY|O_TRUNC|O_CREAT,0666);
	while(a1.lee(10)>0);

	a2.escribe((void*) a1.get_contenido(),a1.obtieneNum_bytes());



	return 0;
}
