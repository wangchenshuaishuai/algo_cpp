OBJS = main.o quicksort.o printarr.o 
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o out

main.o: main.cpp printarr.h quicksort.h printall.h SortTestingHelper.h SelectionSort.h
	$(CC) $(CFLAGS) main.cpp

printarr.o: printarr.cpp printarr.h
	$(CC) $(CFLAGS) printarr.cpp

# SelectionSort.o: SelectionSort.cpp SelectionSort.h
# 	$(CC) $(CFLAGS) SelectionSort.cpp

clean:
	\rm *.o out

tar:
	tar cfv out.tar makefile *.cpp *.h