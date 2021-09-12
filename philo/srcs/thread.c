/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:31:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/12 18:40:03 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int thread_process(t_trunk *trunk, int num_philo)
{
	// int ret;
	int i;
	t_philo *tmp_philo;
	t_fork *tmp_fork;

	i = 0;
	tmp_philo = &(trunk->philo[i]);
	while (i < num_philo)
	{
		//philo thread作成
		if (pthread_create(&(tmp_philo->thread), NULL, philosopher, (void *)tmp_philo))
			return (-1);
		if (pthread_detach(tmp_philo->thread))
			return (-1);
		i += 2;
		tmp_philo = &(trunk->philo[i]);
	}
	usleep(400);
	i = 1;
	tmp_philo = &(trunk->philo[i]);
	while (i < num_philo)
	{
		//philo thread作成
		if (pthread_create(&(tmp_philo->thread), NULL, philosopher, (void *)tmp_philo))
			return (-1);
		if (pthread_detach(tmp_philo->thread))
			return (-1);
		i += 2;
		tmp_philo = &(trunk->philo[i]);
	}
	// i = 0;
	// tmp_philo = &(trunk->philo[i]);
	// while (i < num_philo)
	// {
	// 	ret = pthread_join(tmp_philo->thread, NULL);
	// 	if (ret != 0)
	// 		return (-1);
	// 	tmp_philo = &(trunk->philo[++i]);
	// }
	while (1)
	{
		if (g_is_dead == true)
			break;
	}
	usleep(10000);
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
