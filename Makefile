CC=gcc
CFLAGS=-g

all: jpegdec 

jpegdec: jpegdec.o bitstream.o
	$(CC) $(CFLAGS) $< bitstream.o -o jpegdec 

%.s: %.c
	$(CC) $(CFLAGS) -S -o $@ $<

lib%.so: %.c
	$(CC) $(CFLAGS) -shared -o $@ -fPIC $<

clean:
	rm -rf *.o
	rm -f jpegdec 
