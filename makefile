dragon-work-:election.o main.o	
	gcc election.o main.o -o dragon-work-
main.o:main.c
	gcc -c main.c
fonction.o:fonction.c
	gcc -c election.c
