prog:electorale.o main.o
	gcc electorale.o main.o -o prog
main.o:main.c
	gcc -c main.c
electorale.o:electorale.c
	gcc -c electorale.c
