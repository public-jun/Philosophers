/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:10:28 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/12 18:28:52 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int sleeping(t_philo *philo)
{
	long start_time;

	start_time = what_time();
	pthread_mutex_lock(&g_print);
	if (g_is_dead == false)
		printf("%ld %d is sleeping\n", start_time, philo->id);
	pthread_mutex_unlock(&g_print);
	if (g_is_dead == true)
		return (-1);
	while (!waiting_time(start_time, philo->config.time_to_sleep))
	{
		if (g_is_dead == true)
			return (-1);
		usleep(1000);
	}
	return (0);
}
