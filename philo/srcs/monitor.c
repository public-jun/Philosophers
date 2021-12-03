/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:46:22 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/03 22:46:48 by jnakahod         ###   ########.fr       */
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
	men = philo->men;
	i = -1;
	while (philo->is_alive)
	{
		while (++i < philo->num_of_times_each_philo_must_eat)
		{
			now = what_time();
			is_die(&men[i], now);
		}
		i = -1;
	}
	return (NULL);
}
