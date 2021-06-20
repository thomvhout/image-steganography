#include "IO.h"

int readBytes(uint8_t* dataBuffer, char* path, uint64_t countBytesToRead) {
    FILE* fp;

    if (!(fp = fopen(path, "rb"))) {
        fclose(fp);
        return -1;
    }
    else if (fread(dataBuffer, sizeof(char), countBytesToRead, fp) > 0) {
            fclose(fp);
            return 0;        
    }
    
    fclose(fp);
    return -1;
}