OBJS = main.o 
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o out

main.o: main.cpp SortTestingHelper.h SelectionSort.h insertionSort.h mergeSort.h heapSort.h ../search/binarySearch.h
	$(CC) $(CFLAGS) main.cpp

# SelectionSort.o: SelectionSort.cpp SelectionSort.h
# 	$(CC) $(CFLAGS) SelectionSort.cpp

clean:
	\rm *.o out

tar:
	tar cfv out.tar makefile *.cpp *.h