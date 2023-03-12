#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	if (argc == 1) return 0;
	unsigned char out;
	int fd = open("/dev/random", O_RDONLY);
	read(fd, &out, 1);
	close(fd);
	out %= argc - 1;
	++out;
	printf(argv[out]);
	return 0;
}
