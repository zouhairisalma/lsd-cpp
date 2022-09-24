#include <stdio.h>



/*Functions*/


//For an integer
void check_msb(int x )
{
	int g=x>>31;
	if(g==1)
		printf("msb is set");
	else
		printf("msb is not set");
		
	printf("\n");
	return;

}

//For a character
void check_msb_char(char x )
{
	int g=x>>7;
	if(g==1)
		printf("msb is set");
	else
		printf("msb is not set");
		
	printf("\n");
	return;

}

//For a character
void print_bits(unsigned char x)
{
	for(int i=0;i<8;i++)
	{
		if ( ((x>>8-i-1) & 1) ==1)
			printf("1");
		else 
			printf("0");
	}	
	printf("\n");
	
	return;	

}

//For an integer
void print_bits_int(int x)
{
	for(int i=0;i<32;i++)
	{
		if ( ((x>>32-i-1) & 1) ==1)
			printf("1");
		else 
			printf("0");
	}	
	printf("\n");
	
	return;	

}

void print_nth_byte(int m, int n)
{
	int S=n*8;
	for (int i=0;i<8;i++)
	{
		if(((m>>S-i-1 )&1 )==1)
			printf("1");
		else
			printf("0");
	
	}
	
	
	printf("\n");
	return;

}



/*
	
	For exercise 5:
	
	
	
	--> first of all, in our Terminal, we create the object file lib_assignment_1.o by compiling lib_assignment_1.c :
	
	$ gcc -c  libasg1.c
	
	--> Then, We create the static Library libassign1.a using this command :
	
	$ ar rcs libasg1.a libasg1.o	 
	
	
	
	
	--> then to use it in a separate program : testing_my_lib.c we type the following command in our Terminal, given that the library is stocked in the same directory (we suppose that all attached files are in the same directory) :
	
	$ gcc -o test testing_my_lib.c  -L. -lasg1.o
	
	$ ./test



*/



