/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/10 13:53:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int eating(t_philo *philo)
{
	if (g_is_dead == false)
	{
		philo->eat_start = what_time();
		pthread_mutex_lock(&g_print);
		printf("%ld %d is eating\n", philo->eat_start, philo->id);
		pthread_mutex_unlock(&g_print);
	}
	else
	{
		pthread_mutex_unlock(&(philo->left->mutex_fork));
		pthread_mutex_unlock(&(philo->right->mutex_fork));
		return (-1);
	}
	while (!waiting_time(philo->eat_start, philo->config.time_to_eat))
	{
		if (g_is_dead == true)
		{
			pthread_mutex_unlock(&(philo->left->mutex_fork));
			pthread_mutex_unlock(&(philo->right->mutex_fork));
			return (-1);
		}
		usleep(50);
	}
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->left->mutex_fork));
	pthread_mutex_unlock(&(philo->right->mutex_fork));
	return (0);
}

int take_a_fork(t_fork *hand, t_philo *philo)
{
	pthread_mutex_lock(&(hand->mutex_fork));
	if (g_is_dead == false)
	{
		pthread_mutex_lock(&g_print);
		printf("%ld %d has taken a fork\n", what_time(), philo->id);
		pthread_mutex_unlock(&g_print);
	}
	// pthread_mutex_unlock(&(hand->mutex_fork));
	return (1);
}

int wait_fork(t_fork *hand, t_philo *philo)
{
	// while (!take_a_fork(hand, philo))
	// {
	// 	if (g_is_dead == true)
	// 		return (-1);
	// 	usleep(50);
	// }
	take_a_fork(hand, philo);
	return (0);
}

int eat(t_philo *philo)
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
