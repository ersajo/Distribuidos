#include<iostream>
#include<set>
#include <cstdlib>
#include <cstdio>
using namespace std;

set<unsigned long> setOfNumbers;

#define max 10

using namespace std;

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

char* genMessage(unsigned long num){
  char* message = (char *)malloc(25*sizeof(char));
  char* RFC;
  char voto;
  RFC = genRFC();
  voto = 48 + (rand()%10);
  sprintf(message,"%ld%s%d", num, RFC, voto);
  return message;
}

int main(){
  srand(time(NULL));
	for(int i = 0; i < max; i++) {
    while (1) {
      unsigned long num = TELgen();
      if(insertNum(num)) break;
    }
	}

   std::cout<<setOfNumbers.size()<<std::endl;

	 for (set<unsigned long>::iterator it = setOfNumbers.begin(); it != setOfNumbers.end(); ++it){
     cout << genMessage(*it) << endl;
   }

 return 0;
}
