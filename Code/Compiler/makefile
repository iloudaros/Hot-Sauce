#NOT READY


iloudaros: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y
	cp ../Lexical\ Analysis\ \(Flex\)/hotsauce.l ./
	cp ../Syntax\ Analysis\ \(Bison\)/hotsauce.y ./
	cp ../Test\ Code\ \(HotSauce\)/test.hotsauce.txt ./
	cp ../Exec\ Helper/Exec_Helper.c ./ 
	bison -t -d hotsauce.y
	flex -d hotsauce.l
	gcc -c hotsauce.tab.c lex.yy.c
	gcc hotsauce.tab.o lex.yy.o -o hotsauce
	gcc -o Exec_Helper Exec_Helper.c
	./Exec_Helper




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
	rm -f Exec_Helper
	rm -f output
	rm -f Exec_Helper.c
	rm -f hotsauce.tab.o
	rm -f lex.yy.o
	rm -f test.hotsauce.txt
	
