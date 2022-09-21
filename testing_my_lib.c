#include <stdio.h>


/*A program to test my Library*/

int main ()
{
	int u;
	printf("Give an integer");
	scanf("%d",&u);
	print_bits_int(u);
	
	return 0;
}

/*To compile this file we write the following command in the Terminal, -L to tell our gcc compiler that the library is stocked in the same directory, which is the case here ( All attached files in the assignment are in the same Directory ) :


$  gcc -o test testing_my_lib.o -L. -libassign1.a

$  ./test


*/


