/***** The Parser of the greatest computer language of all time, HotSauce *****/

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define 10 50

//Declarations of flex derived tools

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int  yywrap;

int yylex();
void yyerror(const char* s);

char decl_vars [10][30];
char decl_funcs [10][30];
char decl_structs [10][30];

int var_count = 0;
int fun_count = 0;
int struct_count = 0;

int found_flag = 0;


%}

%union
{
  char id[30];
}

/*** Here, we declare the tokens ***/

%token KEY_PROGRAM
%token KEY_FUNCTION KEY_RETURN KEY_ENDFUNCTION
%token KEY_VARS KEY_CHAR KEY_INT
%token KEY_MAIN KEY_ENDMAIN
%token KEY_WHILE KEY_ENDWHILE
%token KEY_FOR KEY_TO KEY_STEP KEY_ENDFOR
%token KEY_IF KEY_ELSEIF KEY_ENDIF
%token KEY_THEN
%token KEY_ELSE
%token KEY_SWITCH KEY_CASE KEY_DEFAULT KEY_ENDSWITCH
%token KEY_PRINT
%token KEY_BREAK
%token KEY_ASSIGN
%token KEY_BRACKETR KEY_BRACKETL KEY_PARR KEY_PARL KEY_COMMA KEY_SEMICOLON KEY_COLON

%token KEY_CHARACTER
%token KEY_NUM
%token KEY_STRING

%token KEY_IDENTIFIER
%type<id> KEY_IDENTIFIER

%left KEY_AND
%left KEY_OR

%nonassoc KEY_GREATER KEY_LESSER KEY_EQUAL KEY_NOTEQUAL
%left KEY_MUL KEY_DIV
%left KEY_PLUS KEY_MIN

%token KEY_TYPEDEF
%token KEY_STRUCT
%token KEY_ENDSTRUCT

//%type<item> print_data

%%
/*** Here, you can see the rules ***/

//Declarations
program:
  KEY_PROGRAM KEY_IDENTIFIER struct_decls functions main {printf("Parsed Successfully!🔥 \n");}
  ;

main:
  KEY_MAIN body KEY_ENDMAIN
  ;

vardeclaration:
  //empty
  | KEY_VARS variables_decl
  ;

variables_decl:
  variable_decl
  | variables_decl variable_decl
  ;

variable_decl:
  //empty
  | int_decl
  | char_decl
  | char_array_decl
  | int_array_decl
  ;

int_decl:
  int KEY_SEMICOLON
  ;

char_decl:
  char KEY_SEMICOLON
  ;

int_array_decl:
  KEY_INT KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON  { strcpy(decl_vars[var_count], $2); var_count++; } ;

char_array_decl:
  KEY_CHAR KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON { strcpy(decl_vars[var_count], $2); var_count++; } ;

int:
  KEY_INT identifier_list
  ;

char:
  KEY_CHAR identifier_list
  ;

int_array:
  KEY_INT KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR { strcpy(decl_vars[var_count], $2); var_count++; }
  ;

char_array:
  KEY_CHAR KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR { strcpy(decl_vars[var_count], $2); var_count++; }
  ;

/*** start of structs ***/

struct_decl:
	  KEY_STRUCT KEY_IDENTIFIER vardeclaration KEY_ENDSTRUCT { strcpy(decl_structs[struct_count], $2); struct_count++; }
    ;

typedef_decl:
	  KEY_TYPEDEF KEY_STRUCT KEY_IDENTIFIER vardeclaration KEY_SEMICOLON KEY_IDENTIFIER KEY_ENDSTRUCT { strcpy(decl_structs[struct_count], $6); struct_count++; }
    ;

struct_decls:
	  struct_decl
	  | struct_decls struct_decl
	  | typedef_decl
	  | struct_decls typedef_decl
    | //empty
	  ;

struct_call:
	  KEY_STRUCT KEY_IDENTIFIER {
                                found_flag = 0;

                                for(int i=0; i<10 ; i++)
                                {
                                  if(strcmp($2,decl_structs[i])==0)
                                  {
                                    found_flag = 1;
                                    break;
                                  }

                                  if(found_flag == 0)
                                  {
                                    printf("Struct %s in line %d not declared. \n",$2, yylineno);
                                    exit(1);
                                  }

                                }
                              }
    ;

/*** FUNCTIONS ***/

functions:
      function
      | functions function
      ;

function:
  //empty
  | KEY_FUNCTION KEY_IDENTIFIER KEY_PARL parameters KEY_PARR body return KEY_ENDFUNCTION { strcpy(decl_funcs[fun_count], $2); fun_count++; }
  ;

