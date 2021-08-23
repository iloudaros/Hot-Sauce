%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Syntax\ Analysis\ \(Bison\)/hotsauce.tab.h"
%}

%option noyywrap
%option yylineno

identifier [a-zA-Z_$][a-zA-Z_$0-9]*  //used for all non-reserved words
digit [0-9]
non_zero_digit [1-9]
whitespace [\t\v\r]

escaped_string (\\.|[^\"])*
number {non_zero_digit}{digit}*|"0"


%%

"+"             {printtokens(KEY_PLUS); return KEY_PLUS;}
"-"             {printtokens(KEY_MIN); return KEY_MIN;}
"*"             {printtokens(KEY_MUL); return KEY_MUL;}
"/"             {printtokens(KEY_DIV); return KEY_DIV;}
"^"             {printtokens(KEY_POWER); return KEY_POWER;}
">"             {printtokens(KEY_GREATER); return KEY_GREATER;}
"<"             {printtokens(KEY_LESS); return KEY_LESS;}
"="             {printtokens(KEY_ASSIGN); return KEY_ASSIGN;}
"=="            {printtokens(KEY_EQUAL); return KEY_EQUAL;}
"!="            {printtokens(KEY_NOTEQUAL); return KEY_NOTEQUAL;}
"&&"            {printtokens(KEY_LAND); return KEY_LAND;}
"||"            {printtokens(KEY_LOR); return KEY_LOR;}
":"             {printtokens(KEY_COLON); return KEY_COLON;}
"."             {printtokens(KEY_DOT); return KEY_DOT;}
";"             {printtokens(KEY_SEMICOLON); return KEY_SEMICOLON;}
","             {printtokens(KEY_COMMA); return KEY_COMMA;}
"("             {printtokens(KEY_PARL); return KEY_PARL;}
")"             {printtokens(KEY_PARR); return KEY_PARR;}
"["             {printtokens(KEY_BRACKETL); return KEY_BRACKETL;}
"]"             {printtokens(KEY_BRACKETR); return KEY_BRACKETR;}
"{"             {printtokens(KEY_CURLYL); return KEY_CURLYL;}
"}"             {printtokens(KEY_CURLYR); return KEY_CURLYR;}
"%"             {printtokens(KEY_COMMENT); return KEY_COMMENT;}
"PROGRAM"       {printtokens(KEY_PROGRAM); return KEY_PROGRAM;}
"FUNCTION"      {printtokens(KEY_FUNCTION); return KEY_FUNCTION;}
"END_FUNCTION"  {printtokens(KEY_ENDFUNCTION); return KEY_ENDFUNCTION;}
"VARS"          {printtokens(KEY_VARS); return KEY_VARS;}
"CHAR"          {printtokens(KEY_CHAR); return KEY_CHAR;}
"INTEGER"       {printtokens(KEY_INT); return KEY_INT;}
"RETURN"        {printtokens(KEY_RETURN); return KEY_RETURN;}
"STARTMAIN"     {printtokens(KEY_MAIN); return KEY_MAIN;}
"ENDMAIN"       {printtokens(KEY_ENDMAIN); return KEY_ENDMAIN;}
"WHILE"         {printtokens(KEY_WHILE); return KEY_WHILE;}
"ENDWHILE"      {printtokens(KEY_ENDWHILE); return KEY_ENDWHILE;}
"AND"           {printtokens(KEY_AND); return KEY_AND;}
"OR"            {printtokens(KEY_OR); return KEY_OR;}
"FOR"           {printtokens(KEY_FOR); return KEY_FOR;}
"TO"            {printtokens(KEY_TO); return KEY_TO;}
"STEP"          {printtokens(KEY_STEP); return KEY_STEP;}
"ENDFOR"        {printtokens(KEY_ENDFOR); return KEY_ENDFOR;}
"IF"            {printtokens(KEY_IF); return KEY_IF;}
"THEN"          {printtokens(KEY_THEN); return KEY_THEN;}
"ELSEIF"        {printtokens(KEY_ELSEIF); return KEY_ELSEIF;}
"ELSE"          {printtokens(KEY_ELSE); return KEY_ELSE;}
"ENDIF"         {printtokens(KEY_ENDIF); return KEY_ENDIF;}
"SWITCH"        {printtokens(KEY_SWITCH); return KEY_SWITCH;}
"CASE"          {printtokens(KEY_CASE); return KEY_CASE;}
"DEFAULT"       {printtokens(KEY_DEFAULT); return KEY_DEFAULT;}
"ENDSWITCH"     {printtokens(KEY_ENDSWITCH); return KEY_ENDSWITCH;}
"PRINT"         {printtokens(KEY_PRINT); return KEY_PRINT;}
"BREAK"         {printtokens(KEY_BREAK); return KEY_BREAK;}
"\n"            {printtokens(KEY_NEWLINE); return KEY_NEWLINE;}
{identifier}    {printtokens(KEY_IDENTIFIER); return KEY_IDENTIFIER;}
{letter}        {printtokens(KEY_LETTER); return KEY_LETTER;}
{number}        {printtokens(KEY_NUMBER); return KEY_NUMBER;}
<<EOF>>         {printtokens(KEY_EOF); return KEY_EOF;}
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
