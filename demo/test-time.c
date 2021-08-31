#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

//msで表示が目的

int	what_time();
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	main(void)
{
	struct timeval tv;
	struct timeval tv2;

	gettimeofday(&tv, NULL);
	usleep(200);
	printf("s = %ld\n", tv.tv_sec);
	printf("ms = %d\n", tv.tv_usec / 1000);
	printf("s+ms = %ld\n", tv.tv_sec * 1000 + tv.tv_usec / 1000);
	gettimeofday(&tv2, NULL);
	printf("2 s = %ld\n", tv2.tv_sec);
	printf("2 ms = %d\n", tv2.tv_usec / 1000);
	printf("2 s+ms = %ld\n", tv2.tv_sec * 1000 + tv2.tv_usec / 1000);

	return (0);
}
