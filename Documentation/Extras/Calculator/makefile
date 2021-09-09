#NOT READY

all: calc

calc: fb3-1.l fb3-1.y fb3-1.h fb3-1funcs.c
	bison -d -t fb3-1.y
	flex -ofb3-1.lex.c fb3-1.l
	cc -o $@ fb3-1.tab.c fb3-1.lex.c fb3-1funcs.c


clean:
	rm -f fb3-1 fb3-2 \
	fb3-1.lex.c fb3-1.tab.h fb3-1.tab.c fb3-2.tab.c fb3-2.tab.h fb3-2.lex.c a.out
