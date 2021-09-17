#pragma once



typedef struct{
  char** list;
  int size;
}log;


void declare(log* l, char* identifier);


void check_arr(log* l, char* identifier);
