#NOT READY


iloudaros: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y
	cp ../Lexical\ Analysis\ \(Flex\)/hotsauce.l ./
	cp ../Syntax\ Analysis\ \(Bison\)/hotsauce.y ./
	cp ../Test\ Code\ \(HotSauce\)/test.hotsauce.txt ./
	bison -d hotsauce.y
	flex hotsauce.l
	gcc -c hotsauce.tab.c lex.yy.c
	gcc hotsauce.tab.o lex.yy.o -o hotsauce




itsikelis: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y
	cp ../Lexical\ Analysis\ \(Flex\)/hotsauce.l ./
	cp ../Syntax\ Analysis\ \(Bison\)/hotsauce.y ./
	bison -d hotsauce.y
	flex hotsauce.l




azekyria: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y





ckratimenou: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y

clean:
	rm -f hotsauce.l
	rm -f hotsauce.y
	rm -f hotsauce.tab.c
	rm -f hotsauce.tab.h
	rm -f lex.yy.c
	rm -f hotsauce
