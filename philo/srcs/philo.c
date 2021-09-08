/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:59:19 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/08 23:03:56 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//出力してみる
void	*philosopher(void *v)
{
	t_philo *philo;

	philo = (t_philo *)v;
	if ((philo->id  - 1 ) % 2)
		usleep(200);
	while (1)
	{
		//eat
		if (eat(philo) != 0)
			break;
		//sleep
		pthread_mutex_lock(&g_print);
		printf("%ld %d is sleeping\n", what_time(), philo->id);
		pthread_mutex_unlock(&g_print);
		usleep (100000);
		//think
		pthread_mutex_lock(&g_print);
		printf("%ld %d is thinking\n", what_time(), philo->id);
		pthread_mutex_unlock(&g_print);
	}
	return (NULL);
}
