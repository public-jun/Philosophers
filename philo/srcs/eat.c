/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/07 23:07:59 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	eating(t_philo *philo)
{
	struct timeval	tv;
	int				standard_time;

	if (g_is_dead == false)
	{
		gettimeofday(&tv, NULL);
		philo->eat_start = tv;
		pthread_mutex_lock(&g_print);
		printf("%d %d  is eating\n", tv.tv_usec / 1000, philo->id);
		pthread_mutex_unlock(&g_print);
		standard_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}
	else
		return (-1);
	while (!waiting_time(standard_time, philo->config.time_to_eat))
	{
		if (g_is_dead == true)
			return (-1);
		usleep(200);
	}
	philo->eat_count++;
	philo->right->is_use = false;
	philo->left->is_use = false;
	return (0);
}

int	take_a_fork(t_fork *hand, t_philo *philo)
{
	if (hand->is_use == false)
	{
		pthread_mutex_lock(&(hand->mutex_fork));
		hand->is_use = true;
		if (g_is_dead == false)
		{
			pthread_mutex_lock(&g_print);
			printf("%d %d has taken a fork\n", what_ms_time(), philo->id);
			pthread_mutex_unlock(&g_print);
		}
		pthread_mutex_unlock(&(hand->mutex_fork));
		return (1);
	}
	return (0);
}

int	wait_fork(t_fork *hand, t_philo *philo)
{
	while (!take_a_fork(hand, philo))
	{
		if (g_is_dead == true)
			return (-1);
		usleep(200);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	//take left fork
	if (wait_fork(philo->left, philo) < 0)
		return (-1);
	//take right fork
	if (wait_fork(philo->right, philo) < 0)
		return (-1);
	//eat
	if (eating(philo) != 0)
		return (-1);
	return (0);
}
