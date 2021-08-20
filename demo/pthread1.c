/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:40:45 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/20 11:36:59 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <err.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void f1(void);

int	main(void)
{
	pthread_t	thread1;
	int	ret1;

	ret1 = pthread_create(&thread1, NULL, (void *)f1, NULL);
	if (ret1 != 0)
		err(EXIT_FAILURE, "can not create thread 1: %s", strerror(ret1));
	printf("execute pthread_joic\n");
	ret1 = pthread_join(thread1, NULL);
	if (ret1 != 0)
		errc(EXIT_FAILURE, ret1, "can not join thread 1");
	printf("join'n");
	return (0);
}

void	f1(void)
{
	size_t i;

	for(i = 0; i< 4; i++)
		printf("Doing one thing\n");
}
