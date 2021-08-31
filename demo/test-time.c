#include <stdio.h>
#include <sys/time.h>

//msで表示が目的

int	main(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("s = %ld\n", tv.tv_sec);
	printf("ms = %d\n", tv.tv_usec / 1000);
	return (0);
}
