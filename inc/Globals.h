/*
    This file is part of Beard VM.

    Beard VM is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Beard VM is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Beard VM; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "stdio.h"
#include "string.h"
#include "stdbool.h"

/* CONSTANTS */
#define NUM_REGS 4 // Number of registers

/* TYPES */
typedef struct b_instruction b_instruction; // holds the decoded instruction

struct b_instruction {
    int code; 
    int op1; // operands 1-3
    int op2;
    int op3;
    int imv; // immediate value
};

/* VARIABLES */
int regs[ NUM_REGS ];
int prog[ 10 ];
int pc;
bool running;

b_instruction c_i; // current instruction

#endif
