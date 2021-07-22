all: program

program: main.o fila_pacientes.o
	gcc main.o fila_pacientes.o -lm -o program.out

fila_dina.o: fila_pacientes.c fila_pacientes.h
	gcc -c fila_pacientes.c

main.o: main.c fila_pacientes.h
	gcc -c main.c

clear:
	rm -rf *.o program.out
