#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "simulator.h"

//mux 2 to 1 function
uint8_t mux2_1(uint8_t iA, uint8_t iB, bool bSel)
{
    uint8_t out = 0;
    if(bSel == 0)
    {
        out = iA;
    }
    
    else if(bSel == 1)
    {
        out = iB;
    }

    return out;
}

//decoder 2 to 4 function
void decoder2_4(bool D0, bool D1, bool * EnA, bool * EnB, bool * EnO)
{
    if (D0 == 0 && D1 == 0)
    {
        *EnA = 1;
        *EnB = 0;
        *EnO = 0;
    }

    else if (D0 == 1 && D1 == 0)
    {
        *EnA = 0;
        *EnB = 1;
        *EnO = 0;
    }

    else if (D0 == 0 && D1 == 1)
    {
        *EnA = 0;
        *EnB = 0;
        *EnO = 1;
    }

    else 
    {
        *EnA = 0;
        *EnB = 0;
        *EnO = 0;
    }
}

//ALU function which calculates addition and subtraction, also carry out
uint8_t ALU(uint8_t A, uint8_t B, bool S, bool * carry)
{
    uint8_t out = 0;

    if(S == 0)
    {
        out = A + B;
        *carry = (out > 0xF);
    }

    else if (S == 1)
    {
        //Performing Subtraction
        out = A - B;

        //Checking for carry out (borrow)
        *carry = (A < B) ? 1 : 0;
    }
    out = out & 0xF;
    return out;
}

//main K2 processor simulation function
void simulator(uint8_t instr[], int size)
{
    //Registers RA, RB, RO
    uint8_t RO = 0;
    uint8_t RA = 0;
    uint8_t RB = 0;
    
    //to store mux output
    uint8_t mux_out = 0;

    //to store alu output
    uint8_t alu_out = 0;

    //program counter variable
    uint8_t program_counter = 0;

    //to extract operands and control signals from opcode
    bool J, C, D1, D0, Sreg, S;
    J = C = D1 = D0 = Sreg = S = 0;

    //registers enable control variables
    bool EnA, EnB, EnO;
    EnA = EnB = EnO = 0;
    
    //variable to extract immediate value
    uint8_t imm = 0;

    //D Flip flop variable
    bool DFF = 0;

    //variable to store jump and branch
    bool jump = 0;

    while(program_counter < size)
    {
        //extracting signals and imm from opcode through instruction memory    
        uint8_t opcode = instr[program_counter];
        imm = opcode & 0x7;
        S = opcode & 0x4;
        Sreg = opcode & 0x8;
        D0 = opcode & 0x10;
        D1 = opcode & 0x20;
        C = opcode & 0x40;
        J = opcode & 0x80;

        if(D0 == 1 && D1 == 1 && C == 1){
            //do nothing (for jump if carry as the alu calculated in this operation so it should not)
        }
        else
        {
            alu_out = ALU(RA, RB, S, &DFF); //alu calculation for every instruction except branch
        }

        //selecting output to registers
        mux_out = mux2_1(alu_out, imm, Sreg);

        //decoding enable signals of registers
        decoder2_4(D0, D1, &EnA, &EnB, &EnO);

        //storing value in registers
        if(EnA == 1)
        {
            RA = mux_out;
        }

        else if(EnB == 1)
        {
            RB = mux_out;
        }

        else if(EnO == 1)
        {
            RO = RA;

            //to print RO register output on terminal
            printf("Register RO = 0x%02X \n", RO & 0xF);
            printf("_______________________\n");
        }

        //calculating jump and branch
        jump = J | (C & DFF);
        
        //jump to specific instruction address if true
        if (jump == 1)
        {
            program_counter = imm;
        }

        //else increment program counter
        else
        {
            program_counter++;
        }
        //as we have no end condition in assembly code, so we use this condition to exit the lopp
        //can be commented out for different conditions
        if (RO == 13)
        {
            break;
        }
    }
}