/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/10 20:59:25by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	eating(t_philo *philo)
{
	philo->eat_start = what_time();
	pthread_mutex_lock(&g_print);
	if (g_is_dead == false)
	{
		printf("%ld %d is eating\n", philo->eat_start, philo->id);
		philo->eat_count++;
	}
	pthread_mutex_unlock(&g_print);
	while (!waiting_time(philo->eat_start, philo->config.time_to_eat))
	{
		if (g_is_dead == true)
			break;
		usleep(1000);
	}
	pthread_mutex_unlock(&(philo->right->mutex_fork));
	pthread_mutex_unlock(&(philo->left->mutex_fork));
	usleep(500);
	if (g_is_dead == true)
		return (-1);
	return (0);
}

void	take_a_fork(t_fork *hand, t_philo *philo)
{
	pthread_mutex_lock(&(hand->mutex_fork));
	pthread_mutex_lock(&g_print);
	if (g_is_dead == false)
		printf("%ld %d has taken a fork\n", what_time(), philo->id);
	pthread_mutex_unlock(&g_print);
}

int	eat(t_philo *philo)
{
	//take left fork
	take_a_fork(philo->left, philo);
	// //take right fork
	take_a_fork(philo->right, philo);
	if (eating(philo) != 0)
		return (-1);
	return (0);
}
