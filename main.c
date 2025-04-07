#include <stdio.h>
#include <stdint.h>
#include <signal.h>

//LC-3 Architecture - hardware components

//Memory storage
#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];

//Registers
enum{
	R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* program counter */
    R_COND,
    R_COUNT
};
uint16_t reg[R_COUNT];

//Opcodes
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

//Condition flags
//Condition flags provide information about the most recently executed calculation 
enum {
	FL_POS = 1 << 0, 
	FL_ZRO = 1 << 1,
	FL_NEG = 1 << 2,
};



int main(int argc, const char* argv[]){
	//Load arguments
	if (argc < 2){
		printf("LC-3 [image-file] ...\n");
		exit(2);
	}

	for(int i = 1; i < argc; ++i){
		if(!read_image(argv[i])){
			printf("failed to load image: %s\n", argv[i]);
		}
	}


	return 0;
}

