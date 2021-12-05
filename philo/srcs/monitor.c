/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:46:22 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/05 20:05:13 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*monitor(void *p)
{
	t_philo		*philo;
	t_man		*men;
	int			i;
	long long	now;

	philo = (t_philo *)p;
	pthread_detach(philo->th_monitor);
	men = philo->men;
	while (philo->is_alive)
	{
		i = -1;
		while (++i < philo->num_philo_and_fork)
		{
			now = what_time();
			is_die(&men[i], now);
		}
	}
	return (NULL);
}
