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

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "Globals.h"

int fetch( void ); // Return the next instruction from the program
int load( const char* filename, int* mem ); // Load the program from file
void decode( int instr ); // Decode instructions into temp subregisters
void eval( bool* running ); // execute given instruction
void run( void );
void showRegs( void ); // display the contents of the registry array

#endif
