/*
	Anshul Verma, 19/78065

	a) same program, same code
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int a;
	a = fork();
	if (a < 0)
	{
		printf("child process could not be created");
		exit(-1);
	}
	else
	{
		printf("My ID is %d, My parent is %d\n", getpid(), getppid());
	}
	return 0;
}