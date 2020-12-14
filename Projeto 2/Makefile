all: main.o rubronegra.o
	@gcc main.o rubronegra.o -o exec
main.o: main.c
	@gcc main.c -c
rubronegra.o: rubronegra.c
	@gcc rubronegra.c -c
run:
	@./exec