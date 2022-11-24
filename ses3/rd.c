#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


#define BUFFER_SIZE 10
#define N 500

/*Prototypes*/
char* do_concatenate(char* A, char B[BUFFER_SIZE],int n,int m);
char* read_lines(int fd);

/*Functions*/
char* read_lines(int fd)
{
	printf("WITH BUFFER SIZE=%d\n\n\n",BUFFER_SIZE );

	char B[N];
	char *A=(char*)malloc(sizeof(char)*N);
	int m=0;
	static char buffer[BUFFER_SIZE];	
	int n=read(fd,buffer,BUFFER_SIZE);   
	
	int z=0;
	int i=0;
	while (n!=-1 && n!=0)
	{	
		
		while (i<n)// testing if the character '\n' is found in the buffer 
		{
			if (buffer[i]=='\n')
			{
				z=1;// if the '\n' is found z=1 else z=0 (its initial value)				
				break;
			}
			i++;
		}
		
	
		
		if (z==1 && buffer[n-1]=='\n') // the character '\n' found in the buffer and is stored at its end 
		{
			A=do_concatenate(A,buffer,n,m);
			m+=n;
			
			break;
		}	 
		if(z==1 && buffer[n-1]!='\n')// The character '\n' found in the buffer but there are more characters after it which araen't part of our read line 
		{
			
			A=do_concatenate(A,buffer,i+1,m);
			
			m+=i+1;
			/*
			for(int j=0;j<BUFFER_SIZE-i-1 ;j++)/ 
			{
				B[j]=buffer[i+1+j];
			}*/
			//In B is stored what comes after '\n' in the buffer for a further call of the function 
			break;
		}



		
		else // we couldn't find the '\n' so we need to read more from the file 
		{
			A=do_concatenate(A,buffer,n,m);  
			m+=n;
			n=read(fd,&buffer,BUFFER_SIZE);
			i=0;
		
		}	
		
	}
	
	
	char * C=NULL;
	if (z==1)
	{
		C =(char*)malloc(sizeof(char)*(m+i));
		for (int j=0;j<m+i;j++)
			C[j]=A[j];
	}
	free(A);
	return C;
}



/////////******************************************************************************************//////////

//THIS FUNCTION  to : Copy Buffer content into A with m the index from which we start pasting into A and n is the number of characters to copy


char* do_concatenate(char* A,char B[BUFFER_SIZE],int n,int m) 
{
    for (int i =m; i<m+n;i++)
        A[i]=B[i-m];       
    return A;
}



int main()
{
	int fd = open("test.txt",O_RDONLY);
	char* A=read_lines(fd);	
	printf("%s",A);	
	return 0;
}


