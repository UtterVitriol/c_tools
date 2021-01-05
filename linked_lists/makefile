CC=gcc
CFLAGS= -g -Wno-unused-parameter -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Wfloat-equal

DEPS1 = test.c
DEPS2 = link_list.c link_list.h

OBJ1 = test
OBJ2 = link_list

OBJ = $(OBJ1).o $(OBJ2).o

build: $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ1) $(OBJ)
	rm $(OBJ)


$(OBJ1).o : $(DEPS1)
	gcc -c $(OBJ1).c -o $@

$(OBJ2).o : $(DEPS2)
	gcc -c $(OBJ2).c -o $@
