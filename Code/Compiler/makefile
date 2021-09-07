#NOT READY

all: hotsauce

hotsauce: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y
	cp ../Lexical\ Analysis\ \(Flex\)/hotsauce.l ./
	cp ../Syntax\ Analysis\ \(Bison\)/hotsauce.y ./
	bison -d hotsauce.y
	flex hotsauce.l

clear :
	rm -f hotsauce.l
	rm -f hotsauce.y
	rm -f hotsauce.tab.c
	rm -f hotsauce.tab.h
	rm -f lex.yy.c
	
	

	
