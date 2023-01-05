all: txtfind isort txtfind.o isort.o

txtfind: txtfind.o
	gcc -o txtfind txtfind.o

txtfind.o: txtfind.c
	gcc -c txtfind.c

isort: isort.o
	gcc -o isort isort.o

isort.o: isort.c
	gcc -c isort.c


clean:
	rm *.o txtfind isort