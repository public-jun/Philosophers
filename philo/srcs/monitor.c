/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:56:48 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/26 22:17:39 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*monitor(void *v)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo *)v;
	while (g_is_dead == false)
	{
		now = what_time();
		if (now - philo->eat_start >= philo->config.time_to_die)
		{
			pthread_mutex_lock(&g_print);
			if(g_is_dead == false)
				printf("%ld %d died\n", now, philo->id);
			g_is_dead = true;
			pthread_mutex_unlock(&g_print);
			usleep(500);
		}
	}
	return (NULL);
}
