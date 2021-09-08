%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotsauce.tab.h"
%}

%option noyywrap

digit [0-9]
non_zero_digit [1-9]
whitespace [\t\v\r]

string ["][a-zA-Z][[:space:]:;,()A-Za-z0-9_.-]*["]

identifier [a-zA-Z_$][a-zA-Z_$0-9]*

escaped_string (\\.|[^])*
number {non_zero_digit}{digit}*|"0"


%%

"+"             {return KEY_PLUS;}
"-"             {return KEY_MIN;}
"*"             {return KEY_MUL;}
"/"             {return KEY_DIV;}
">"             {return KEY_GREATER;}
"<"             {return KEY_LESSER;}
"="             {return KEY_ASSIGN;}
"=="            {return KEY_EQUAL;}
"!="            {return KEY_NOTEQUAL;}
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
"\""            {return KEY_QUOTE;}
"%"             {return KEY_COMMENT;}
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
"\n"            {return KEY_NEWLINE;}
{identifier}    {return KEY_IDENTIFIER;}
{string}        {return KEY_STRING;}
{number}        {return KEY_NUM;}
<<EOF>>         {return KEY_EOF;}
%%

//int main(int argc, char *argv[]) {
//    int token;
//		if(argc>1){
//		  yyin = fopen(argv[1], "r");
//			if (yyin==NULL){
//			   perror ("error open");
//				 return -1;
//			}
//		}
//		do{
//		  token = yylex();

//		}while (token != KEY_EOF);
//
//		fclose(yyin);
//		yyterminate();
//}
