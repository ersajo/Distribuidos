#include <iostream>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <atomic>

using namespace std;

void funcioni(int valor,atomic<int>& var)
{
	int j;
	while(j<=valor){	
	var++;
	j++;
	}
	sleep(1);
}

void funciond(int valor,atomic<int>& var)
{
	int j;
	while(j<=valor){	
	var--;
	j++;
	}
	sleep(1);
}

int main()
{
	atomic<int> i(0);
	int n=29000;
	thread th1(funcioni,n,ref(i)), th2(funciond,n,ref(i));
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout << i;
	exit(0);
}
