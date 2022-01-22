/*
	Anshul Verma, 19/78065

	c) different programs

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
	else if (a == 0)
	{
		execl("/bin/ls", "ls", NULL);
	}
	else
	{
		printf("Parent process : My ID is %d\n", getpid());
	}
	return 0;
}