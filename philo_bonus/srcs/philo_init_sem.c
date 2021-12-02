/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_sem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:00:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 14:36:05 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result	new_semaphore(sem_t **dst, const char *name, int value)
{
	sem_unlink(name);
	*dst = sem_open(name, O_CREAT, 0600, value);
	sem_unlink(name);
	return (SUCCESS);
}



t_result	philo_init_sem(t_philo *philo)
{
	int	total_philo;
	sem_t	*taking;
	int		i;

	total_philo = philo->num_philo_and_fork;
	taking = NULL;
	new_semaphore(&philo->fork, "/fork", total_philo);
	new_semaphore(&philo->eat, "/eat", 0);
	new_semaphore(&philo->died, "/died", 1);
	new_semaphore(&taking, "/taking", 1);
	i = -1;
	while (++i < total_philo)
	{
		philo->men[i].fork = philo->fork;
		philo->men[i].died = philo->died;
		philo->men[i].eat = philo->eat;
		philo->men[i].taking = taking;
	}
	return (SUCCESS);
}
