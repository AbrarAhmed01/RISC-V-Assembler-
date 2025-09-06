#include <stdint.h>
/*header file loadmem.h*/
#ifndef LOADMEM_H
#define LOADMEM_H

void inst_mem_write(const char * filename, uint8_t instr[], int size);

#endif /* LOADMEM_H */