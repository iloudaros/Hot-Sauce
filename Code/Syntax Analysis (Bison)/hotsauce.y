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
%token KEY_IDENTIFIER KEY_NUM KEY_NEWLINE
%token KEY_EOF
%token KEY_MAIN KEY_ENDMAIN
%token KEY_MAIN KEY_STARTMAIN
%token KEY_WHILE KEY_ENDWHILE
%token KEY_FOR KEY_TO KEY_STEP KEY_ENDFOR
%token KEY_AND KEY_OR
%token KEY_IF KEY_THEN KEY_ELSEIF KEY_ELSE KEY_ENDIF
%token KEY_SWITCH KEY_CASE KEY_DEFAULT KEY_ENDSWITCH
%token KEY_PRINT KEY_COMMENT
%token KEY_BREAK
%token KEY_ASSIGN
%token KEY_CURLYR KEY_CURLYL KEY_BRACKETR KEY_BRACKETL KEY_PARR KEY_PARL KEY_COMMA KEY_SEMICOLON KEY_DOT KEY_COLON
%left KEY_LOR
%left KEY_LAND
%left KEY_GREATER KEY_LESS KEY_EQUAL KEY_NOTEQUAL
%left KEY_PLUS KEY_MIN
%left KEY_MUL KEY_DIV
%left KEY_POWER


%token KEY_TYPEDEF
%token KEY_STRUCT        
%token KEY_ENDSTRUCT     


%%
/*** Here, you can see the rules ***/

//Declarations
program: 
      KEY_PROGRAM KEY_IDENTIFIER KEY_NEWLINE struct_decl functions main KEY_EOF;
	  
/*** start of structs ***/	  

struct_decl:
	  KEY_STRUCT KEY_IDENTIFIER variables KEY_ENDSTRUCT KEY_NEWLINE;

typedef_decl: 
	  KEY_TYPEDEF KEY_IDENTIFIER KEY_STRUCT variables KEY_ENDSTRUCT KEY_SEMICOLON KEY_NEWLINE;
	  
struct_decls: 
	  struct_decl
	  | struct_decl struct_decls
	  | typedef_decl
	  | typedef_decl struct_decls
	  ;
	  
struct_call: 
	  KEY_STRUCT KEY_IDENTIFIER;

/*** FUNCTIONS ***/

functions:
      function
      | functions function;

function:
      //empty
      | KEY_FUNCTION KEY_IDENTIFIER KEY_PARL parameters KEY_PARR KEY_NEWLINE body KEY_RETURN return_val KEY_SEMICOLON KEY_ENDFUNCTION;

parameters:
      //empty
      | KEY_IDENTIFIER
      | parameters KEY_COMMA KEY_IDENTIFIER
	  ;

return_val:
      KEY_IDENTIFIER
      | KEY_NUMBER
	  ;

body:
      variables
      | variables commands
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
      KEY_VARS KEY_INT identifier_list KEY_SEMICOLON;

char:
      KEY_VARS KEY_CHAR identifier_list KEY_SEMICOLON;

identifier_list: 
      identifier
      | identifier_list KEY_COMMA identifier
	  ;
      
int_array:
      KEY_VARS KEY_INT KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON;

char_array: 
      KEY_VARS KEY_CHAR KEY_IDENTIFIER KEY_BRACKETL KEY_NUM KEY_BRACKETR KEY_SEMICOLON;


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
      | comment
	  ;
	  
assignment:
      KEY_IDENTIFIER KEY_ASSIGN expression KEY_SEMICOLON
      | KEY_IDENTIFIER KEY_ASSIGN KEY_NUMBER KEY_SEMICOLON
      ;

expression:
      NUMBER { $$=$1; }
      | expression KEY_PLUS expression {$$ = $1 + $3;}
      | expression KEY_MINUS expression {$$ = $1 - $3;}
      | expression KEY_MUL expression {$$ = $1 * $3;}
      | expression KEY_DIV expression {$$ = $1 / $3;}
      | KEY_MINUS expression %prec KEY_NEG {$$ = -$2;}
      | KEY_PARL expression KEY_PARR {$$ = $2;}
      | KEY_IDENTIFIER KEY_PARL parameters KEY_PARR KEY_SEMICOLON
      ;

	  

//bis hier alles gut

main:
	  KEY_STARTMAIN KEY_NEWLINE body KEY_ENDMAIN KEY_NEWLINE;


/*** IF ***/


if_stmt: 
	  if KEY_ENDIF
	  | if else KEY_ENDIF
	  | if else_ifs KEY_ENDIF
	  | if else_ifs else KEY_ENDIF
	  ;

