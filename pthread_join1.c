/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_join1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:20:08 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/20 15:48:10 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void	*f1();
void	*f2();

int	main(void)
{
	pthread_t	thread1, thread2;
	int	ret1, ret2;

	ret1 = pthread_create(&thread1, NULL, (void *)f1, NULL);
	ret2 = pthread_create(&thread2, NULL, (void *)f2, NULL);
	if (ret1 != 0)
		err(EXIT_FAILURE, "can not create thread 1: %s", strerror(ret1));
	if (ret2 != 0)
		err(EXIT_FAILURE, "can not create thread 2: %s", strerror(ret2));

	void	*status1, *status2;
	ret1 = pthread_join(thread1, &status1);
	if (ret1 != 0)
		errc(EXIT_FAILURE, ret1, "can not join thread 1");
	ret2 = pthread_join(thread2, &status2);
	if (ret2 != 0)
		errc(EXIT_FAILURE, ret2, "can not join thread 2");

	printf("status1 = %p, %d\n", status1, *(int *)status1);
	printf("status2 = %p, %d\n", status2, *(int *)status2);
	free(status1);
	free(status2);

	exit(EXIT_SUCCESS);
}

void	*Malloc(size_t size)
{
	void *p;

	p = (void *)malloc(size);
	if (!p)
		err(EXIT_FAILURE, "malloc error: %lu", size);
	return p;
}

void	*f1()
{
	void	*p = Malloc(sizeof(int));
	printf("%s: %p\n", __func__, p);
	*(int *)p = 123;
	pthread_exit(p);
}

void	*f2()
{
	void	*p = Malloc(sizeof(int));
	printf("%s: %p\n", __func__, p);
	*(int *)p = 456;
	pthread_exit(p);
}
