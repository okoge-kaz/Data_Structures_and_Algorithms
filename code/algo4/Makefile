# compiler
CC = gcc
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = item.h list.h
# object files
OBJ = main.o item.o list.o
# main file name
TARGET = main
# out file name
OUT = main

all : $(TARGET) 

$(TARGET): $(OBJ)
	gcc $(CFLAGS) -o $(OUT) $(OBJ) -lm

$(OBJ): $(DEPS)

tree : tree.c item.o list.o
	gcc -Wall -o tree tree.c item.o list.o
.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~)