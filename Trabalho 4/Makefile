all: main.o lista.o
	@gcc main.o lista.o -o exec
main.o: main.c
	@gcc main.c -c
lista.o: lista.c
	@gcc lista.c -c
run:
	@./exec