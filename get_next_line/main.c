#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	while (0 < (fd = open("test.txt", O_RDWR)))
	{
		printf("fd: %d\n", fd);
		printf("%s\n", get_next_line(fd)); 
	}
}
