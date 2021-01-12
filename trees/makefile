CC=gcc
CFLAGS=-Wno-unused-parameter -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Wfloat-equal

OBJ1 = test
OBJ2 = bin_tree


DEPS1 = $(OBJ1).c $(OBJ1).h

DEPS2 = $(OBJ2).c $(OBJ1).o

OBJ = $(OBJ1).o $(OBJ2).o

debug: CFLAGS += -g
debug: build

build: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ1)
	rm $(OBJ)
	

$(OBJ1).0 : $(DEPS1)
	gcc $(CFLAGS) -c $(OBJ1).c -o $@

$(OBJ2).0 : $(DEPS2)
	gcc $(CFLAGS) -c $(OBJ2).c -o $@

