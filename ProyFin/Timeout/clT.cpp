#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define max 10

set<unsigned long> setOfNumbers;
set<char*> setOfMessages;
set<unsigned long>::iterator itU;
set<char*>::iterator itC;

int insertNum(unsigned long num){
  return setOfNumbers.insert(num).second;
}

unsigned long TELgen(){
	char* tel = (char *)malloc(10*sizeof(char));
  tel[0] = '5';
  tel[1] = '5';

	for (int i = 2; i <= 10; i++) {
		tel[i] = 48+(rand()%10);
	}

	return strtoul(tel, NULL, 0);
}

char* genRFC(){
  char* RFC = (char *)malloc(12*sizeof(char));
  for(int i = 0; i < 13; i++){
    if(i < 4 || i > 9)
      RFC[i] = 65 + (rand()%26);
    else
      RFC[i] = 48 + (rand()%10);
  }
  return RFC;
}

void genMessage(unsigned long num){
  char* message = (char *)malloc(25*sizeof(char));
  char* RFC;
  char voto;
  RFC = genRFC();
  voto = 48 + (rand()%10);
  sprintf(message,"%ld%s%d", num, RFC, voto);
  setOfMessages.insert(message).second;
}

int main(int argc, char const *argv[])
{
	Solicitud s;
	int id = 0;
	char* aux;
	srand(time(NULL));
	for(int i = 0; i < max; i++) {
    while (1) {
      unsigned long num = TELgen();
      if(insertNum(num)) break;
    }
	}

	for (itU = setOfNumbers.begin(); itU != setOfNumbers.end(); ++itU){
    genMessage(*itU);
  }
  for (itC = setOfMessages.begin(); itC != setOfMessages.end(); ++itC){
   aux = s.doOperation((char*)argv[1], 7300, 0, *itC, id);
	 printf("Respuesta %s\n",aux);
	 id++;
	}
	std::cout<<setOfNumbers.size()<<std::endl;

	return 0;
}
