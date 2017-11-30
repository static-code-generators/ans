CC=gcc
CFLAGS=-O2

all: compress 

compress: compress.o kans.h
	$(CC) $(CFLAGS) compress.o -o compress

decompress: decompress.o kans.h
	$(CC) $(CFLAGS) decompress.o -o decompress

%.s: %.c
	$(CC) $(CFLAGS) -S -o $@ $<

lib%.so: %.c
	$(CC) $(CFLAGS) -shared -o $@ -fPIC $<

clean:
	rm -rf *.o
	rm -f compress
	rm -f decompress
