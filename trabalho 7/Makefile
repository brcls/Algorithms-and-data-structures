all: main.o arvoreBinaria.o
	@gcc main.o arvoreBinaria.o -o exec
main.o: main.c
	@gcc main.c -c
arvoreBinaria.o: arvoreBinaria.c
	@gcc arvoreBinaria.c -c
run:
	@./exec