all: main.o fila.o
	@gcc main.o fila.o -o exec
main.o: main.c
	@gcc main.c -c
fila.o: fila.c
	@gcc fila.c -c
run:
	@./exec