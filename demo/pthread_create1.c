/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:40:22 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/20 15:05:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void	*f1(void *p);
void	*f2(void *p);

int	main(void)
{
	pthread_t thread1, thread2;
	int	arg1 = 123, arg2 = 456;
	int ret1, ret2;
	ret1 = pthread_create(&thread1, NULL, (void *)f1, (void *) &arg1);
	ret2 = pthread_create(&thread2, NULL, (void *)f2, (void *) &arg2);

	if (ret1 != 0)
		err(EXIT_FAILURE, "can not create thread 1: %s", strerror(ret1));
	if (ret2 != 0)
		err(EXIT_FAILURE, "can not create thread 2: %s", strerror(ret2));

	ret1 = pthread_join(thread1, NULL);
	if (ret1 != 0)
		errc(EXIT_FAILURE, ret1, "can not join thread 1");

	ret2 = pthread_join(thread2, NULL);
	if (ret2 != 0)
		errc(EXIT_FAILURE, ret2, "can not join thread 2");

	printf("arg1 = %d\n", arg1);
	printf("arg2 = %d\n", arg2);

	exit(EXIT_SUCCESS);
}

void	*f1(void *p)
{
	int *ip = (int *)p;
	printf("%s: %d\n", __func__, *ip);
	*ip *= 2;
	pthread_exit(NULL);
}

void	*f2(void *p)
{
	int *ip = (int *)p;
	printf("%s: %d\n", __func__, *ip);
	*ip *= 2;
	pthread_exit(NULL);
}