if: 
	  KEY_IF KEY_BRACKETL expression KEY_BRACKETR KEY_THEN statement;
	  
else: 
	  KEY_ELSE statement;

else_ifs:
	  else_ifs else_if
	  | elseif
	  ;
	  
else_if: 
	  KEY_ELSEIF KEY_BRACKETL expression KEY_BRACKETR KEY_THEN statement;
	  

/*** SWITCH ***/  
	  

switch_stmt:
	  switch cases KEY_ENDSWITCH
	  | switch cases default KEY_ENDSWITCH
	  ;
	  
switch: 
	  KEY_SWITCH KEY_BRACKETR expression KEY_BRACKETR;
	  
cases:
	  cases case
	  | case
	  ;
	  
case: 
	  KEY_CASE KEY_BRACKETR expression KEY_BRACKETR KEY_COLON statement;
	  

default: 
	  KEY_DEFAULT KEY_COLON statement;
	  

/*** WHILE ***/

while: 
	  KEY_WHILE KEY_BRACKETL expression KEY_BRACKETR statement KEY_ENDWHILE;


/*** FOR ***/

for: 
	  KEY_FOR identifier KEY_COLON KEY_EQUAL int KEY_TO int KEY_STEP int statement KEY_ENDFOR;
	
	  

	  








loperator: KEY_LOR
| KEY_LAND
| KEY_GREATER
| KEY_LESS
| KEY_EQUAL
| KEY_NOTEQUAL
;



lexpression: aexpression
| lexpression loperator lexpression
| KEY_PARL lexpression KEY_PARR
;

assignment: KEY_VARNAME KEY_ASSIGN aexpression KEY_SEMICOLON /* !!! Αν δημιουργήσει πρόβλημα, βάζουμε KEY_NUM*/
| KEY_VARNAME KEY_ASSIGN KEY_CHAR KEY_SEMICOLON
;

printstatement: KEY_PRINT KEY_PARL string KEY_PARR KEY_SEMICOLON
| KEY_PRINT KEY_PARL string KEY_BRACKETL KEY_VARNAME KEY_BRACKETR KEY_PARR KEY_SEMICOLON
;

//Δομές Επανάληψης
while: KEY_WHILE KEY_PARL lexpression KEY_PARR KEY_NEWLINE code KEY_NEWLINE KEY_ENDWHILE ;

for: KEY_FOR KEY_NUM KEY_TO KEY_NUM KEY_STEP KEY_NUM KEY_NEWLINE code KEY_NEWLINE KEY_ENDFOR ;

//Δομές Απόφασης
if: KEY_IF KEY_PARL lexpression KEY_PARR KEY_THEN KEY_NEWLINE code elseif else KEY_ENDIF;

elseif: elseif KEY_ELSEIF KEY_PARL lexpression KEY_PARR KEY_NEWLINE code
| KEY_ELSEIF KEY_PARL lexpression KEY_PARR KEY_NEWLINE code
| /* empty */
;

else: KEY_ELSE KEY_PARL lexpression KEY_PARR KEY_NEWLINE code
| /* empty */
;

switch: KEY_SWITCH KEY_PARL lexpression KEY_PARR KEY_NEWLINE case default KEY_ENDSWITCH;

case: case KEY_CASE KEY_PARL lexpression KEY_PARR KEY_COLON KEY_NEWLINE code
| KEY_CASE KEY_PARL lexpression KEY_PARR KEY_COLON KEY_NEWLINE code
| /* empty */
;

default: KEY_DEFAULT KEY_PARL lexpression KEY_PARR KEY_COLON KEY_NEWLINE code
| /* empty */
;

//Σχόλια
comment: KEY_COMMENT string;

//Πιο αφηρημένες έννοιες
code:  statement | KEY_BRACKETL statements KEY_BRACKETR ;

statements: statements statement | statement;

statement: if  /* !!! Προσοχή, υπάρχει περίπτωση να καταστρατηγείται το LR(1)*/
| for
| while
| assignment
| switch
| comment
| KEY_BREAK
;

function: funcdeclaration KEY_NEWLINE vardeclaration KEY_NEWLINE code KEY_NEWLINE KEY_RETURN aexpression KEY_NEWLINE KEY_ENDFUNCTION
| funcdeclaration KEY_NEWLINE vardeclaration KEY_NEWLINE code KEY_NEWLINE KEY_RETURN KEY_IDENTIFIER KEY_NEWLINE KEY_ENDFUNCTION
;

main: KEY_MAIN KEY_NEWLINE vardeclaration KEY_NEWLINE code KEY_ENDMAIN ;


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
