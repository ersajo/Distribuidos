#include <string.h>
#include <stdio.h>
#include "Respuesta.h"
#include "mensaje.h"
#include <iostream>
using namespace std;
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
void operacion1(char *s)
{
    char *word_begin = NULL;
    char *temp = s;
    while( *temp )
    {
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }
    reverse(s, temp-1);
}

int main(){
	Respuesta r(7300);
	struct mensaje msg = r.getRequest();
	char * txt=msg.arguments;
	if(msg.operationId==1){
		operacion1(txt);
	}
	r.sendReply(txt,msg.IP,msg.puerto);
	return 0;
}
