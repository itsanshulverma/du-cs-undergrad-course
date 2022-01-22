/*
	Written by Anshul Verma, 19/78065
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Correct Usage: ./main <filename>\n");
		return -1;
	}
	
	struct stat dt;
	
	printf("\nFile Info\n");
	printf("--------------------\n");
	printf("Name: %s\n", argv[1]);
	printf("UserID: %d\n", dt.st_uid);
	printf("GroupID: %d\n", dt.st_gid);
	printf("File Type: %d\n", S_IFMT);
	printf("Directory: %s\n", S_IFDIR ? "Yes" : "No");
	printf("Regular File: %s\n", S_IFREG ? "Yes" : "No");
	printf("Last access time: %ld\n", dt.st_atime);
	printf("Last modified time: %ld\n", dt.st_mtime);
	printf("User Permissions:\n");
	printf("  Read: %s\n", S_IRUSR ? "Yes" : "No");
	printf("  Write: %s\n", S_IWUSR ? "Yes" : "No");
	printf("  Execute: %s\n", S_IXUSR ? "Yes" : "No");
	printf("Group Permissions:\n");
	printf("  Read: %s\n", S_IRGRP ? "Yes" : "No");
	printf("  Write: %s\n", S_IWGRP ? "Yes" : "No");
	printf("  Execute: %s\n", S_IXGRP ? "Yes" : "No");
	printf("Others Permissions:\n");
	printf("  Read: %s\n", S_IROTH ? "Yes" : "No");
	printf("  Write: %s\n", S_IWOTH ? "Yes" : "No");
	printf("  Execute: %s\n\n", S_IXOTH ? "Yes" : "No");
}
