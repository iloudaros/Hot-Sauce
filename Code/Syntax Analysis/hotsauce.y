/***** The Parser of the greatest computer language of all time, HotSauce *****/

%{
#include <stdio.h>
#include <math.h>
void yyerror(char *);
extern FILE *yyin;
extern FILE *yyout;
int yylex();

%}

/*** Here, we declare the tokens ***/
%token KEY_PROGRAM
%token KEY_FUNCTION KEY_RETURN KEY_ENDFUNCTION
%token KEY_VARS KEY_CHAR KEY_INT VAR_NAME
%token KEY_LETTER KEY_NUM KEY_WS
%token KEY_EOF
%token KEY_MAIN KEY_ENDMAIN
%token KEY_WHILE KEY_ENDWHILE
%token KEY_FOR KEY_TO KEY_STEP KEY_ENDFOR
%token KEY_AND KEY_OR
%token KEY_IF KEY_THEN KEY_ELSEIF KEY_ELSE KEY_ENDIF
%token KEY_SWITCH KEY_CASE KEY_DEFAULT KEY_ENDSWITCH
%token KEY_PRINT KEY_COMMEND
%token KEY_BREAK
%token KEY_ASSIGN
%token KEY_CURLYR KEY_CURLYL KEY_BRACKETR KEY_BRACKETL KEY_PARR KEY_PARL KEY_COMMA KEY_SEMICOLON KEY_DOT KEY_COLON
%left KEY_LOR
%left KEY_LAND
%left KEY_GREATER KEY_LESS KEY_EQUAL KEY_NOTEQUAL
%left KEY_PLUS KEY_MIN
%left KEY_MUL KEY_DIV
%left KEY_POWER






%%
/*** Here, you can see the rules ***/

//Βασικές Έννοιες
punctuation: KEY_CURLYR
|KEY_CURLYL
|KEY_BRACKETR
|KEY_BRACKETL
|KEY_PARR
|KEY_PARL
|KEY_COMMA
|KEY_SEMICOLON
|KEY_DOT
|KEY_COLON
;

string: KEY_LETTER string
| KEY_NUM string
| punctuation string
| KEY_LETTER
| KEY_NUM
;

type: KEY_CHAR
| KEY_INT
;

variable: type VAR_NAME ";";

array: variable "[" KEY_NUM "]" ;

variables: variable
| array
| variables variable
| variables array
;

aoperator:  KEY_PLUS
| KEY_MIN
| KEY_MUL
| KEY_DIV
| KEY_POWER
;

loperator: KEY_LOR
| KEY_LAND
| KEY_GREATER
| KEY_LESS
| KEY_EQUAL
| KEY_NOTEQUAL
;



//Δηλώσεις
programtitle: KEY_PROGRAM string "\n" ;

funcdeclaration: KEY_FUNCTION string "(" variables ")" ";" ;

vardeclaration: KEY_VARS variables;



//Εντολές
aexpression:
;

lexpression:
;

assignmnet: VAR_NAME "=" keynumber ";"
|VAR_NAME "=" keynumber ";"
;

printstatement: KEY_PRINT "(" string ")" ";"
| KEY_PRINT "(" string "[" VAR_NAME "]" ")" ";"
;



//Δομές Επανάληψης
while: KEY_WHILE "(" lexpression ")" "\n" code "\n" KEY_ENDWHILE ;

for: KEY_FOR KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM "\n" code "\n" KEY_ENDFOR ;



//Δομές Απόφασης
if: KEY_IF "(" lexpression ")" KEY_THEN code elseif else KEY_ENDIF;

elseif: elseif KEY_ELSEIF "(" lexpression ")" code
| KEY_ELSEIF "(" lexpression ")" code
| /* empty */
;

else: KEY_ELSE "(" lexpression ")" code
| /* empty */
;

switch: KEY_SWITCH "(" lexpression ")" "\n" case default KEY_ENDSWITCH;

case: case KEY_CASE "(" lexpression ")" code
| KEY_CASE "(" lexpression ")" code
| /* empty */
;

default: KEY_DEFAULT "(" lexpression ")" code
| /* empty */
;



//Σχόλια
commend: KEY_COMMEND string;

//Πιο αφηρημένες έννοιες
code:  statement | LBRACE statements RBRACE ;

statements: statements statement | statement;

statement: if
| for
| while
| assigment
| switch
| commend
| KEY_BREAK
;

function: funcdeclaration "\n" vardeclaration "\n" code "\n" KEY_RETURN aexpression "\n" KEY_ENDFUNCTION
| funcdeclaration "\n" vardeclaration "\n" code "\n" KEY_RETURN KEY_LETTER "\n" KEY_ENDFUNCTION
;

main: KEY_MAIN "\n" vardeclaration "\n" code KEY_ENDMAIN ;

program: programtitle funcdeclaration main ;


%%
/*** And finaly, the parser in action ***/

void yyerror(char *s) {
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
