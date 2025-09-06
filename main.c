/********************************************************
Project of C Module (NCDC)
Description: K2 Microprocessor and Simulator
By: Abrar Ahmed
Date: 18/08/2024
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//Different header files containing different functions
#include "assembler.h"
#include "loadmem.h"
#include "simulator.h"

//instruction address length
#define N 16 

int main()
{   
    //variables for input from user and files
    char input = ' ';
    char input_file[] = "fibonacci.asm";
    char output_file[] = "fibonacci.bin";
    //array to store instructions
    uint8_t instruction [N] = {0};

    //Menu Display
    printf("************************************\n");
    printf("K2 Assembler And Simulator Program \n");
    printf("************************************\n");
    
    while(input != 'E')
    {
        printf("\n");
        printf("Select the command you want to perform (e.g. C, L, R, E):\n");
        printf("1. Convert the assembly code(file.asm) to machine code(file.bin) (Command: C).\n");
        printf("2. Load the binary file to processor (Command: L).\n");
        printf("3. Run the K2 Microprocessor Simulator (Command: R).\n");
        printf("4. Exit Program (Command: E).\n");
        printf("Enter Command: ");
        scanf(" %c", &input);
        printf("\n");

        switch(input)
        {
            case 'C':           //to convert assembly code to machine code
                assembler(input_file, output_file);
                break;
            case 'L':           //to upload machine code to instruction memory
                inst_mem_write(output_file, instruction, N);
                break;
            case 'R':           //K2 Processor simulation
                simulator(instruction, N);
                break;
            case 'E':
                                //do nothing (to exit program)
                break;
            default:
                printf("Error: Wrong command entered.\n");
                break;
        }
    }
    
    return 0;
}