#include <stdio.h>
#include <string.h>

#include <stdint.h>

#include "./BMP/BMP.h"
#include "./IO/IO.h"

int main() {

    char str[100];
    while(1) {

        printf("Enter bitmap location:\n");
        gets(str);

        char path[100] = "testImage.bmp";
        char pathOut[100] = "out.bmp";

        if (strlen(str) > 1) {
            strcpy(path, str);
        }

        uint8_t buff[256];

        if (readBytes(buff, path, 255) == 0) {
            for (int i = 0; i < 255; i++) {
                printf("%x", buff[i]);
            }

            FileHeader fh = { 0, 0, 0, 0 };
            ImageHeader ih = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            
            if (parseHeaders(buff, 255, &fh, &ih) == 0) {
                //Not working in BMP.c for some reason.
                ih.width = buff[21] << 24 | buff[20] << 16 | buff[19] << 8 | buff[18];
                ih.height = buff[25] << 24 | buff[24] << 16 | buff[23] << 8 | buff[22];

                //Display current data
                printf("FH:\n");
                printf("%x \n", fh.header);
                printf("%x \n", fh.offset);

                printf("\nIH:\n");
                printf("%x \n", ih.width);
                    printf("%d \n", ih.width);
                printf("%x \n", ih.height);
                printf("%x \n", ih.bitCount);
                printf("%x\n", buff[18]); printf("%x\n", buff[19]);
                printf("%x\n", buff[20]); printf("%x\n", buff[21]);
                uint32_t a = buff[21] << 24 | buff[20] << 16 | buff[19] << 8 | buff[18];
                ih.width = a;
                printf("%x \n", ih.width);
                printf("%x", a);
                printf("%d \n", ih.width);

                unsigned long byteCountData = ih.bitCount/8 * ih.width * ih.height + fh.offset;
                printf("\n%lu\n", byteCountData);

                //write 0
                //TEMP MOVE TO CLASS!!!
                FILE* fp;
                FILE* fileOut;

                if (!(fp = fopen(path, "rb"))) {
                    fclose(fp);
                    puts("Error: Unable to open file!");
                    break;
                }
                if (!(fileOut = fopen(pathOut, "wb"))) {
                    fclose(fileOut);
                                        puts("OOF2");
                    break;
                }
                for (unsigned long i = 0; i < byteCountData; i++) {
                    fseek(fp, i, 0);
                    fseek(fileOut, i, 0);

                    uint8_t byteRead = 0;
                    fread(&byteRead, sizeof(byteRead), 1, fp);
                    
                    if (i < fh.offset) {
                        //write header
                        fwrite(&byteRead, sizeof(byteRead), 1, fileOut);
                    }
                    else {
                        //write data

                        //set 0 on LSB from byteRead
                        byteRead = byteRead & 0b11111110;
                        fwrite(&byteRead, sizeof(byteRead), 1, fileOut);
                    }
                }
                uint8_t nisk = 0;
                fwrite(&nisk, sizeof(nisk), 1, fileOut);
                fwrite(&nisk, sizeof(nisk), 1, fileOut);
                fclose(fp);
                fclose(fileOut);
            }
            else {
                printf("Unable to parse header from file.\n");
            }
            
        }
        else {
            printf("Unable to read file.\n");
        }
        puts("DONE!");  
    }
    gets(str);
}
