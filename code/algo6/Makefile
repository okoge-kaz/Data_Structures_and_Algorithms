# compiler
CC = gcc
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = item.h st.h
# object files
OBJ = main.o item.o 
# main file name
TARGET = lp sc
# out file name
OUT = lp
OUT2 = sc 
# standard
STD = -std=c99

all : $(TARGET) 

lp: $(OBJ) st.o
	gcc $(CFLAGS) $(STD) -o $(OUT) $(OBJ) st.o -lm

sc: $(OBJ) st2.o
	gcc $(CFLAGS) $(STD) -o $(OUT2) $(OBJ) st2.o -lm

$(OBJ): $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~) lp sc
