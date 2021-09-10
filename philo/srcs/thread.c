/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:31:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/11 00:02:09 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int thread_process(t_trunk *trunk, int num_philo)
{
	int ret;
	int i;
	t_philo *tmp_philo;
	t_fork *tmp_fork;

	i = 0;
	tmp_philo = &(trunk->philo[i]);
	while (i < num_philo)
	{
		//philo thread作成
		ret = pthread_create(&(tmp_philo->thread), NULL, philosopher, (void *)tmp_philo);
		if (ret != 0)
			return (-1);
		usleep(100);
		tmp_philo = &(trunk->philo[++i]);
	}
	i = 0;
	tmp_philo = &(trunk->philo[i]);
	while (i < num_philo)
	{
		ret = pthread_join(tmp_philo->thread, NULL);
		if (ret != 0)
			return (-1);
		tmp_philo = &(trunk->philo[++i]);
	}
	pthread_mutex_destroy(&g_print);
	pthread_mutex_destroy(&g_dead);
	i = 0;
	tmp_fork = &trunk->fork[i];
	while (i < num_philo)
	{
		pthread_mutex_destroy(&(tmp_fork->mutex_fork));
		tmp_fork = &(trunk->fork[++i]);
	}
	return (0);
}
