all: main.o treaps.o
	@gcc main.o treaps.o -o exec
main.o: main.c
	@gcc main.c -c
treaps.o: treaps.c
	@gcc treaps.c -c
run:
	@./exec