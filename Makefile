CC = gcc
CFLAGS = -g

default: all

all: keylogfile

keylogfile: keylogfile.c
	$(CC) $(CFLAGS) -o openssl_keylogfile.so -shared -fPIC keylogfile.c -D_GNU_SOURCE

clean:
	rm -f openssl_keylogfile.so
