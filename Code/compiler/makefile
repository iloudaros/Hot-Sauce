#NOT READY


iloudaros: ../lexical_analysis_flex/hotsauce.l ../syntax_analysis_bison/hotsauce.y
	cp ../lexical_analysis_flex/hotsauce.l ./
	cp ../syntax_analysis_bison/hotsauce.y ./
	cp ../test_code/test.hotsauce.txt ./
	cp ../exec_helper/exec_helper.c ./
	bison -d hotsauce.y
	flex -d hotsauce.l
	gcc -c hotsauce.tab.c lex.yy.c
	gcc hotsauce.tab.o lex.yy.o -o hotsauce
	gcc -o exec_helper exec_helper.c
	./Exec_Helper




itsikelis: ../lexical_analysis_flex/hotsauce.l ../syntax_analysis_bison/hotsauce.y
	cp ../lexical_analysis_flex/hotsauce.l ./
	cp ../syntax_analysis_bison/hotsauce.y ./
	cp ../test_code/test.hotsauce.txt ./
	cp ../exec_helper/exec_helper.c ./
	bison -t -d hotsauce.y
	flex hotsauce.l
	gcc -c hotsauce.tab.c lex.yy.c
	gcc hotsauce.tab.o lex.yy.o -o hotsauce
	gcc -o exec_helper exec_helper.c
	./exec_helper

azekyria: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y





ckratimenou: ../Lexical\ Analysis\ (Flex)/hotsauce.l ../Syntax\ Analysis\ (Bison)/hotsauce.y

clean:
	rm -f hotsauce.l
	rm -f hotsauce.y
	rm -f hotsauce.tab.c
	rm -f hotsauce.tab.h
	rm -f lex.yy.c
	rm -f hotsauce
	rm -f exec_helper
	rm -f output
	rm -f exec_helper.c
	rm -f hotsauce.tab.o
	rm -f lex.yy.o
	rm -f test.hotsauce.txt
