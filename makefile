all: clean numExt

numExt:
	cc -o numExt numExt.c -Wall

clean:
	-rm numExt
