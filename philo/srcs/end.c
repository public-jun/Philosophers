/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:03:03 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/02 22:21:44 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	destroy_share(t_share *share)
{
	pthread_mutex_destroy(&(share->mutex_print));
	pthread_mutex_destroy(&(share->mutex_stop));
}

void	free_philo(t_trunk *trunk)
{
	free(trunk->philo);
	trunk->philo = NULL;
}

void	free_fork(t_trunk *trunk)
{
	int		i;
	t_fork	*tmp_fork;

	i = 0;
	tmp_fork = &(trunk->fork[i]);
	while (i < trunk->config.num_philo_and_fork)
	{
		pthread_mutex_destroy(&(tmp_fork->mutex_fork));
		tmp_fork = &(trunk->fork[++i]);
	}
	free(trunk->fork);
	trunk->fork = NULL;
}

void	end_process(t_trunk *trunk)
{
	destroy_share(&(trunk->share));
	free_philo(trunk);
	free_fork(trunk);
}
