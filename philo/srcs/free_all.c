/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:03:51 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/28 18:14:14 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	destroy_philo(t_philo *philo)
{
	int i;

	pthread_mutex_destroy(&philo->died);
	i = 0;
	while (i < philo->num_philo_and_fork)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		++i;
	}
	pthread_mutex_destroy(&philo->eat);
}

int	free_all(t_philo *philo)
{
	free_set((void **)&philo->fork, NULL);
	free_set((void **)&philo->men, NULL);
	return (1);
}
