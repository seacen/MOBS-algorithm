# Makefile 
# Andrew Turpin
# March 2014

OBJ     = main.o stack.o oracle.o binarySearch.o mobs.o

CC    = g++ 
CFLAGS = -Wall -O2

main: $(OBJ) Makefile
	$(CC) $(CFLAGS) -o main $(OBJ)

clean:
	rm -f $(OBJ) main

clobber: clean
	rm -f main

test:
	@./main Z 0 100 15 0.1 5000 > /tmp/x
	@R --slave --args /tmp/x < plot.r
	@mv Rplots.pdf exp1.pdf
	@./main Z 0 1000 15 0.1 5000 > /tmp/x
	@R --slave --args /tmp/x < plot.r
	@mv Rplots.pdf exp2.pdf
	@./main Z 0 999 499 0 5000 > /tmp/x
	@R --slave --args /tmp/x < plot.r
	@mv Rplots.pdf exp3.pdf
	@./main Z 0 20000 20000 0.3 5000 > /tmp/x
	@R --slave --args /tmp/x < plot.r
	@mv Rplots.pdf exp4.pdf
	@./main Z 100 156 119 0.1 5000 > /tmp/x
	@R --slave --args /tmp/x < plot.r
	@mv Rplots.pdf exp5.pdf

mobs.o:         mobs.h Makefile oracle.h stack.h
binarySearch.o: binarySearch.h Makefile oracle.h stack.h
main.o:         mobs.h binarySearch.h Makefile stack.h
oracle.o:       oracle.h Makefile

