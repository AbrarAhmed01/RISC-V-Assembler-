#include <stdint.h>
#include <stdbool.h>
/*header file simulator.h*/
#ifndef SIMULATOR_H
#define SIMULATOR_H

uint8_t mux2_1(uint8_t iA, uint8_t iB, bool bSel);
void decoder2_4(bool D0, bool D1, bool * EnA, bool * EnB, bool * EnO);
uint8_t ALU(uint8_t A, uint8_t B, bool S, bool * carry);
void simulator(uint8_t instr[], int size);

#endif /* SIMULATOR_H */