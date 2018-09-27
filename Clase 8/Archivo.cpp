#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Archivo.h"
using namespace std;

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
  contenido = (char *) realloc(contenido, num_bytes+nbytes);
  size_t var = read(fd, contenido+num_bytes, nbytes);
	num_bytes += var;
  return var;
}

size_t Archivo::escribe(void *buffer,size_t nbytes){
  return write(fd,buffer,nbytes);
}

size_t Archivo::obtieneNum_bytes(){
  return num_bytes;
}

const char* Archivo::get_contenido(){
	return contenido;
}

int Archivo::obtieneId(){
	return fd;
}

Archivo::~Archivo(){
	close(fd);
}
