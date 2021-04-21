%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap
%option yylineno


digit [0-9]
letter [a-zA-Z]
ws [\t\n\r]

boolean ("True"|"False")
escaped_string (\\.|[^\"])*

num {digit}+
string {letter}+
alphanumeric ({string}|{num})*
float {num}"."{num}

%%

"+"             {return KEY_PLUS;}
"-"             {return KEY_MIN;}
"*"             {return KEY_MUL;}
"/"             {return KEY_DIV;}
"^"             {return KEY_POWER;}
"="             {return KEY_EQUAL;}
"!="            {return KEY_NOTEQUAL;}
"&&"            {return KEY_LAND;}
"||"            {return KEY_LOR;}
":"             {return KEY_COLON;}
"."             {return KEY_DOT;}
";"             {return KEY_SEMICOLON;}
","             {return KEY_COMMA;}
"("             {return KEY_PARL;}
")"             {return KEY_PARR;}
"["             {return KEY_BRACKETL;}
"]"             {return KEY_BRACKETR;}
"{"             {return KEY_CURLYL;}
"}"             {return KEY_CURLYR;}
"PROGRAM"       {return KEY_PROGRAM;}
"FUNCTION"      {return KEY_FUNCTION;}
"END_FUNCTION"  {return KEY_ENDFUNCTION;}
"VARS"          {return KEY_VARS;}
"CHAR"          {return KEY_CHAR;}
"INTEGER"       {return KEY_INT;}
"RETURN"        {return KEY_RETURN;}
"STARTMAIN"     {return KEY_MAIN;}
"ENDMAIN"       {return KEY_ENDMAIN;}
"WHILE"         {return KEY_WHILE;}
"ENDWHILE"      {return KEY_ENDWHILE;}
"AND"           {return KEY_AND;}
"OR"            {return KEY_OR;}
"FOR"           {return KEY_FOR;}
"TO"            {return KEY_TO;}
"STEP"          {return KEY_STEP;}
"ENDFOR"        {return KEY_ENDFOR;}
"IF"            {return KEY_IF;}
"THEN"          {return KEY_THEN;}
"ELSEIF"        {return KEY_ELSEIF;}
"ELSE"          {return KEY_ELSE;}
"ENDIF"         {return KEY_ENDIF;}
"SWITCH"        {return KEY_SWITCH;}
"CASE"          {return KEY_CASE;}
"DEFAULT"       {return KEY_DEFAULT;}
"ENDSWITCH"     {return KEY_ENDSWITCH;}
"PRINT"         {return KEY_PRINT;}
"BREAK"         {return KEY_BREAK;}
{boolean}       {return KEY_BOOLEAN;}
{letter}+       {return KEY_LETTER;}
{num}           {return KEY_NUM;}
{num}"."{num}	        {return KEY_FLOAT;}
{alphanumeric}  {return KEY_ALPHANUM;}
{ws}            {return KEY_WS;}
<<EOF>>         {return KEY_EOF;}
%%

int main(int argc, char *argv[]) {
    int token;
		if(argc>1){
		  yyin = fopen(argv[1], "r");
			if (yyin==NULL){
			   perror ("error open");
				 return -1;
			}
		}
		do{
		  token = yylex();

		}while (token != KEY_EOF);

		fclose(yyin);
		yyterminate();
}

void printtokens(int tokennum){
  prtintf("Token found \'%s\' (%d) at line %d \n", yytext, tokennum, yylineno);
}
