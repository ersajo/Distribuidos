/*USANDO C-STRING*/
#include <iostream>
#include <string.h>

using namespace std;

int main() {
  int n = 10000000;
  char* word = NULL;
  char* cString = NULL;
  char* outString = NULL;
  cString = (char*) malloc (23*3);
  word = (char*) malloc (23*3);
  outString = (char*) malloc (23*4*n);
  srand(time(NULL));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++){
      cString[j] = rand()%26+65;
    }
    if (i == 60){
      word = cString;
    }
    strcat(outString, cString);
    strcat(outString, " ");
  }
  if (strstr(outString, "IPN") == NULL){
    cout << "NO SE ENCONTRO LA CADENA" << endl;
  }
  else{
    cout << "SE ENCONTRO LA CADENA" << endl;
  }
  return 0;
}
