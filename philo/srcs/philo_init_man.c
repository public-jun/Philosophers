/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_man.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:50:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 23:28:31 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_man(t_man *man)
{
	man->num_philo_and_fork = 0;
	man->time_to_die = 0;
	man->time_to_eat = 0;
	man->time_to_sleep = 0;
	man->num_of_times_each_philo_must_eat = 0;
	man->is_must_eat = false;
	man->id = 0;
	man->left = NULL;
	man->right = NULL;
	man->eat_count = 0;
	man->died = NULL;
	man->eat = NULL;
	man->least_ate_count = NULL;
	man->is_fin = NULL;
}

t_result	philo_init_man(t_philo *philo)
{
	t_man	man;
	size_t	i;

	philo->men = (t_man *)malloc(sizeof(t_man) * philo->num_philo_and_fork);
	if (!philo->men)
		return (ft_err(CANTALLOCATE));
	init_man(&man);
	man.num_philo_and_fork = philo->num_philo_and_fork;
	man.time_to_die = philo->time_to_die;
	man.time_to_eat = philo->time_to_eat;
	man.time_to_sleep = philo->time_to_sleep;
	man.num_of_times_each_philo_must_eat = \
			philo->num_of_times_each_philo_must_eat;
	man.is_must_eat = philo->is_must_eat;
	i = 0;
	while (i < (size_t)philo->num_philo_and_fork)
	{
		man.id = i + 1;
		philo->men[i] = man;
		philo->men[i].is_fin = &philo->is_fin;
		++i;
	}
	return (SUCCESS);
}
