#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stdio.h>

int readBytes(uint8_t* dataBuffer, char* path, uint64_t countBytesToRead);

#endif