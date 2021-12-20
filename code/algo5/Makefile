# compiler
CC = gcc
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = Item.h heap.h
# object files
OBJ = main.o heap.o
# main file name
TARGET = main
# out file name
OUT = a.out

all : $(TARGET) 

$(TARGET): $(OBJ)
	gcc $(CFLAGS) -o $(OUT) $(OBJ) -lm

$(OBJ): $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~) $(OUT)
