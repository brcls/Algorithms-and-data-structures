all: main.o skipList.o
	@gcc main.o skipList.o -o exec
main.o: main.c
	@gcc main.c -c
skipList.o: skipList.c
	@gcc skipList.c -c
run:
	@./exec