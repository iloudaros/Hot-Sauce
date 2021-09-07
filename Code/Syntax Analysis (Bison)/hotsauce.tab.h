/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOTSAUCE_TAB_H_INCLUDED
# define YY_YY_HOTSAUCE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KEY_PROGRAM = 258,
    KEY_FUNCTION = 259,
    KEY_RETURN = 260,
    KEY_ENDFUNCTION = 261,
    KEY_VARS = 262,
    KEY_CHAR = 263,
    KEY_INT = 264,
    KEY_IDENTIFIER = 265,
    KEY_NUM = 266,
    KEY_NEWLINE = 267,
    KEY_EOF = 268,
    KEY_MAIN = 269,
    KEY_ENDMAIN = 270,
    KEY_WHILE = 271,
    KEY_ENDWHILE = 272,
    KEY_FOR = 273,
    KEY_TO = 274,
    KEY_STEP = 275,
    KEY_ENDFOR = 276,
    KEY_IF = 277,
    KEY_THEN = 278,
    KEY_ELSEIF = 279,
    KEY_ELSE = 280,
    KEY_ENDIF = 281,
    KEY_SWITCH = 282,
    KEY_CASE = 283,
    KEY_DEFAULT = 284,
    KEY_ENDSWITCH = 285,
    KEY_PRINT = 286,
    KEY_COMMENT = 287,
    KEY_BREAK = 288,
    KEY_ASSIGN = 289,
    KEY_CURLYR = 290,
    KEY_CURLYL = 291,
    KEY_BRACKETR = 292,
    KEY_BRACKETL = 293,
    KEY_PARR = 294,
    KEY_PARL = 295,
    KEY_COMMA = 296,
    KEY_SEMICOLON = 297,
    KEY_DOT = 298,
    KEY_COLON = 299,
    KEY_QUOTE = 300,
    KEY_STRING = 301,
    KEY_AND = 302,
    KEY_OR = 303,
    KEY_GREATER = 304,
    KEY_LESSER = 305,
    KEY_EQUAL = 306,
    KEY_NOTEQUAL = 307,
    KEY_MUL = 308,
    KEY_DIV = 309,
    KEY_PLUS = 310,
    KEY_MIN = 311,
    KEY_TYPEDEF = 312,
    KEY_STRUCT = 313,
    KEY_ENDSTRUCT = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOTSAUCE_TAB_H_INCLUDED  */
