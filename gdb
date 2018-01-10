*How to Use gdb in C++ *

g++ -g file.cpp		// -g to turn the debugging on 

gdb ./a.out		// to enter into debugging mode.. executable file

b file.cpp:line number	// to set break point at line number

b function name		// to set break point at function

b line number		// to set break point at line number

bt 			// back trace

c			// continues execution from break point

list line number	// list the source code around line number or current line number

where 			// show the stack frames

condition <bp-num> <exp>   Sets breakpoint number <bp-num> to break only if
                           conditional expression <exp> is true

n			// step over 

s			// step into

p data			// print the value of variable 

quit 			// get off from debugging mode


