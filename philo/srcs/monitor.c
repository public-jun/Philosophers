/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:56:48 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/10 00:04:47 by jnakahod         ###   ########.fr       */
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
		// eat_start の初期値は無視する
		if (now - philo->eat_start >= philo->config.time_to_die)
		{
			pthread_mutex_lock(&g_print);
			if(g_is_dead == false)
				printf("%ld %d died\n", now, philo->id);
			pthread_mutex_unlock(&g_print);
			g_is_dead = true;
		}
	}
	return (NULL);
}
