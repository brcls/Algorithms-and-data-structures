all: main.o backward.o
	@gcc main.o backward.o -o exec
main.o: main.c
	@gcc main.c -c
backward.o: backward.c
	@gcc backward.c -c
run:
	@./exec