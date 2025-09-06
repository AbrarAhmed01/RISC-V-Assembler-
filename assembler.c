#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assembler.h"

//Function to convert the assembly instruction into machine code
unsigned char assemble(char* instruction) {
    if (strncmp(instruction, "RA = RA + RB", 12) == 0)
    {
        return 0b00000000;          //function 1 of K2 ISA
    }

    else if (strncmp(instruction, "RB = RA + RB", 12) == 0)
    {
        return 0b00010000;          //function 2 of K2 ISA
    
    }
    else if (strncmp(instruction, "RA = RA - RB", 12) == 0)
    {
        return 0b00000100;          //function 3 of K2 ISA
    }

    else if (strncmp(instruction, "RB = RA - RB", 12) == 0)
    {
        return 0b00010100;          //function 4 of K2 ISA
    }

    else if (strncmp(instruction, "RO = RA", 7) == 0)
    {
        return 0b00100000;          //function 5 of K2 ISA
    }

    else if (strncmp(instruction, "RA = ", 5) == 0)     //function 6 of K2 ISA
    {
        int imm = atoi(instruction + 5);     //atoi is a function that converts the string read in to an integer
        return 0b00001000 | (imm & 0b111);  // Mask to fit the 3-bit immediate
    }

    else if (strncmp(instruction, "RB = ", 5) == 0)     //function 7 of K2 ISA
    {
        int imm = atoi(instruction + 5);    //atoi is a function that converts the string read in to an integer
        return 0b00011000 | (imm & 0b111);  // Mask to fit 3-bit immediate
    }

    else if (strncmp(instruction, "jump if carry", 13) == 0)    //function 8 of K2 ISA
    {
        int imm = atoi(instruction + 14);   //atoi is a function that converts the string read in to an integer
        return 0b01110000 | (imm & 0b111);  // Mask to fit 3-bit immediate
    }

    else if (strncmp(instruction, "jump to", 7) == 0)           //function 9 of K2 ISA
    {
        int imm = atoi(instruction + 8);    //atoi is a function that converts the string read in to an integer
        return 0b10110000 | (imm & 0b111);  // Mask to fit 3-bit immediate
    }

    else
    {
        printf("Error: Unknown instruction \"%s\"\n", instruction);
        exit(1);                            //exit function if wrong assemly code entered
    }
}

void assembler(const char * input_filename, const char * output_filename) {
    FILE *input = fopen(input_filename, "r");
    FILE *output = fopen(output_filename, "wb");

    //if both files not opened
    if (input == NULL) {
        printf("Error: Could not open the assembly file.\n");
        exit(1);
    }

    if (output == NULL) {
        printf("Error: Could not open the binary file.\n");
        exit(1);
    }

    char line[256];

    while (fgets(line, sizeof(line), input)) {
        
        //Converting assembly instruction to machine code
        unsigned char machine_code = assemble(line);

        //Writing the machine code to the output file
        fwrite(&machine_code, sizeof(unsigned char), 1, output);
    }

    fclose(input);
    fclose(output);

    printf("Assembly code has been successfully assembled into %s\n", output_filename);
}
