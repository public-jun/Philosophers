/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_sem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:00:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 00:58:18 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result	philo_init_sem(t_philo *philo)
{
	int	total_philo;
	sem_t	*taking;
	int		i;

	total_philo = philo->num_philo_and_fork;
	sem_unlink("/fork");
	philo->fork = sem_open("/fork", O_CREAT, 0600, total_philo);
	sem_unlink("/fork");
	sem_unlink("/eat");
	philo->eat = sem_open("/eat", O_CREAT, 0600, 0);
	sem_unlink("/eat");
	sem_unlink("/taking");
	taking = sem_open("/taking", O_CREAT, 0600, 1);
	sem_unlink("/taking");
	sem_unlink("/died");
	philo->died = sem_open("/died", O_CREAT, 0600, 1);
	sem_unlink("/died");
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
