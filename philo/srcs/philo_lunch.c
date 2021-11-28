/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/28 20:34:23 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void *lunch(void *p)
{
	t_man *man;

	man = p;
	// printf("id: %d\n", man->id);
	// take fork
	// eat
	// sleep
	// think
	return (NULL);
}

void	philo_lunch(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num_philo_and_fork)
	{
		pthread_create(&philo->men[i].thread, NULL, lunch, &philo->men[i]);
	}
	i = -1;
	while (++i < philo->num_philo_and_fork)
		pthread_join(philo->men[i].thread, NULL);
}
