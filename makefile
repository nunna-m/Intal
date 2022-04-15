CC=gcc
CFLAGS=-I.
DEPS=intal.h

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

intal: check.o intal.o
		$(CC) -o intal check.o intal.o