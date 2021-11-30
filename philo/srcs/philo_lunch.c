/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/30 15:16:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_take_fork(t_man *man)
{
	if (man->id % 2)
		pthread_mutex_lock(man->left);
	else
	{
		usleep(200);
		pthread_mutex_lock(man->right);
	}
	philo_print_status(man, TAKEFORK);
	if (man->id % 2)
	{
		usleep(200);
		pthread_mutex_lock(man->right);
	}
	else
		pthread_mutex_lock(man->left);
	philo_print_status(man, TAKEFORK);
}

void	philo_eat_spaghetti(t_man *man)
{
	is_die(man, what_time());
	pthread_mutex_lock(man->died);
	man->time_to_start_eat = what_time();
	if (*man->is_alive)
		printf("%lld %d %s\n", man->time_to_start_eat, man->id, EAT);
	pthread_mutex_unlock(man->died);
	philo_wait(man, man->time_to_start_eat, man->time_to_eat);
	++man->eat_count;
	if (*man->is_alive
		&& man->eat_count == man->num_of_times_each_philo_must_eat)
	{
		pthread_mutex_lock(man->eat);
		++*man->least_philo_ate_count;
		if (*man->least_philo_ate_count == man->num_philo_and_fork)
		{
			pthread_mutex_lock(man->died);
			*man->is_alive = false;
			pthread_mutex_unlock(man->died);
		}
		pthread_mutex_unlock(man->eat);
	}
	pthread_mutex_unlock(man->left);
	pthread_mutex_unlock(man->right);
}

void	philo_sleep(t_man *man)
{
	long long	time_to_start_sleep;

	pthread_mutex_lock(man->died);
	time_to_start_sleep = what_time();
	if (*man->is_alive)
		printf("%lld %d %s\n", time_to_start_sleep, man->id, SLEEP);
	pthread_mutex_unlock(man->died);
	philo_wait(man, time_to_start_sleep, man->time_to_sleep);
}

void	*lunch(void *p)
{
	t_man	*man;

	man = p;
	man->time_to_start_eat = what_time();
	while (*man->is_alive)
	{
		philo_take_fork(man);
		philo_eat_spaghetti(man);
		philo_sleep(man);
		philo_print_status(man, THINK);
	}
	return (NULL);
}

void	philo_lunch(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->num_philo_and_fork == 1)
	{
		only_one_philo(&philo->men[0]);
		return ;
	}
	while (++i < philo->num_philo_and_fork)
	{
		pthread_create(&philo->men[i].thread, NULL, lunch, &philo->men[i]);
	}
	i = -1;
	while (++i < philo->num_philo_and_fork)
		pthread_join(philo->men[i].thread, NULL);
}
