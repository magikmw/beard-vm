Beard VM Specifications
=====
This will be updated as I go. Rewrites of the whole thing should be expected.

The Machine
-----

* 16-bit
* 4 registers (0-3)

Addressing
-----

Register numbers begin with 'r': r0, r1, r2, r3.
Immediate values begin with '#': #100, #200, #2, #256.
Memory addresses begin with '@': @1000, @1004.

Instructions
-----

[code] [instruction name] [operands]

0 halt  
1 load [r_dest] [value]  
2 add [r_result] [r_add] [r_add]  
...

Encoding
-----
16-bit hexadecimal numbers.  
1st digit (4 bits) is the instruction code number.  
Remaining (3) digits are used as operands.

Implementation
-----

There is going to be one.  
Ideally I want to avoid using any of the built-in types of C.  
As close to the metal as I can without using an assembler to write a VM.
