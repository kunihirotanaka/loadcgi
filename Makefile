CC = gcc
CFLAGS = -Wall -O2

loadcgi: loadcgi.c
	$(CC) -o $@ $(CFLAGS) $<
