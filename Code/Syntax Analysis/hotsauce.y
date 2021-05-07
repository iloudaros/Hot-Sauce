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

variable: type VAR_NAME KEY_SEMICOLON;

array: variable KEY_BRACKETL KEY_NUM KEY_BRACKETR ;

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
programtitle: KEY_PROGRAM string NEWLINE ;

funcdeclaration: KEY_FUNCTION string KEY_PARL variables KEY_PARR KEY_SEMICOLON ;

vardeclaration: KEY_VARS variables;



//Εντολές
aexpression: aexpression aoperator aexpression
| KEY_PARL aexpression KEY_PARR
| KEY_NUM
| VAR_NAME
| KEY_MIN aexpression
;

lexpression: aexpression
| lexpression loperator lexpression
| KEY_PARL lexpression KEY_PARR
;

assignmnet: VAR_NAME KEY_ASSIGN keynumber KEY_SEMICOLON
|VAR_NAME KEY_ASSIGN keynumber KEY_SEMICOLON
;

printstatement: KEY_PRINT KEY_PARL string KEY_PARR KEY_SEMICOLON
| KEY_PRINT KEY_PARL string KEY_BRACKETL VAR_NAME KEY_BRACKETR KEY_PARR KEY_SEMICOLON
;



//Δομές Επανάληψης
while: KEY_WHILE KEY_PARL lexpression KEY_PARR NEWLINE code NEWLINE KEY_ENDWHILE ;

for: KEY_FOR KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM NEWLINE code NEWLINE KEY_ENDFOR ;



//Δομές Απόφασης
if: KEY_IF KEY_PARL lexpression KEY_PARR KEY_THEN code elseif else KEY_ENDIF;

elseif: elseif KEY_ELSEIF KEY_PARL lexpression KEY_PARR code
| KEY_ELSEIF KEY_PARL lexpression KEY_PARR code
| /* empty */
;

else: KEY_ELSE KEY_PARL lexpression KEY_PARR code
| /* empty */
;

switch: KEY_SWITCH KEY_PARL lexpression KEY_PARR NEWLINE case default KEY_ENDSWITCH;

case: case KEY_CASE KEY_PARL lexpression KEY_PARR code
| KEY_CASE KEY_PARL lexpression KEY_PARR code
| /* empty */
;

default: KEY_DEFAULT KEY_PARL lexpression KEY_PARR code
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

function: funcdeclaration NEWLINE vardeclaration NEWLINE code NEWLINE KEY_RETURN aexpression NEWLINE KEY_ENDFUNCTION
| funcdeclaration NEWLINE vardeclaration NEWLINE code NEWLINE KEY_RETURN KEY_LETTER NEWLINE KEY_ENDFUNCTION
;

main: KEY_MAIN NEWLINE vardeclaration NEWLINE code KEY_ENDMAIN ;

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
