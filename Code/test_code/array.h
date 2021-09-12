#pragma once

struct variable
{
  enum{INT,CHAR,FUN} type;
  enum{VAR = 1, LITERAL = 2} data_type;
  char name[100];
};

struct arr
{
  struct variable *array;
  size_t used;
  size_t size;
};

void init_arr(struct arr* array,size_t initialSize);

void insert_arr(struct arr* array, struct variable element);

void empty_arr(struct arr* array);

void print_arr(char* str, struct variable item, struct arr);

void check_arr(struct variable item, struct arr *arr);

// #include<stdio.h>
// #include<stdlib.h>
// #include <string.h>
//
// struct node
// {
//   enum{INT,CHAR,FUN} type;
//   enum{VAR, LITERAL} data_type;
//   char name[100];
//   node *next;
// } node_t;
//
// node_t *head = NULL;
//
// void push(node_t *head, enum{INT,CHAR,FUN} type, enum{VAR, LITERAL} data_type, char name[100])
// {
//   node_t *current = head;
//   while(current->next != null)
//   {
//     current = current->next;
//   }
//
//   current->next = (node_t* )malloc(sizeof(node_t))
//   current->next->type = type;
//   current->next->data_type = data_type;
//   current->next->name =
// }
