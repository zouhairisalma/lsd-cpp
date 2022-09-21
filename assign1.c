#include <stdio.h>
#include "ass1.h"


int main()
{
	check_msb(3);
	check_msb_char(5);
	print_bits(9);
	print_bits_int(4);
	print_nth_byte(2,1);
	
	/*
	For exercise 5:
	
	--> first of all, in our Terminal, we create the object file assign1.o by compiling assign1.h :
	
	$ gcc -o assign1.o assign1.c
	
	--> Then, We create the Library libassign1.a using this command :
	
	$ ar rcs libassign1.a assign1.o 
	
	*/
	
	
	return 0;

}

