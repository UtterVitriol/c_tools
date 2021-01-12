CC=gcc
CFLAGS=-Wno-unused-parameter -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Wfloat-equal

OBJ1 = stack_array_i
OBJ2 = stack_array_c
OBJ3 = postfx_calc


DEPS1 = $(OBJ1).c $(OBJ1).h

DEPS2 = $(OBJ2).c $(OBJ2).h

DEPS3 = $(OBJ3).c $(OBJ2).o $(OBJ1).o

OBJ = $(OBJ1).o $(OBJ2).o $(OBJ3).o

debug: CFLAGS += -g
debug: build

build: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ3) -lm
	rm $(OBJ)
	

$(OBJ1).0 : $(DEPS1)
	gcc $(CFLAGS) -c $(OBJ1).c -o $@

$(OBJ2).0 : $(DEPS2)
	gcc $(CFLAGS) -c $(OBJ2).c -o $@

$(OBJ3).o : $(DEPS3)
	gcc $(CFLAGS) -c $(OBJ3).c -o $@
