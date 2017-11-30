CC=gcc
CFLAGS=-g

all: jpegdec rgb2ycc ycc2rgb dct quantize

jpegdec: jpegdec.o bitstream.o
	$(CC) $(CFLAGS) $< bitstream.o -o jpegdec 

rgb2ycc: rgb2ycc.o
	$(CC) $(CFLAGS) -lm $< -o r2y

ycc2rgb: ycc2rgb.o
	$(CC) $(CFLAGS) -lm $< -o y2r

dct: dct.o
	$(CC) $(CFLAGS) -lm $< -o $@

quantize: quantize.o
	$(CC) $(CFLAGS) -lm $< -o $@

%.s: %.c
	$(CC) $(CFLAGS) -S -o $@ $<

lib%.so: %.c
	$(CC) $(CFLAGS) -shared -o $@ -fPIC $<

clean:
	rm -rf *.o
	rm -f jpegdec r2y y2r dct quantize
