test:utilisateur.o main.o
	gcc utilisateur.o main.o -o test
main.o:main.c
	gcc -c main.c

utilisateur.o:utilisateur.c
	gcc -c utilisateur.c
