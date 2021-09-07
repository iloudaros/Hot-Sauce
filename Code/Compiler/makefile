#NOT READY

all: hotsauce

hotsauce: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y
	cp ../Lexical\ Analysis\ \(Flex\)/hotsauce.l ./
	cp ../Syntax\ Analysis\ \(Bison\)/hotsauce.y ./
	bison -d hotsauce.y
	flex hotsauce.l
	gcc-11 -o hotsauce hotsauce.tab.c lex.yy.c


clean:
	rm -f hotsauce.l
	rm -f hotsauce.y
	rm -f hotsauce.tab.c
	rm -f hotsauce.tab.h
	rm -f lex.yy.c
	rm -f hotsauce
