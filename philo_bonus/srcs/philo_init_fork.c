/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:00:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/28 18:14:49 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result	err_philo_init_fork(t_philo *philo, int last_index, char *msg)
{
	int	i;

	pthread_mutex_destroy(&philo->died);
	i = 0;
	while (i < last_index)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		++i;
	}
	ft_err(msg);
	return (FAILURE);
}

t_result	philo_init_fork(t_philo *philo)
{
	int	total_philo;
	int	i;

	total_philo = philo->num_philo_and_fork;
	if (pthread_mutex_init(&philo->died, NULL))
		return (ft_err(ERRINITMUTEX));
	philo->fork = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * total_philo);
	if (!philo->fork)
		return (err_philo_init_fork(philo, 0, CANTALLOCATE));
	i = -1;
	while (++i < total_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL))
			return (err_philo_init_fork(philo, i, ERRINITMUTEX));
	}
	i = -1;
	while (++i < total_philo)
	{
		philo->men[i].right = &philo->fork[i];
		philo->men[i].left = &philo->fork[(i - 1 + total_philo) % total_philo];
		philo->men[i].died = &philo->died;
	}
	return (SUCCESS);
}
