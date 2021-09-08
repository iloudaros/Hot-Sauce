

all: giannis




giannis: hotsauce.l hotsauce.y 
flex -d hotsauce.l
bison -d -t hotsauce.y
gcc -c hotsauce.tab.c lex.yy.c
gcc hotsauce.tab.o lex.yy.o -o parser
