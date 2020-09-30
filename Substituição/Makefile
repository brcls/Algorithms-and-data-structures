all: main.o substring.o
	@gcc main.o substring.o -o sub
main.o: main.c
	@gcc main.c -c
substring.o: substring.c
	@gcc substring.c -c
run:
	@./sub