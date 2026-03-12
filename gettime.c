#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct timeval	time;
	struct timeval	time2;
	long			elapsed;

	gettimeofday(&time, NULL);
	usleep(100);
	gettimeofday(&time2, NULL);
	elapsed = (time2.tv_sec - time.tv_sec) * 1000000 +
	(time2.tv_usec - time.tv_usec);
	printf("%ld", elapsed);
	return 0;
}

