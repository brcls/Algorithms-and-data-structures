all: main.o pilha.o
	@gcc main.o pilha.o -o exec
main.o: main.c
	@gcc main.c -c
pilha.o: pilha.c
	@gcc pilha.c -c
run:
	@./exec