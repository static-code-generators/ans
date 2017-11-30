#include "jpeg.h"
#include <stdlib.h>
#include <assert.h>

static void read_huffman_table(JpegCtx *j)
{
    uint8_t byte;
    JpegHuffTable *ht = malloc(sizeof(JpegHuffTable));
    // Read length of DHT
    ht->length = read_nbits(j->bs, 16);
    // Read type of DHT
    byte = read_nbits(j->bs, 4);
    assert(byte == 0 || byte == 1);
    ht->type = byte;
    // Read destination identifier
    ht->dest_id = read_nbits(j->bs, 4);
    // FIXME: Assuming baseline only rn
    assert(ht->dest_id <= 1);
    uint16_t nhv = 0;
    for (int i = 0; i < 16; i++) {
        ht->nsymbols[i] = read_byte(j->bs);
        nhv += ht->nsymbols[i];
    }
    // Ensure DHT length = 19 + nhv
    assert(ht->length == nhv + 19);
    // Read Huff values
    ht->huffvals = malloc(sizeof(uint8_t) * nhv);
    for (int i = 0; i < nhv; i++) {
        ht->huffvals[i] = read_byte(j->bs);
    }
}

static void handle_marker(JpegCtx *j)
{
    uint8_t byte = read_byte(j->bs);
    switch (byte) {
    case 0x00: // ignore
        break;
    case 0xc4: // huffman table
        read_huffman_table(j);
        break;
    case 0xd9: // end of image
        exit(0); 
    case 0xd8: // start of image
    default:
        break;
    }
}

Pxl * decode(FILE *jpegfile)
{
    JpegCtx *j = malloc(sizeof(JpegCtx));
    j->bs = initbitstream(jpegfile, BS_READ, 0);
    uint8_t byte;
    while (j->bs->last != 1) {
        byte = read_byte(j->bs);
        if (byte == 0xff) {
            handle_marker(j);
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Use %s <jpegfile> <outfile>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "rb");
    decode(fp);
    return 0;
}
