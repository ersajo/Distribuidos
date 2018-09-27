#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <algorithm>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>
using namespace std;


//***********************************
#ifndef WORD_H
#define WORD_H
class Word{
private:
  string pal;
  int num;
public:
  Word(string palabra);
  Word(string palabra, int n);
  void printNum();
  void printPalabra();
  string getPal();
  int getNum();
  void sum();
  void sum(int n);
  ~Word();
};
#endif
//*****
Word::Word(string palabra){
  pal = palabra;
  num = 1;
}

Word::Word(string palabra, int n){
  pal  = palabra;
  num = n;
}

void Word::printNum(){
  cout << num << endl;
}

void Word::printPalabra(){
  cout << "Palabra: " << pal << "\tRepeticiones: " << num << endl;
}

string Word::getPal(){
  return pal;
}

int Word::getNum(){
  return num;
}

void Word::sum(){
  num++;
}

void Word::sum(int n){
  num += n;
}

Word::~Word(){}

//***************************************************************
#ifndef ARCHIVO_H
#define ARCHIVO_H
class Archivo{
private:
  string nombreArchivo;
  int fd;
  unsigned char *contenido;
  size_t num_bytes;
public:
  Archivo(string filename);
  Archivo(string filename, int banderas, mode_t modo);
  size_t lee(size_t nbytes);
  size_t escribe(void* buffer, size_t nbytes);
  size_t getNumBytes();
  const unsigned char* getContenido();
  int getId();
  void printName();
  ~Archivo();
};
#endif

//***********************************************************

Archivo::Archivo(string filename){
	nombreArchivo = filename;
	fd = open(nombreArchivo.c_str(),O_RDONLY);
	num_bytes = 0;
	contenido = NULL;
}

Archivo::Archivo(string filename, int banderas, mode_t modo){
	nombreArchivo = filename;
	fd = open(nombreArchivo.c_str(),banderas,modo);
	num_bytes = 0;
	contenido = NULL;
}

size_t Archivo::lee(size_t nbytes){
  contenido = (unsigned char *) realloc(contenido, num_bytes+nbytes);
  size_t var = read(fd, contenido+num_bytes, nbytes);
	num_bytes += var;
  return var;
}

size_t Archivo::escribe(void *buffer,size_t nbytes){
  return write(fd,buffer,nbytes);
}

size_t Archivo::getNumBytes(){
  return num_bytes;
}

const unsigned char* Archivo::getContenido(){
	return contenido;
}

int Archivo::getId(){
	return fd;
}

void Archivo::printName(){
  cout << nombreArchivo << endl;
}

Archivo::~Archivo(){
	close(fd);
}
//**********************************************************

vector <Word> palabras;
vector <Word> arr[8];
vector <string> nameFiles;

int isLetter(int ch){
  //Buscar letras mayusculas sin acento
  if(ch >= 65 && ch <= 90)
    return 1;
  //Buscar letras minusculas sin acento
  if(ch >= 97 && ch <= 122)
    return 1;
  //Buscar letras minusculas con acento
  if(ch == 195 || ch == 161 || ch == 169 || ch == 173 || ch == 179 || ch == 186)
    return 1;
  //Buscar letras mayusculas con acentos
  if(ch == 129 || ch == 137 || ch == 141 || ch == 147 || ch == 154)
    return 1;
  //Buscar letras minusculas con dieresis
  if(ch == 164 || ch == 171 || ch == 175 || ch == 182 || ch == 188)
    return 1;
  //Buscar letras mayusculas con dieresis
  if(ch == 132 || ch == 139 || ch == 143 || ch == 150 || ch == 156)
    return 1;
  //Buscar ñ o Ñ
  if(ch == 145 || ch == 177)
    return 1;
  return 0;
}

int find(vector<Word> pals, Word pal){
  for(int i = 0; i < pals.size(); i++)
    if (pal.getPal() == pals[i].getPal()){
      return i;
  }
  return -1;
}

bool sortVector(Word w1, Word w2){
  return w1.getNum() > w2.getNum();
}

void procesamiento(int min, int max, int i){
  long words = 0;
  const unsigned char* content;
  string cad;
  int pos;

  for(int j = min; j < max; j++){
    if (j > nameFiles.size()) break;
    Archivo temp(nameFiles[j]);
    while (temp.lee(1000)>0);
    content = temp.getContenido();
    int n = 0;
    unsigned char prev = ' ';
    unsigned char actual = content[n];
    while(actual != EOF){
      if(!isLetter(prev) && isLetter(actual)){
        words++;
        cad.erase(cad.begin(), cad.end());
        while(isLetter(actual)){
          cad.push_back(toupper(actual));
          prev = actual;
          actual = content[++n];
        }
        pos = find(arr[i], cad);
        if(arr[i].size() == 0)
          arr[i].push_back(cad);
        else if (pos != -1)
          arr[i][pos].sum();
        else
          arr[i].push_back(cad);
      }
      prev = actual;
      actual = content[++n];
      if (content[n+1] == 0)
        break;
    }
    cout << "\nANALISIS FINALIZADO DE " << nameFiles[j] << "\n" <<endl;
  }
}

int main (int argc, char* argv[]){
  setlocale(LC_CTYPE, "");
  DIR *dip;
  struct dirent *dit;
  int i=0;
  string cad;

  if(argc < 2){
    printf("Usage: %s <directory>\n", argv[0]);
    return 0;
  }

  if ((dip = opendir(argv[2])) == NULL){
    perror("opendir");
    return 0;
  }

  printf("Directory stream is now open\n");

  while((dit = readdir(dip)) != NULL){
    i++;
    printf("%s\n", dit->d_name);
    if(i > 2){
      cad.erase(cad.begin(), cad.end());
      cad.append(argv[2]);
      cad.append("/");
      cad.append(dit->d_name);
      nameFiles.push_back(cad);
    }
  }
  cout << "\n\n"<< endl;

  int num = nameFiles.size()/atoi(argv[1]);
  vector <int> limites;
  for(int n = 0; n < 9; n++){
    limites.push_back(n*num);
  }

  thread th1(procesamiento, limites[0], limites[1], 0);
  thread th2(procesamiento, limites[1], limites[2], 1);
  thread th3(procesamiento, limites[2], limites[3], 2);
  thread th4(procesamiento, limites[3], limites[4], 3);
  thread th5(procesamiento, limites[4], limites[5], 4);
  thread th6(procesamiento, limites[5], limites[6], 5);
  thread th7(procesamiento, limites[6], limites[7], 6);
  thread th8(procesamiento, limites[7], limites[8], 7);

  th1.join();
  th2.join();
  th3.join();
  th4.join();
  th5.join();
  th6.join();
  th7.join();
  th8.join();

  cout << "Procesamiento finalizado" << endl;

  int res;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < arr[i].size(); j++){
      res = find(palabras, arr[i][j]);
      if(res == -1){
        Word aux(arr[i][j].getPal(),arr[i][j].getNum());
        palabras.push_back(aux);
      }
      else
        palabras[res].sum(arr[i][j].getNum());
    }
  }

  sort(palabras.begin(), palabras.end(), sortVector);
  for(int r = 0; r < palabras.size(); r++){
    palabras[r].printPalabra();
  }

  printf("\n\nreaddir() found a total of %i files\n", i);
  if(closedir(dip) == -1){
    perror("closedir");
    return 0;
  }


  printf("\nDirectory stream is now closed\n");
  return 1;

}
