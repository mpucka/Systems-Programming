#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>


int Morph(char *number);

int main(int argc, char *argv[])

{

	Morph(argv[1]);

}

int Morph(char *number) 
{ 
	char *args []={"isPrime",number, NULL};
	execvp("./isPrime",args);
	//printf("Is here\n");
	//return 0;
	
	/*
	char *number[3];
	number[0]=isPrime;
	number[1]="-u";
	number[2]=NULL;

	execvp(number[0],number);
	
	*/
	
}




