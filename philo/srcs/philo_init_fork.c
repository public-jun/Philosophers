/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:00:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 23:31:13 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result	philo_init_fork(t_philo *philo)
{
	int	total_philo;

	total_philo = philo->num_philo_and_fork;
	philo->fork = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * total_philo);
	if (!philo->fork)
		return (ft_err(CANTALLOCATE));

	return (SUCCESS);
}
