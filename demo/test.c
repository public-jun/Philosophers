/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:19:52 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/06 10:25:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int a = 0;
pthread_mutex_t mutex;

void *func_thread1(void *p)
{
	printf("start %d\n", *(int *)p);

	pthread_mutex_lock(&mutex);
	while (1);
	pthread_mutex_unlock(&mutex);
	return (0);
}

void *func_thread2(void *p)
{
	pthread_mutex_lock(&mutex);
	printf("aaa\n");
	pthread_mutex_unlock(&mutex);
	return (0);
}

int main(void)
{
	pthread_mutex_init(&mutex, NULL);
	printf("test\n");

	int b = 42;

	pthread_t pthread1, pthread2;
	pthread_create(&pthread1, NULL, &func_thread1, &b);
	pthread_create(&pthread2, NULL, &func_thread2, &b);
	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);

	return (0);
}
