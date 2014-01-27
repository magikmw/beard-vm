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

#include "BeardMain.h"

int regs[ NUM_REGS ];

// test program
// 1. load r0 #100
// 2. load r1 #200
// 3. add r2 r0 r1
// 4. halt
int prog[10] = { 0x1064, 0x11C8, 0x2201, 0x0000 };

int pc = 0; // set the program counter

bool running = true;

int main( void ) {

    run();
    return 0;
}
