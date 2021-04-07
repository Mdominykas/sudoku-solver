DEPS = cell.h gridStatus.h gridCommunication.h solve.h main.h


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $

program: main.o cell.o gridStatus.o gridCommunication.o solve.o
	gcc -o program main.o cell.o gridStatus.o gridCommunication.o solve.o
main.o: main.c $(DEPS)
	gcc -c main.c
cell.o: cell.c $(DEPS)
	gcc -c cell.c
gridStatus.o: gridStatus.c $(DEPS)
	gcc -c gridStatus.c
gridCommunication.o: gridCommunication.c $(DEPS)
	gcc -c gridCommunication.c
solve.o: solve.c $(DEPS)
	gcc -c solve.c $(DEPS)