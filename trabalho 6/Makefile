all: main.o grandesNum.o
	@gcc main.o grandesNum.o -o exec
main.o: main.c
	@gcc main.c -c
grandesNum.o: grandesNum.c
	@gcc grandesNum.c -c
run:
	@./exec