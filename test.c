/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:19:52 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/19 22:31:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int	a = 0;
pthread_mutex_t	mutex;

void	*func_thread(void *p)
{
	printf("start %d\n", *(int *)p);

	int i = 0;
	for (i = 0; i < 10000; i++)
	{
		pthread_mutex_lock(&mutex);
		int next = a + 1;
		int now = a;
		a = next;
		pthread_mutex_unlock(&mutex);
		if (now + 1 != next)
		{
			printf("other thread change %d %d\n", a+1, next);
		}
	}
	return (0);
}

int	main(void)
{
	pthread_mutex_init(&mutex, NULL);
	printf("test\n");

	int	b = 42;

	pthread_t	pthread;
	pthread_create(&pthread, NULL, &func_thread, &b);

	int i = 0;
	for (i = 0; i < 10000; i++)
	{
		pthread_mutex_lock(&mutex);
		int next = a + 1;
		int	now = a;
		a = next;
		pthread_mutex_unlock(&mutex);
		if (now + 1 != next)
		{
			printf("other thread change %d %d\n", a + 1, next);
		}
	}
	pthread_join(pthread, NULL);
	printf("a=%d\n", a);

	return (0);
}
