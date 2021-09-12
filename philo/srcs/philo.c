/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:59:19 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/12 11:51:31 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//出力してみる
void *philosopher(void *v)
{
	t_philo *philo;

	philo = (t_philo *)v;
	if (pthread_create(&(philo->death_monitor), NULL, monitor, (void *)philo))
		return (NULL);
	if (pthread_detach(philo->death_monitor))
		return (NULL);
	// if ((philo->id - 1) % 2)
	// 	usleep(500);
	while (1)
	{
		//eat
		if (eat(philo) != 0)
			break;
		if (sleeping(philo) != 0)
			break;
		//think
		pthread_mutex_lock(&g_print);
		if (g_is_dead == false)
			printf("%ld %d is thinking\n", what_time(), philo->id);
		pthread_mutex_unlock(&g_print);
	}
	return (NULL);
}