parameters:
  parameter
  | parameters KEY_COMMA parameter
  ;

parameter:
  int
  | char
  | int_array
  | char_array
  | struct_call
  ;

body:
  vardeclaration statements
  ;

return:
  | KEY_RETURN return_val
  ;

return_val:
  KEY_IDENTIFIER  {
                    found_flag = 0;

                    for(int i=0; i<10 ; i++)
                    {
                      if(strcmp($1,decl_vars[i])==0)
                      {
                        found_flag = 1;
                        break;
                      }
                    }

                    if(found_flag == 0)
                    {
                      printf("Variable %s in line %d not declared. \n",$1, yylineno);
                      exit(1);
                    }

                  }
  | KEY_NUM
  | KEY_CHARACTER
	;

identifier_list:
  KEY_IDENTIFIER { strcpy(decl_vars[var_count], $1); var_count++; }
  | identifier_list KEY_COMMA KEY_IDENTIFIER { strcpy(decl_vars[var_count], $3); var_count++; }
  ;

statements:
  statement
  | statements statement
  ;

statement:
  assignment
  | while
  | for
  | if
  | switch
  | print
  | KEY_IDENTIFIER KEY_PARL identifier_list KEY_PARR KEY_SEMICOLON {
                                                                      found_flag = 0;

                                                                      for(int i=0; i<10 ; i++)
                                                                      {
                                                                        if(strcmp($1,decl_funcs[i])==0)
                                                                        {
                                                                          found_flag = 1;
                                                                          break;
                                                                        }
                                                                      }

                                                                      if(found_flag == 0)
                                                                      {
                                                                        printf("Function %s in line %d not declared. \n",$1, yylineno);
                                                                        exit(1);
                                                                      }

                                                                    }
  | KEY_IDENTIFIER KEY_PARL KEY_PARR KEY_SEMICOLON {
                                                      found_flag = 0;

                                                      for(int i=0; i<10 ; i++)
                                                      {
                                                        if(strcmp($1,decl_funcs[i])==0)
                                                        {
                                                          found_flag = 1;
                                                          break;
                                                        }
                                                      }

                                                      if(found_flag == 0)
                                                      {
                                                        printf("Function %s in line %d not declared. \n",$1, yylineno);
                                                        exit(1);
                                                      }

                                                    }
	;

assignment:
  KEY_IDENTIFIER KEY_ASSIGN expression KEY_SEMICOLON {
                                                        found_flag = 0;

                                                        for(int i=0; i<10 ; i++)
                                                        {
                                                          if(strcmp($1,decl_vars[i])==0)
                                                          {
                                                            found_flag = 1;
                                                            break;
                                                          }
                                                        }

                                                        if(found_flag == 0)
                                                        {
                                                          printf("Variable %s in line %d not declared. \n",$1, yylineno);
                                                          exit(1);
                                                        }

                                                      }
  | KEY_IDENTIFIER KEY_ASSIGN KEY_CHARACTER KEY_SEMICOLON {
                                                            found_flag = 0;

                                                            for(int i=0; i<10 ; i++)
                                                            {
                                                              if(strcmp($1,decl_vars[i])==0)
                                                              {
                                                                found_flag = 1;
                                                                break;
                                                              }
                                                            }

                                                            if(found_flag == 0)
                                                            {
                                                              printf("Variable %s in line %d not declared. \n",$1, yylineno);
                                                              exit(1);
                                                            }

                                                          }
  ;

expression:
  KEY_NUM
  | KEY_IDENTIFIER {
                      found_flag = 0;

                      for(int i=0; i<10 ; i++)
                      {
                        if(strcmp($1,decl_vars[i])==0)
                        {
                          found_flag = 1;
                          break;
                        }
                      }

                      if(found_flag == 0)
                      {
                        printf("Variable %s in line %d not declared. \n",$1, yylineno);
                        exit(1);
                      }

                    }
  | expression KEY_PLUS expression
  | expression KEY_MIN expression
  | expression KEY_MUL expression
  | expression KEY_DIV expression
  | KEY_MIN expression %prec KEY_MIN
  | KEY_PARL expression KEY_PARR
  | KEY_IDENTIFIER KEY_PARL parameters KEY_PARR KEY_SEMICOLON {
                                                                found_flag = 0;

                                                                for(int i=0; i<10 ; i++)
                                                                {
                                                                  if(strcmp($1,decl_funcs[i])==0)
                                                                  {
                                                                    found_flag = 1;
                                                                    break;
                                                                  }
                                                                }

                                                                if(found_flag == 0)
                                                                {
                                                                  printf("Function %s in line %d not declared. \n",$1, yylineno);
                                                                  exit(1);
                                                                }

                                                              }
  ;

