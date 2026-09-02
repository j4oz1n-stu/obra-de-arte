all: compilar run
compilar:
	gcc sources/main.c sources/quadro.c -o sources/run
run:
	./sources/run
