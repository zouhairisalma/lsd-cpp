#include <stdio.h>

/*Prototypes*/
void check_msb(int );
void check_msb_char(char);
void print_bits(unsigned char);
void print_bits_int(int );
void print_bits_int(int );


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










