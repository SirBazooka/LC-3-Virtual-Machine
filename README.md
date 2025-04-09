# LC-3 Virtual Machine 

## Overview
This is a Virtual Machine implementation in c based on LC-3 architecture. 
LC-3 architecture is an educational computer architecture commonly used in universities.

## Features
- **Register Management:** Supports general-purpose registers (R0-R7), program counter (PC), and condition flags (P, Z, N).
- **Instruction Set:** Implements a subset of LC-3 instructions including ADD, AND, NOT, BRANCH, JMP, JSR, LD, LDI, LDR, LEA, ST, STI, STR, and TRAP.
- **Memory Operations:** Handles loading and storing data in memory.
- **Control Flow:** Supports branching and jumping instructions.
- **Trap Routines:** Implements trap routines for input/output operations and program termination.
- **Input Buffering:** Disables input buffering for immediate character input.
- **Signal Handling:** Restores input buffering and exits gracefully on interrupt signals.

## Requirements
- **Operating System:** Windows (due to Windows-specific libraries like `Windows.h` and `conio.h`)
- **Compiler:** A C compiler that supports C99 or later (e.g., GCC)

## Setup

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/SirBazooka/LC-3-Virtual-Machine.git
   cd LC-3-Virtual-Machine
   ```

2. **Compile the Code:**

   ```sh
   gcc -o lc3 main.c
   ```

3. **Runt the Virtual Machine:** \
   *(As testing app I use the game 2048 in the 2048.obj file.)*
   ```sh
   lc3 2048.obj
   ```
