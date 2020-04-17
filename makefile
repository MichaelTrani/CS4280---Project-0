#Michael Trani 2/14/2020
#Make Clean does not remove executable 
CC = gcc
CFLAGS = -g -lrt -lpthread
TARGET = p0
OBJS1 = p0.o node.h
OBJS2 = tree.o tree.h node.h
.SUFFIXES: .c .o

all: $(TARGET)
p0: $(OBJS1) $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS1) $(OBJS2) -o $@
.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.o
