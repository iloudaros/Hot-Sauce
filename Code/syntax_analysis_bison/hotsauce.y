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
%token KEY_IDENTIFIER KEY_NUM
%token KEY_MAIN KEY_ENDMAIN
%token KEY_WHILE KEY_ENDWHILE
%token KEY_FOR KEY_TO KEY_STEP KEY_ENDFOR
%token KEY_IF KEY_THEN KEY_ELSEIF KEY_ELSE KEY_ENDIF
%token KEY_SWITCH KEY_CASE KEY_DEFAULT KEY_ENDSWITCH
%token KEY_PRINT
%token KEY_BREAK
%token KEY_ASSIGN
%token KEY_BRACKETR KEY_BRACKETL KEY_PARR KEY_PARL KEY_COMMA KEY_SEMICOLON KEY_COLON
%token KEY_CHARACTER
%token KEY_STRING

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
  KEY_PROGRAM KEY_IDENTIFIER functions main {printf("Alles gut!");}
  ;

main:
  KEY_MAIN body KEY_ENDMAIN
  ;

vardeclaration:
  //empty
  | KEY_VARS variables KEY_SEMICOLON;


body:
  //empty
  | vardeclaration statements
  ;

/*** start of structs ***/
/*
struct_decl:
	  KEY_STRUCT KEY_IDENTIFIER variables KEY_ENDSTRUCT
    ;

typedef_decl:
	  KEY_TYPEDEF KEY_IDENTIFIER KEY_STRUCT variables KEY_ENDSTRUCT KEY_SEMICOLON
    ;

struct_decls:
	  struct_decl
	  | struct_decl struct_decls
	  | typedef_decl
	  | typedef_decl struct_decls
	  ;

struct_call:
	  KEY_STRUCT KEY_IDENTIFIER
    ;

*/

/*** FUNCTIONS ***/

functions:
      function
      | functions function
      ;

function:
  //empty
  | KEY_FUNCTION KEY_IDENTIFIER KEY_PARL parameters KEY_PARR body return KEY_ENDFUNCTION
  ;

parameters:
  //empty
  | KEY_IDENTIFIER
  | parameters KEY_COMMA KEY_IDENTIFIER
	;

return:
  | KEY_RETURN return_val
  ;

return_val:
  KEY_IDENTIFIER
  | KEY_NUM
	;

variables:
  variable
  | variables variable
	;

variable:
  //empty
  | int
  | char
  | char_array
  | int_array
	;

int:
  KEY_INT identifier_list KEY_SEMICOLON
  ;

char:
  KEY_CHAR identifier_list KEY_SEMICOLON
  ;

identifier_list:
  KEY_IDENTIFIER
  | identifier_list KEY_COMMA KEY_IDENTIFIER
	;

int_array:
  KEY_INT KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON
  ;

char_array:
  KEY_CHAR KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON
  ;

statements:
  statement
  | statements statement
  ;

statement:
  //empty
  | assignment
  | while
  | for
  | if
  | switch
  | print
  | break
  | KEY_IDENTIFIER KEY_PARL identifier_list KEY_PARR KEY_SEMICOLON
	;

assignment:
  KEY_IDENTIFIER KEY_ASSIGN expression KEY_SEMICOLON
  | KEY_IDENTIFIER KEY_ASSIGN KEY_NUM KEY_SEMICOLON
  | KEY_IDENTIFIER KEY_ASSIGN KEY_CHARACTER KEY_SEMICOLON
  ;

expression:
  KEY_NUM //{$$ = $1;}
  | expression KEY_PLUS expression //{$$ = $1 + $3;}
  | expression KEY_MIN expression //{$$ = $1 - $3;}
  | expression KEY_MUL expression //{$$ = $1 * $3;}
  | expression KEY_DIV expression //{$$ = $1 / $3;}
  | KEY_MIN expression %prec KEY_MIN //{$$ = -$2;}
  | KEY_PARL expression KEY_PARR //{$$ = $2;}
  | KEY_IDENTIFIER KEY_PARL parameters KEY_PARR KEY_SEMICOLON
  ;

/*** IF ***/

if:
	if_start KEY_ENDIF
	| if_start else KEY_ENDIF
	| if_start else_ifs KEY_ENDIF
	| if_start else_ifs else KEY_ENDIF
	;

if_start:
	KEY_IF KEY_PARL condition KEY_PARR KEY_THEN statements
  ;

else_ifs:
  else_if
	| else_ifs else_if
	;

else_if:
	KEY_ELSEIF KEY_PARL condition KEY_PARR KEY_THEN statements
  ;

else:
	KEY_ELSE statements
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

/*** SWITCH ***/

switch:
  switch_start cases KEY_ENDSWITCH
	| switch_start cases default KEY_ENDSWITCH
	;

switch_start:
	KEY_SWITCH KEY_PARL condition KEY_PARR
  ;

cases:
	case
	| cases case
	;

case:
	KEY_CASE KEY_PARL condition KEY_PARR KEY_COLON statements KEY_BREAK
  ;

default:
	KEY_DEFAULT KEY_COLON statements
  ;

/*** WHILE ***/

while:
	KEY_WHILE KEY_PARL condition KEY_PARR statements KEY_ENDWHILE
  ;

/*** FOR ***/

for:
	KEY_FOR KEY_IDENTIFIER KEY_COLON KEY_EQUAL KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM statements KEY_ENDFOR
  ;

/*** PRINT ***/

print:
  KEY_PRINT KEY_PARL KEY_PARR KEY_SEMICOLON
  | KEY_PRINT KEY_PARL KEY_STRING KEY_PARR KEY_SEMICOLON
  |  KEY_PRINT KEY_PARL KEY_STRING KEY_PARR print_data KEY_BRACKETR KEY_PARR KEY_SEMICOLON
  ;

print_data:
  KEY_COMMA KEY_IDENTIFIER
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
  ++argv; --argc;
  if ( argc > 0 ) yyin = fopen( argv[0], "r" );
  yyparse ();

  return 0;
}
