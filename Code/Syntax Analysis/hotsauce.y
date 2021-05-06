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
%token KEY_VARS KEY_CHAR KEY_INT
%token KEY_LETTER KEY_NUM KEY_WS
%token KEY_EOF
%token KEY_MAIN KEY_ENDMAIN
%token KEY_WHILE KEY_ENDWHILE
%token KEY_FOR KEY_TO KEY_STEP KEY_ENDFOR
%token KEY_AND KEY_OR
%token KEY_IF KEY_THEN KEY_ELSEIF KEY_ELSE KEY_ENDIF
%token KEY_SWITCH KEY_CASE KEY_DEFAULT KEY_ENDSWITCH
%token KEY_PRINT
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
