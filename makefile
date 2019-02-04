all: clean numExt

numExt:
	cc -o numExt numExt.c -Wall -std=c11

clean:
	-rm numExt
