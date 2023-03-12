main.o:
	gcc main.c -o random -s -g3

install:
	-rm "/usr/local/bin/random"
	ln -s "`pwd`/random" "/usr/local/bin/random"
