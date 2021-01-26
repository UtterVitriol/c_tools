CC=gcc
CFLAGS= -Wall -Wextra -Wpedantic -Waggregate-return -Wwrite-strings -Wvla -Wfloat-equal -O3 -std=c11

OBJ1 = graph
OBJ2 = queue/queue

DEPS1 = $(OBJ1).c $(OBJ1).h $(OBJ2).h
DEPS1 = $(OBJ2).c $(OBJ2).h $(OBJ1).h

OBJ = $(OBJ1).o $(OBJ2).o

all: build

debug: CFLAGS += -g
debug: build

build: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ1)
	rm -f $(OBJ)

profile: CFLAGS += -pg
profile:$(OBJ1).o
	$(CC) $(CFLAGS) $(OBJ1).o -o $(OBJ1)
	rm -f $(OBJ1).o

clean:
	rm -f $(OBJ1)
	rm -f gmon.out

check:
	./intersect test/test1.txt test/test2.txt
	./intersect -u test/test1.txt test/test2.txt
	./intersect -l test/test1.txt test/test2.txt
	./intersect -lu test/test1.txt test/test2.txt
	./intersect -i test/test1.txt test/test2.txt
	./intersect -il test/test1.txt test/test2.txt
	./intersect -ilu test/test1.txt test/test2.txt

$(OBJ1).o : $(DEPS1)
	$(CC) -c $(CFLAGS) $(OBJ1).c

$(OBJ2).o : $(DEPS2)
	$(CC) -c $(CFLAGS) $(OBJ2).c -o $(OBJ2).o