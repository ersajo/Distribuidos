#include "Fecha.h"
#include <iostream>
using namespace std;

int main()
{
	Fecha a, b, c(21, 9, 1973);
	bool ab,bb,cb;

	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	cout<< a.convierte() << endl;
	ab = a.leapyr();
	cout << "Anio bisiesto = " << ab << endl;
	b.muestraFecha();
	cout<< b.convierte() << endl;
	bb = b.leapyr();
	cout << "Anio bisiesto = " << bb << endl;
	c.muestraFecha();
	cout<< c.convierte() << endl;
	cb = c.leapyr();
	cout << "Anio bisiesto = " << cb << endl;
	int i=1,x=0;	
	for(i=1;i<2019;i++){
		a.inicializaFecha(17,6,i);
		if(a.leapyr()){
			a.muestraFecha();
			x++;
		}
	}
	cout << x << endl;
}
