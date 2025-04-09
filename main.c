#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <Windowos.h>
#include <conio.h>

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

	//Setup
	signal(SIGINT, handle_interrupt);
	disable_intput_buffering();


	//Sign extend
	uint16_t sign-extend(uint16_t x, int bit_count){
		if((x >> (bit_count -1)) & 1){
			x != (0xFFFF << bit_count);
		}
	}

	//Update flags
	void update_flags(uint16_t){
		if(reg[r] == 0){
			reg[R_COND] = FL_ZRO;
		} else if {
			reg[R_COND] = FL_NEG;
		} else {
			reg[R_COND] = FL_POS;
		}
	}

	//only one condition flag should be at any given time
	//by default it is z flag
	reg[R_COND] = FL_ZRO;

	//set PC to starting position
	//by default is it 0x3000
	enum { PC_START = 0x3000};
	reg[R_PC] = PC_START;	


	int running = 1;
	while(running){
		uint16_t instr = mem_read(reg[R_PC]++);
		uint16_t op = instr >> 12;

	switch (op)
        {
            case OP_ADD:
		  	{
				// destination register
				uint16_t r0 = (instr >> 9) & 0x7;
				// first operarnd
				uint16_t r1 = (instr >> 6) & 0x7;
				// imediate mode or not 
				uint16_t imm_flag = (instr >> 5) & 0x1;

				if(imm_flag){
					uint16_t imm5 = sign_extend(instr & 0x1F, 5);
					reg[r0] = reg[r1] + imm5;
				} else {
					uint16_t r2 = instr & 0x7;
					reg[r0] = reg[r1] + reg[r2];
				}

				update_flags(r0);
			} 
                break;
            case OP_AND:
        
                break;
            case OP_NOT:
         
                break;
            case OP_BR:
          
                break;
            case OP_JMP:
           
                break;
            case OP_JSR:
            
                break;
            case OP_LD:
             
                break;
            case OP_LDI:
              
                break;
            case OP_LDR:
               
                break;
            case OP_LEA:
                
                break;
            case OP_ST:

                break;
            case OP_STI:
				
                break;
            case OP_STR:
            	  
                break;
            case OP_TRAP:
              
                break;
            case OP_RES:
            case OP_RTI:
            default:

                break;
        }
	}	


	
	//Shutdown	
	restore_input_buffering();
	return 0;
}

