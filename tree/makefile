CC = g++
CFLAG = -Wall -c
LFLAG = -Wall
OBJS = main.o test.o #ReadFile.o

ALL:$(OBJS)
	$(CC) $(LFLAG) $(OBJS) -o out

main.o: main.cpp  test.h bsTree.h
	$(CC) $(CFLAG) main.cpp

test.o: test.cpp test.h
	$(CC) $(CFLAG) test.cpp

# ReadFile.o: ReadFile.cpp ReadFile.h
# 	$(CC) $(CFLAG) ReadFile.cpp