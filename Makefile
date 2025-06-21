CC = gcc
CFLAGS = -g -Wall -std=gnu99 -pedantic
MAIN = array_list_tests
OBJS = array_list_tests.o array_list.o

all : $(MAIN)

$(MAIN) : $(OBJS) array_list.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

array_list_tests.o : array_list_tests.c array_list.h
	$(CC) $(CFLAGS) -c array_list_tests.c

array_list.o : array_list.c array_list.h
	$(CC) $(CFLAGS) -c array_list.c

test: $(MAIN)
	./array_list_tests

clean :
	rm -f *.o $(MAIN) core
