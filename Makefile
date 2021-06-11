CC = gcc
CFLAGS = -g

default: all

all: keylogfile

keylogfile: keylogfile.c
	$(CC) $(CFLAGS) -o keylogfile keylogfile.c

clean:
	rm -f keylogfile
