#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// This is used instead of (s)rand because using srand(time(NULL)) will result in the same seed if in the same second
int randomint() {
	int fd = open("/dev/urandom", O_RDONLY);
	int out;
	read(fd, &out, sizeof(int));
	if (out < 0) out = 0 - out;
	close(fd);
	return out;
}

int main(int argc, char *argv[]) {
	if (argc <= 1) // need an argument
		return 1;
	int min, max, dif, out;
	max = atoi(argv[1]);
	if (argc > 2) { // if extra arg
		min = atoi(argv[2]);
	} else {
		min = 0;
	}
	if (max == min) {
		out = min;
	} else {
		if (min > max) { // make sure min < max
			dif = min;
			min = max;
			max = dif;
		}
		dif = abs(max - min) + 1;
		out = randomint();
		out %= dif; // make sure not above max		
		printf("%d %d %d %d\n", min, max, dif, out);
		out = min + out; // scale to min-max
	}
	printf("%d\n", out); // print
	return out;
}
