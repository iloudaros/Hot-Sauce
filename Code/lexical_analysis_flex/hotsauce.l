%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotsauce.tab.h"

static void skip_multiple_line_comment(void);
%}

%option noyywrap
%option yylineno

identifier [a-zA-Z_][a-zA-Z_$0-9]*

digit [0-9]
non_zero_digit [1-9]
number {non_zero_digit}{digit}*|"0"

string_item ([^\n\'\"\\])|([\\].)
string	([']{string_item}*['])|(["]{string_item}*["])

whitespace	[ \t\v\n\f]

%%

^[ ]*\n	   			 {/* Ignore blank lines. */   }
^[\t]*\n   			 {/* Ignore blank lines. */   }
[%].*			     { /*Ignore comments*/        }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]   		 { /*Ignore multiline comments*/}

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
"STRUCT"        {return KEY_STRUCT;}
"TYPEDEF"       {return KEY_TYPEDEF;}
"ENDSTRUCT"			{return KEY_ENDSTRUCT;}

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
";"             {return KEY_SEMICOLON;}
","             {return KEY_COMMA;}
"("             {return KEY_PARL;}
")"             {return KEY_PARR;}
"["             {return KEY_BRACKETL;}
"]"             {return KEY_BRACKETR;}
"/*"            { puts("long comment begins ");
	                    skip_multiple_line_comment();
	                    puts("long comment ends");
								}

\n							{}

{identifier}    {
									yylval.str = strdup(yytext);
				          return KEY_IDENTIFIER;
                }


{string}        {
                  if(strlen(yytext) > 3) return KEY_STRING;
                  else return KEY_CHARACTER;
                }

{number}        {return KEY_NUM;}
{whitespace}    {  }

%%


static void skip_multiple_line_comment(void)
{
  int c;

  for(;;)
  {
    switch(input())
    {
      /* We expect ending the comment first before EOF */
      case EOF:
        fprintf(stderr, "Error unclosed comment, expect */\n");
        exit(-1);
        goto done;
      break;
      /* Is it the end of comment? */
      case '*':
        if((c = input()) == '/') goto done;
        unput(c);
        break;
      default:
        /* skip this character */
        break;
    }
  }

done:
  /* exit entry */ ;
}