/*** IF ***/

if:
	KEY_IF KEY_PARL condition KEY_PARR KEY_THEN statements KEY_ENDIF
	| if_else
	| if_elsif
  | if_elsif_else
  ;

if_else:
  KEY_IF KEY_PARL condition KEY_PARR KEY_THEN statements KEY_ELSE statements KEY_ENDIF
  ;

if_elsif:
  KEY_IF KEY_PARL condition KEY_PARR else_ifs KEY_ENDIF
  ;

else_ifs:
  else_if
  |else_ifs else_if
  ;

else_if:
  KEY_ELSEIF KEY_PARL condition KEY_PARR KEY_THEN statements
  ;

if_elsif_else:
  KEY_IF KEY_PARL condition KEY_PARR KEY_THEN statements else_ifs KEY_ELSE statements KEY_ENDIF
  ;

/*** SWITCH ***/

switch:
  switch_start cases_term
	| switch_start cases default
	;

switch_start:
	KEY_SWITCH KEY_PARL condition KEY_PARR
  ;

cases_term:
  cases KEY_ENDSWITCH
  ;

cases:
	case
	| cases case
	;

case:
	KEY_CASE KEY_PARL condition KEY_PARR KEY_COLON statements KEY_BREAK KEY_SEMICOLON
  ;

default:
	KEY_DEFAULT KEY_COLON statements KEY_ENDSWITCH
  ;


condition:
  KEY_NUM
  | KEY_IDENTIFIER {
                      found_flag = 0;

                      for(int i=0; i<10 ; i++)
                      {
                        if(strcmp($1,decl_vars[i])==0)
                        {
                          found_flag = 1;
                          break;
                        }
                      }

                      if(found_flag == 0)
                      {
                        printf("Variable %s in line %d not declared. \n",$1, yylineno);
                        exit(1);
                      }

                    }
  | condition KEY_GREATER condition
  | condition KEY_LESSER condition
  | condition KEY_EQUAL condition
  | condition KEY_NOTEQUAL condition
  | condition KEY_AND condition
  | condition KEY_OR condition
  | KEY_PARL condition KEY_PARR
  ;


/*** WHILE ***/

while: KEY_WHILE KEY_PARL condition KEY_PARR statements KEY_ENDWHILE;

/*** FOR ***/

for: KEY_FOR KEY_IDENTIFIER KEY_COLON KEY_ASSIGN KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM statements KEY_ENDFOR  {
                                                                                                                  found_flag = 0;

                                                                                                                  for(int i=0; i<10 ; i++)
                                                                                                                  {
                                                                                                                    if(strcmp($2,decl_vars[i])==0)
                                                                                                                    {
                                                                                                                      found_flag = 1;
                                                                                                                      break;
                                                                                                                    }
                                                                                                                  }

                                                                                                                  if(found_flag == 0)
                                                                                                                  {
                                                                                                                    printf("Variable %s in line %d not declared. \n",$2, yylineno);
                                                                                                                    exit(1);
                                                                                                                  }

                                                                                                                }
      ;

/*** PRINT ***/

print:
  KEY_PRINT KEY_PARL KEY_STRING KEY_PARR KEY_SEMICOLON
  |  KEY_PRINT KEY_PARL KEY_STRING KEY_PARR KEY_COMMA KEY_IDENTIFIER KEY_BRACKETR KEY_PARR KEY_SEMICOLON  {
                                                                                                            found_flag = 0;

                                                                                                            for(int i=0; i<10 ; i++)
                                                                                                            {
                                                                                                              if(strcmp($6,decl_vars[i])==0)
                                                                                                              {
                                                                                                                found_flag = 1;
                                                                                                                break;
                                                                                                              }
                                                                                                            }

                                                                                                            if(found_flag == 0)
                                                                                                            {
                                                                                                              printf("Variable %s in line %d not declared. \n",$6, yylineno);
                                                                                                              exit(1);
                                                                                                            }

                                                                                                          }
  ;

  //bis hier alles gut

%%
/*** And finally, the parser in action ***/

void yyerror(const char* s)
  {
	fprintf(stderr, "Line: %d --> Parser error\n", yylineno);
	exit(1);
  }

int main ( int argc, char **argv  )
  {

  yyin = fopen( argv[1], "r" );
  yyparse ();

  return 0;
}
