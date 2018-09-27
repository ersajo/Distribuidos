#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include "PaqueteDatagrama.h"

int puerto = 7200;

int main(void){

  struct sockaddr_in msg_to_server_addr, client_addr;
  int s, num[2],res;
  char arreglo[4];
  int i;

  SocketDatagrama cliente(puerto);
  SocketDatagrama servidor(puerto);

  num[0] = 2;
  num[1] = 5;

  sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr*) &msg_to_server_addr, sizeof(msg_to_server_addr));
  recvfrom(s, (char*)&res, sizeof(int), 0, NULL, NULL);
  memcpy(arreglo, &msg_to_server_addr.sin_addr.s_addr, 4);
  for(i = 0; i < 4; i++){
    printf("%x\n", arreglo[i]);
  }


  printf("2 + 5 = %d\n", res);
}
