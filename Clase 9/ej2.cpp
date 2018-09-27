#include <iostream>
#include <unistd.h>
#include <thread>
#include <stdio.h>

using namespace std;

int i=0;

void funcioni()
{
	i++;
	sleep(1);
}

void funciond()
{
	i--;
	sleep(1);
}

int main()
{
	thread th1(funcioni), th2(funciond);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout << i;
	exit(0);
}
