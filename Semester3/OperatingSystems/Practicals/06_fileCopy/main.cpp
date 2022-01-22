/*
	6. Write a program to copy a source file into the target file and display the target file using system calls.
	
	Author: Anshul Verma
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "Correct Usage: ./main <src_filename> <src_filename>\n");
		return -1;
	}
	
	char buf;
	int fd1, fd2, n;
	if ((fd1 = open(argv[1], O_RDONLY)) < 0)
	{
		fprintf(stderr, "Could not read %s\n", argv[1]);
		return 2;
	}

	if ((fd2 = creat(argv[2], 0666)) < 0)
	{
		fprintf(stderr, "Could not write to %s\n", argv[2]);
    		return 2;
	}
	
	while ((n = read(fd1, &buf, 1)) > 0)
		write(fd2, &buf, 1);

	printf("Copied contents of %s to %s\n", argv[1], argv[2]);

	close(fd1);
	close(fd2);
	return 0;
}
