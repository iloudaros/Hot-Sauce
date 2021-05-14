/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KEY_PROGRAM = 258,
     KEY_FUNCTION = 259,
     KEY_RETURN = 260,
     KEY_ENDFUNCTION = 261,
     KEY_VARS = 262,
     KEY_CHAR = 263,
     KEY_INT = 264,
     KEY_VARNAME = 265,
     KEY_LETTER = 266,
     KEY_NUM = 267,
     KEY_WS = 268,
     KEY_NEWLINE = 269,
     KEY_EOF = 270,
     KEY_MAIN = 271,
     KEY_ENDMAIN = 272,
     KEY_WHILE = 273,
     KEY_ENDWHILE = 274,
     KEY_FOR = 275,
     KEY_TO = 276,
     KEY_STEP = 277,
     KEY_ENDFOR = 278,
     KEY_AND = 279,
     KEY_OR = 280,
     KEY_IF = 281,
     KEY_THEN = 282,
     KEY_ELSEIF = 283,
     KEY_ELSE = 284,
     KEY_ENDIF = 285,
     KEY_SWITCH = 286,
     KEY_CASE = 287,
     KEY_DEFAULT = 288,
     KEY_ENDSWITCH = 289,
     KEY_PRINT = 290,
     KEY_COMMENT = 291,
     KEY_BREAK = 292,
     KEY_ASSIGN = 293,
     KEY_CURLYR = 294,
     KEY_CURLYL = 295,
     KEY_BRACKETR = 296,
     KEY_BRACKETL = 297,
     KEY_PARR = 298,
     KEY_PARL = 299,
     KEY_COMMA = 300,
     KEY_SEMICOLON = 301,
     KEY_DOT = 302,
     KEY_COLON = 303,
     KEY_LOR = 304,
     KEY_LAND = 305,
     KEY_NOTEQUAL = 306,
     KEY_EQUAL = 307,
     KEY_LESS = 308,
     KEY_GREATER = 309,
     KEY_MIN = 310,
     KEY_PLUS = 311,
     KEY_DIV = 312,
     KEY_MUL = 313,
     KEY_POWER = 314
   };
#endif
/* Tokens.  */
#define KEY_PROGRAM 258
#define KEY_FUNCTION 259
#define KEY_RETURN 260
#define KEY_ENDFUNCTION 261
#define KEY_VARS 262
#define KEY_CHAR 263
#define KEY_INT 264
#define KEY_VARNAME 265
#define KEY_LETTER 266
#define KEY_NUM 267
#define KEY_WS 268
#define KEY_NEWLINE 269
#define KEY_EOF 270
#define KEY_MAIN 271
#define KEY_ENDMAIN 272
#define KEY_WHILE 273
#define KEY_ENDWHILE 274
#define KEY_FOR 275
#define KEY_TO 276
#define KEY_STEP 277
#define KEY_ENDFOR 278
#define KEY_AND 279
#define KEY_OR 280
#define KEY_IF 281
#define KEY_THEN 282
#define KEY_ELSEIF 283
#define KEY_ELSE 284
#define KEY_ENDIF 285
#define KEY_SWITCH 286
#define KEY_CASE 287
#define KEY_DEFAULT 288
#define KEY_ENDSWITCH 289
#define KEY_PRINT 290
#define KEY_COMMENT 291
#define KEY_BREAK 292
#define KEY_ASSIGN 293
#define KEY_CURLYR 294
#define KEY_CURLYL 295
#define KEY_BRACKETR 296
#define KEY_BRACKETL 297
#define KEY_PARR 298
#define KEY_PARL 299
#define KEY_COMMA 300
#define KEY_SEMICOLON 301
#define KEY_DOT 302
#define KEY_COLON 303
#define KEY_LOR 304
#define KEY_LAND 305
#define KEY_NOTEQUAL 306
#define KEY_EQUAL 307
#define KEY_LESS 308
#define KEY_GREATER 309
#define KEY_MIN 310
#define KEY_PLUS 311
#define KEY_DIV 312
#define KEY_MUL 313
#define KEY_POWER 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

