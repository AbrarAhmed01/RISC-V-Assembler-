#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "loadmem.h"

void inst_mem_write(const char * filename, uint8_t instr[], int size)
{
    char chfile = ' ';
    int i = 0;
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    printf("Instruction Memory:\n");
    while(chfile != EOF)
    {
        chfile = fgetc(fptr);
        instr[i] = (uint8_t)chfile;
        printf("%d.\t 0x%02X \n", i, instr[i]);
        i++;
    }

    fclose(fptr);
}