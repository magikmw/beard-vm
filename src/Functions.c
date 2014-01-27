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

#include "Functions.h"

int fetch( void ) {
    return prog[ pc++ ];
}

void decode( int instr ) {
    printf("instr: %04X\n", instr);

    c_i.code = (instr & 0xF000) >> 12;
    c_i.op1 = (instr & 0xF00 ) >>  8;
    c_i.op2 = (instr & 0xF0  ) >>  4;
    c_i.op3 = (instr & 0xF   );
    c_i.imv = (instr & 0xFF  );
}

void eval( void ) {
    switch( c_i.code ) {
        case 0: // halt
            printf( "halt\n" );
            running = 0;
            break;
        case 1: // load
            printf ( "load r%d $%d\n", c_i.op1, c_i.imv );
            regs[ c_i.op1 ] = c_i.imv;
            break;
        case 2: // add
            printf( "add r%d r%d r%d\n", c_i.op1, c_i.op2, c_i.op3 );
            regs[ c_i.op1 ] = regs[ c_i.op2 ] + regs[ c_i.op3 ];
            break;
    }
}

void run( void ) {
    while ( running ){
        showRegs();
        int instr = fetch();
        decode( instr );
        eval();
    }
    showRegs();
}

void showRegs( void )
{
  printf( "regs = " );
  for( int i=0; i<NUM_REGS; i++ )
    printf( "%04X ", regs[ i ] );
  printf( "\n" );
}
