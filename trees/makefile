CC=gcc
CFLAGS=-Wno-unused-parameter -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Wfloat-equal

OBJ1 = test
OBJ2 = bin_tree
OBJ3 = queue/queue_array
OBJ4 = stack/stack_array


DEPS1 = $(OBJ1).c $(OBJ1).h

DEPS2 = $(OBJ2).c $(OBJ1).o

DEPS3 = $(OBJ3).c $(OBJ3).h

DEPS3 = $(OBJ3).c $(OBJ3).h

DEPS4 = $(OBJ3).c $(OBJ3).h

OBJ = $(OBJ1).o $(OBJ2).o $(OBJ3).o $(OBJ4).o

debug: CFLAGS += -g
debug: build

build: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ1)
	rm $(OBJ)
	

$(OBJ1).0 : $(DEPS1)
	gcc $(CFLAGS) -c $(OBJ1).c -o $@

$(OBJ2).0 : $(DEPS2)
	gcc $(CFLAGS) -c $(OBJ2).c -o $@

$(OBJ3).0 : $(DEPS3)
	gcc $(CFLAGS) -c $(OBJ3).c -o $@

$(OBJ4).0 : $(DEPS4)
	gcc $(CFLAGS) -c $(OBJ4).c -o $@