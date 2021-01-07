CC=gcc
CFLAGS= -Wno-unused-parameter -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Wfloat-equal

DEPS1 = test.c
DEPS2 = queue.c queue.h

OBJ1 = test
OBJ2 = queue

OBJ = $(OBJ1).o $(OBJ2).o

all: build

debug: CFLAGS += -g
debug: build

build: $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ1) $(OBJ)
	rm $(OBJ)


$(OBJ1).o : $(DEPS1)
	gcc -c $(CFLAGS) $(OBJ1).c -o $@

$(OBJ2).o : $(DEPS2)
	gcc -c $(CFLAGS) $(OBJ2).c -o $@
