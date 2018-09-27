#include <iostream>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <atomic>

using namespace std;

atomic<int> i(0);

void funcioni(int valor)
{
	int j;
	while(j<=valor){	
	i++;
	j++;
	}
	sleep(1);
}

void funciond(int valor)
{
	int j;
	while(j<=valor){	
	i--;
	j++;
	}
	sleep(1);
}

int main()
{
	int n=29000;
	thread th1(funcioni,n), th2(funciond,n);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout << i;
	exit(0);
}
