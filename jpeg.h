/**
 * @file
 * Common JPEG encoder/decoder header 
 */

#ifndef JPEG_H
#define JPEG_H

#include "bitstream.h"
#include <stdint.h>

typedef uint8_t Pxl[3];

#define PXL_R 0
#define PXL_G 1
#define PXL_B 2
#define PXL_Y 0
#define PXL_Cb 1
#define PXL_Cr 2

/** Context structure for JPEG encoder/decoder. */
typedef struct {
    struct bitstream *bs;   ///< JPEG file's bitstream context
    Pxl *outbuf;            ///< Output array of RGB pixels 
} JpegCtx;

enum HT_TYPE {
    DC = 0,
    AC = 1,
};

typedef struct {
    uint16_t length;        ///< Length of table in bitstream
    enum HT_TYPE type;      ///< Type of DCT coefficient
    uint8_t dest_id;        ///< Destination Identifier
    uint8_t nsymbols[16];   ///< Nb symbols per bitlength 1..16
    uint8_t *huffvals;
} JpegHuffTable;

/** Decode a jpeg encoded JFIF file.
 * @param[in] jpegfile File pointer to the JFIF file. 
 */
Pxl * decode(FILE *jpegfile);

#endif
