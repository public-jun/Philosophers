/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:15:28 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/28 16:42:13 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result	err_philo_init_eat(t_philo *philo)
{
	err_philo_init_fork(philo, philo->num_philo_and_fork, NULL);
	ft_err(ERRINITMUTEX);
	return (FAILURE);
}

t_result	philo_init_eat(t_philo *philo)
{
	int	total_philo;
	int	i;

	total_philo = philo->num_philo_and_fork;
	if (pthread_mutex_init(&philo->eat, NULL))
		return (err_philo_init_eat(philo));
	i = 0;
	while (i < total_philo)
	{
		philo->men[i].eat = &philo->eat;
		philo->men[i].least_philo_ate_count = &philo->least_philo_ate_count;
	}
	return (SUCCESS);
}
