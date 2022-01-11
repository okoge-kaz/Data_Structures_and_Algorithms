CC	= gcc
CFLAGS	= -Wall -O2
TARGET	= test dfs bfs

.c.o:
	$(CC) $(CFLAGS) -c $<

test: test.o graph-adjarray.o
	$(CC) -o test test.o graph-adjarray.o

dfs: dfs.o graph-adjarray.o
	$(CC) -o dfs dfs.o graph-adjarray.o

bfs: bfs.o graph-adjlist.o queue.o
	$(CC) -o bfs bfs.o graph-adjlist.o queue.o

clean:
	rm -f *.o *~ $(TARGET)
