/***** The Parser of the greatest computer language of all time, HotSauce *****/

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declarations of flex derived tools

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int  yywrap;

int yylex();
void yyerror(const char* s);

%}


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

%token<item> KEY_CHARACTER
%token<item> KEY_NUM
%token<item> KEY_IDENTIFIER
%token<item> KEY_STRING

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
  KEY_PROGRAM KEY_IDENTIFIER struct_decls functions main {printf("Parsed Successfully!🔥");}
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
  KEY_INT KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON ;

char_array_decl:
  KEY_CHAR KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON ;

int:
  KEY_INT identifier_list
  ;

char:
  KEY_CHAR identifier_list
  ;

int_array:
  KEY_INT KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR
  ;

char_array:
  KEY_CHAR KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR
  ;



/*** start of structs ***/

struct_decl:
	  KEY_STRUCT KEY_IDENTIFIER vardeclaration KEY_ENDSTRUCT
    ;

typedef_decl:
	  KEY_TYPEDEF KEY_STRUCT KEY_IDENTIFIER vardeclaration KEY_SEMICOLON KEY_IDENTIFIER KEY_ENDSTRUCT
    ;

struct_decls:
	  struct_decl
	  | struct_decls struct_decl
	  | typedef_decl
	  | struct_decls typedef_decl
    | //empty
	  ;

struct_call:
	  KEY_STRUCT KEY_IDENTIFIER
    ;


/*** FUNCTIONS ***/

functions:
      function
      | functions function
      ;

function:
  //empty
  | KEY_FUNCTION KEY_IDENTIFIER KEY_PARL parameters KEY_PARR body return KEY_ENDFUNCTION {}
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
  KEY_IDENTIFIER
  | KEY_NUM
  | KEY_CHARACTER
	;

identifier_list:
  KEY_IDENTIFIER
  | identifier_list KEY_COMMA KEY_IDENTIFIER
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
  | KEY_IDENTIFIER KEY_PARL identifier_list KEY_PARR KEY_SEMICOLON {}
  | KEY_IDENTIFIER KEY_PARL KEY_PARR KEY_SEMICOLON {}
	;

assignment:
  KEY_IDENTIFIER KEY_ASSIGN expression KEY_SEMICOLON
  | KEY_IDENTIFIER KEY_ASSIGN KEY_NUM KEY_SEMICOLON
  | KEY_IDENTIFIER KEY_ASSIGN KEY_CHARACTER KEY_SEMICOLON
  ;

expression:
  KEY_NUM
  | KEY_IDENTIFIER
  | expression KEY_PLUS expression
  | expression KEY_MIN expression
  | expression KEY_MUL expression
  | expression KEY_DIV expression
  | KEY_MIN expression %prec KEY_MIN
  | KEY_PARL expression KEY_PARR
  | KEY_IDENTIFIER KEY_PARL parameters KEY_PARR KEY_SEMICOLON
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
	KEY_CASE KEY_PARL condition KEY_PARR KEY_COLON statements break
  ;

default:
	KEY_DEFAULT KEY_COLON statements KEY_ENDSWITCH
  ;


condition:
  KEY_NUM
  | KEY_IDENTIFIER
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

for: KEY_FOR KEY_IDENTIFIER KEY_COLON KEY_ASSIGN KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM statements KEY_ENDFOR ;

/*** PRINT ***/

print:
  KEY_PRINT KEY_PARL KEY_STRING KEY_PARR KEY_SEMICOLON
  |  KEY_PRINT KEY_PARL KEY_STRING KEY_PARR KEY_COMMA KEY_IDENTIFIER KEY_BRACKETR KEY_PARR KEY_SEMICOLON
  ;

/*** BREAK ***/

break:
  KEY_BREAK KEY_SEMICOLON
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
