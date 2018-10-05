
CFLAGS=-Wall --pedantic

trobanslobatobor:	trobanslobatobor.c Makefile
	$(CC) -g -o trobanslobatobor trobanslobatobor.c

clean:
	rm -f trobanslobatobor

