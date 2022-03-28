#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 1)
	{
		printf("open() error");
		exit(1);
	}
	printf("FD : %d\n", fd);
	close(fd);
	return (0);
}
