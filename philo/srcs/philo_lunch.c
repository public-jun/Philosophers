/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/29 16:08:29 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_print_status(t_man *man, const char *msg)
{
	pthread_mutex_lock(man->died);
	if (*man->is_alive)
		printf("%lld %d %s\n", what_time(), man->id, msg);
	pthread_mutex_unlock(man->died);
}

void	philo_die(t_man *man)
{
	pthread_mutex_lock(man->died);
	if (*man->is_alive)
	{
		*man->is_alive = false;
		printf("%lld %d %s\n", what_time(), man->id, DIE);
	}
	pthread_mutex_unlock(man->died);
}

void	philo_take_fork(t_man *man)
{
	if (man->id % 2)
		pthread_mutex_lock(man->left);
	else
	{
		usleep(300);
		pthread_mutex_lock(man->right);
	}
	philo_print_status(man, TAKEFORK);
	if (man->id % 2)
	{
		usleep(300);
		pthread_mutex_lock(man->right);
	}
	else
		pthread_mutex_lock(man->left);
	philo_print_status(man, TAKEFORK);
}

void	philo_eat_spaghetti(t_man *man)
{
	pthread_mutex_lock(man->died);
	man->time_to_start_eat = what_time();
	if (*man->is_alive)
		printf("%lld %d %s\n", man->time_to_start_eat, man->id, EAT);
	pthread_mutex_unlock(man->died);
	while (*man->is_alive)
	{
		// check die
		if (waiting_time(man, man->time_to_start_eat, man->time_to_eat))
			break;
	}
	pthread_mutex_unlock(man->left);
	pthread_mutex_unlock(man->right);
}

void *lunch(void *p)
{
	t_man *man;

	man = p;
	// printf("id: %d\n", man->id);
	// take fork
	philo_take_fork(man);
	// eat
	philo_eat_spaghetti(man);
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
