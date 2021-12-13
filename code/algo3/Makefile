ltest: main.c lstack.o
	gcc -Wall -O2 -o ltest main.c lstack.o

atest: main.c astack.o
	gcc -Wall -O2 -o atest main.c astack.o

postfix: postfix.c astack.o
	gcc -Wall -O2 -o postfix postfix.c astack.o

in2post: in2post.c lstack.o
	gcc -Wall -O2 -o in2post in2post.c lstack.o

lstack.o: lstack.c 
	gcc -c lstack.c

astack.o: astack.c 
	gcc -c astack.c

clean: 
	rm -f *.o *~ atest ltest postfix in2post

