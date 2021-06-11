CC = gcc
CFLAGS = -g -Wall

default: all

all: keylogfile

keylogfile: keylogfile.c
	$(CC) $(CFLAGS) -o openssl_keylogfile.so -shared -fPIC keylogfile.c -lcrypto -lssl -I$(OPENSSLDEVEL) -I$(OPENSSLDEVEL)/include

clean:
	rm -f openssl_keylogfile.so
