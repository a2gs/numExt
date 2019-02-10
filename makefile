CC = gcc
CFLAGS = -g -Wall -std=c11 -D_XOPEN_SOURCE=700

RM = rm -rf

all: clean numExt

numExt:
	$(CC) -o numExt numExt.c $(CFLAGS)

clean:
	-$(RM) numExt
