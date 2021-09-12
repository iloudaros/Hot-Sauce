#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;

void init_arr(struct arr* arr,size_t initialSize)
{
  arr->array = (struct(Variable *)malloc(initialSize*sizeof(struct variable));
  arr->used = 0;
  arr->size = initialSize;
}

void insert_arr(struct arr* arr, struct variable element)
{
  if(arr->used == arr->size)
  {
    arr->size *= 2;
    arr->array = (struct variable *)realloc(arr->array, a->size * sizeof(struct variable));
  }
  arr->array[a->used++] = element;
}

void empty_arr(struct arr* arr)
{
  free(arr->array);
  arr->array = NULL;
  arr->used = arr->size = 0;
}

void print_arr(char* str, struct variable item, struct arr)
{
  memmove(&str[0], &str[1], strlen(str))
  str[strlen(str) - 1] = 0;

  printf("%s", str);

  if (item.type == INT)
  {
    printf("%d\n");
  } else
  {
    if (item.string[0] == '"' || item.string[0] == '\'' && item.string)
    {
        memmove(&item.string[0], &item.string[1], strlen(item.string));
        item.string[strlen(item.string) - 1] = 0;
    }

    print("%s\n", item.string);

  }
}

void check_arr(struct variable item, struct arr *arr)
{
  int i = 0;
  int found_flag = 0;
  while(i < arr->used)
  {
    if (strcmp(arr->array[i].name) == 0)
    {
      found_flag = 1;
    }
    i++;
  }

  if(found_flag)
  {
    printf(stderr, "%s in line %d has not been defined!\n", item.name, yylineno);
    exit(1);
  }

}
