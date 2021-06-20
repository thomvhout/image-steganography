#include "BMP.h"

int parseHeaders(char* data, uint32_t dataCount, FileHeader* fh, ImageHeader* ih) {
    if (data == NULL || fh == NULL || ih == NULL) {
        return -1;
    }

    if (dataCount < 54) {
        return -1;
    }

//clear values first, because the or bitwise operator won't 
//remove bits that are already set high
fh-> header = 0;
fh-> offset = 0;

//assumes data starts with header
    //bm tag, first data in the header
    fh->header = (data[0] << 8) | data[1];
    
    //data doesn't start with header or image not supported
    if (fh->header != 0x424d) {
        //don't cont. parsing
        return -1;
    }

    //little endian -> big endian
    fh->offset = data[13] << 24 | data[12] << 16 | data[11] << 8 | data[10];

    ih->width = 0;
    ih->height = 0;
    ih->bitCount = 0;

    //NOT WORKING
    uint32_t width = data[21] << 24 | data[20] << 16 | data[19] << 8 | data[18];
    ih->width = width;
    ih->height = data[25] << 24 | data[24] << 16 | data[23] << 8 | data[22];
    //WORKING
    ih->bitCount = data[29] << 8 | data[28];

    return 0;
}