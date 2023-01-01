# Make file for linked list project.
# Note, uses templates.

CC	= g++
CCFLAGS = -Wall -Wextra -pedantic -std=c++11 -g
DEPS1	= linkedListType.h unorderedLinkedList.h
DEPS2	= linkedListType.h orderedLinkedList.h

all:	mainOrdered mainUnordered

mainUnordered:	mainUnordered.o
	$(CC) $(CCFLAGS) -o mainUnordered mainUnordered.o

mainUnordered.o:	mainUnordered.cpp $(DEPS1)
	$(CC) $(CCFLAGS) -c mainUnordered.cpp

mainOrdered:	mainOrdered.o
	$(CC) $(CCFLAGS) -o mainOrdered mainOrdered.o

mainOrdered.o:	mainOrdered.cpp $(DEPS2)
	$(CC) $(CCFLAGS) -c mainOrdered.cpp

# -----
# clean by removing object files.

clean:
	rm	mainOrdered.o
	rm	mainUnordered.o
