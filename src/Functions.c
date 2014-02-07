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
    return mem[ pc++ ];
}

int load( const char * filename, int* mem ) {
    unsigned char buffer[8];

    FILE* progfile = fopen( filename, "r" );
    if( progfile == NULL ) {
        printf("Error: Provided filename (%s) is not a file.\n", filename);
        return 1;
    }

    fread( &buffer, 1, 8, progfile );

    unsigned char header[] = { 0x89, 0x42, 0x45, 0x41, 0x42, 0x4f, 0x0a, 0x00 };
    if( memcmp(buffer, header, 8 ) ){
        printf("Error: Provided file (%s) is not a Beard Object type.\n", filename);
        return 1;
    }

    int read = -1;

    for( int i = 0; read != 0; i++ ){
        read = fread( mem+i, 1*2, 1, progfile );
        // printf("read: <%04X>\n", *mem+i);
    }

    fclose( progfile );

    return 0;
}

void decode( int instr ) {
    printf("instr: %04X\n", instr);

    c_i.code = (instr & 0xF000) >> 12;
    c_i.op1 = (instr & 0xF00 ) >>  8;
    c_i.op2 = (instr & 0xF0  ) >>  4;
    c_i.op3 = (instr & 0xF   );
    c_i.imv = (instr & 0xFF  );
}

void eval( bool* running ) {
    switch( c_i.code ) {
        case 0: // halt
            printf( "halt\n" );
            *running = false;
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
    bool running = true;

    while ( running ){
        showRegs();
        int instr = fetch();
        decode( instr );
        eval( &running );
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
