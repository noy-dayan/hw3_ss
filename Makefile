all: txtfind isort txtfind.o isort.o

txtfind: txtfind.o
	gcc -Wall -o txtfind txtfind.o

txtfind.o: txtfind.c
	gcc -Wall -c txtfind.c

isort: isort.o
	gcc -Wall -o isort isort.o

isort.o: isort.c
	gcc -Wall -c isort.c


clean:
	rm *.o txtfind isort
