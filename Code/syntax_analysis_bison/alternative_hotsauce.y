/***** The Parser of the greatest computer language of all time, HotSauce *****/

%{
#include <stdio.h>
#include <math.h>
void yyerror(char *);
extern FILE *yyin;
extern FILE *yyout;
int yylex();
extern int yylineno;

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


%%
/*** Here, you can see the rules ***/

//Βασικές Έννοιες
punctuation:
  KEY_BRACKETR
| KEY_BRACKETL
| KEY_PARR
| KEY_PARL
| KEY_COMMA
| KEY_SEMICOLON
| KEY_COLON
;

type: KEY_CHAR
| KEY_INT
;

variable: type KEY_IDENTIFIER KEY_SEMICOLON;

array: type KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON
| KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON;

variables:
variable
| array
| variables variable
| variables array
;

aoperator:
KEY_PLUS
| KEY_MIN
| KEY_MUL
| KEY_DIV
;

loperator: KEY_OR
| KEY_AND
| KEY_GREATER
| KEY_LESSER
| KEY_EQUAL
| KEY_NOTEQUAL
;

//Δηλώσεις
programtitle: KEY_PROGRAM KEY_IDENTIFIER  ;

funcdeclaration: KEY_FUNCTION KEY_IDENTIFIER KEY_PARL variables KEY_PARR KEY_SEMICOLON ;

vardeclaration: KEY_VARS variables;


//Εντολές
aexpression: aexpression aoperator aexpression
| KEY_PARL aexpression KEY_PARR
| KEY_NUM
| KEY_IDENTIFIER
| KEY_MIN aexpression
;

lexpression: aexpression
| lexpression loperator lexpression
| KEY_PARL lexpression KEY_PARR
;

assignment: KEY_IDENTIFIER KEY_ASSIGN aexpression KEY_SEMICOLON /* !!! Αν δημιουργήσει πρόβλημα, βάζουμε KEY_NUM*/
| KEY_IDENTIFIER KEY_ASSIGN KEY_CHAR KEY_SEMICOLON
;

printstatement: KEY_PRINT KEY_PARL KEY_IDENTIFIER KEY_PARR KEY_SEMICOLON
| KEY_PRINT KEY_PARL KEY_IDENTIFIER KEY_BRACKETL KEY_IDENTIFIER KEY_BRACKETR KEY_PARR KEY_SEMICOLON
;

//Δομές Επανάληψης
while: KEY_WHILE KEY_PARL lexpression KEY_PARR  statements  KEY_ENDWHILE ;

for: KEY_FOR KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM  statements  KEY_ENDFOR ;

//Δομές Απόφασης
if: KEY_IF KEY_PARL lexpression KEY_PARR KEY_THEN  statements elseif else KEY_ENDIF;

elseif: elseif KEY_ELSEIF KEY_PARL lexpression KEY_PARR  statements
| KEY_ELSEIF KEY_PARL lexpression KEY_PARR  statements
| /* empty */
;

else: KEY_ELSE KEY_PARL lexpression KEY_PARR  statements
| /* empty */
;

switch: KEY_SWITCH KEY_PARL lexpression KEY_PARR  case default KEY_ENDSWITCH;

case: case KEY_CASE KEY_PARL lexpression KEY_PARR KEY_COLON  statements
| KEY_CASE KEY_PARL lexpression KEY_PARR KEY_COLON  statements
| /* empty */
;

default: KEY_DEFAULT KEY_PARL lexpression KEY_PARR KEY_COLON  statements
| /* empty */
;



//Πιο αφηρημένες έννοιες

statements: statements statement | statement;

statement: if
| for
| while
| assignment
| switch
| KEY_BREAK KEY_SEMICOLON
| KEY_IDENTIFIER
;

function: funcdeclaration  vardeclaration  statements  KEY_RETURN aexpression  KEY_ENDFUNCTION
| funcdeclaration  vardeclaration  statements  KEY_RETURN KEY_IDENTIFIER  KEY_ENDFUNCTION
;

main: KEY_MAIN  vardeclaration  statements KEY_ENDMAIN ;

program: programtitle funcdeclaration main ;


%%
/*** And finaly, the parser in action ***/

void yyerror(char *s) {
  fprintf(stderr, "Line: %d --> Parser error\n", yylineno);
  fprintf(stderr, "%s\n", s);
}


int main ( int argc, char **argv  )
  {
  ++argv; --argc;
  if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
  else
        yyin = stdin;
  yyout = fopen ( "output", "w" );
  yyparse ();
  return 0;
  }
