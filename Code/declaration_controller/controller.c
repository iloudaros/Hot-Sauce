#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"

extern int yylineno;
extern int yylval;




void declare(log* l, char* identifier)
{
  l->list = (char **)realloc(l->list, (l->size)*sizeof(char*));
  l->list[l->size-1] = strdup(identifier);

}


void check_arr(log* l, char* identifier)
{
  int flag=1;
  for(int i = 0; i < l->size; i++)
  {
    flag=strcmp(l->list[i],identifier);
    if(flag==0) goto found;
  }

  printf("\"%s\" στην γραμμή %d : Δεν είναι δηλωμένο κούκλ@ μου \n", identifier, yylineno);
  exit(0);

  found:{} /*The identifier has been declared exists and we can use it*/

}
