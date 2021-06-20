#ifndef BMP_H
#define DMP_H

#include <stdint.h>
#include <stddef.h>

#define BMP_HEADER_SIZE 54

//14 bytes
typedef struct {
    uint16_t header;    //essential
    uint32_t size;
    uint32_t reserved;
    //where pixel data starts
    uint32_t offset;    //essential
} FileHeader;

//40 bytes
typedef struct {
    uint32_t headerSize;
    uint32_t width;
    uint32_t height;
    //always 1
    uint16_t planes;
    //24 -> RGB
    uint16_t bitCount;  //essential
    uint32_t compression;
    //no compression -> 0
    uint32_t imageSize;
    uint32_t XpixelsPerM;
    uint32_t YpixelsPerM;
    uint32_t colorsUsed;
    //all -> 0
    uint32_t colorsImportant;
} ImageHeader;

int parseHeaders(char* data, uint32_t dataCount, FileHeader* fh, ImageHeader* ih);



#endif
