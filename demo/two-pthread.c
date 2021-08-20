/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two-pthread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:38:32 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/20 11:56:13 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void	f1(void);
void	f2(void);

int	main(void)
{
	pthread_t thread1, thread2;
	int	ret1, ret2;

	ret1 = pthread_create(&thread1, NULL, (void *)f1, NULL);
	ret2 = pthread_create(&thread2, NULL, (void *)f2, NULL);

	if (ret1 != 0)
		err(EXIT_FAILURE, "can not create thread 1: %s", strerror(ret1));
	if (ret2 != 0)
		err(EXIT_FAILURE, "can not create thread 2: %s", strerror(ret2));

	printf("execute pthread_join thread1\n");
	ret1 = pthread_join(thread1, NULL);
	if (ret1 != 0)
		errc(EXIT_FAILURE, ret1, "can not join thread 1");
	printf("execute pthread_join thread2\n");
	ret2 = pthread_join(thread2, NULL);
	if (ret2 != 0)
		errc(EXIT_FAILURE, ret2, "can not join thread 2");
	printf("done\n");
	return (0);
}

void	f1(void)
{
	size_t	i;

	for (i = 0; i < 8; i++)
	{
		printf("Doing one thing\n");
		usleep(5);
	}
}

void	f2(void)
{
	size_t	i;

	for (i = 0; i< 4; i++)
	{
		printf("Doing another\n");
		usleep(5);
	}
}
