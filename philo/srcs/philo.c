/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:59:19 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/07 23:03:54 by jnakahod         ###   ########.fr       */
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
		printf("%d %d is sleeping\n", what_ms_time(), philo->id);
		pthread_mutex_unlock(&g_print);
		usleep (100000);
		//think
		pthread_mutex_lock(&g_print);
		printf("%d %d is thinking\n", what_ms_time(), philo->id);
		pthread_mutex_unlock(&g_print);
	}
	return (NULL);
}

	// pthread_mutex_lock(&g_print);
	// printf("id = %d\n", philo->id);
	// printf("num %d\n", philo->config.num_philo_and_fork);
	// printf("die %d\n", philo->config.time_to_die);
	// printf("eat %d\n", philo->config.time_to_eat);
	// printf("sleep %d\n", philo->config.time_to_sleep);
	// pthread_mutex_unlock(&g_print);
