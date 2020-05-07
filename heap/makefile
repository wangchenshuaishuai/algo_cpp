CFLAG = -Wall -c
LFLAG = -Wall
CC = g++
Objects = main.o


all:$(Objects)
	$(CC) $(LFLAG) $(Objects) -o out

main.o: main.cpp heap.h indexHeap.h
	$(CC) $(CFLAG) main.cpp


clean:
	rm *.o
	rm out.exe