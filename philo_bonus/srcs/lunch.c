/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 00:35:36 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_take_fork(t_man *man)
{
	sem_wait(man->taking);
	pthread_create(&man->dead_monitor, NULL, dead_monitor, man);
	sem_wait(man->fork);
	philo_print_status(man, TAKEFORK);
	sem_wait(man->fork);
	man->is_get_fork = true;
	philo_print_status(man, TAKEFORK);
	sem_post(man->taking);
}

void	philo_eat_spaghetti(t_man *man)
{
	is_die(man, what_time());
	sem_wait(man->died);
	man->time_to_start_eat = what_time();
	printf("%lld %d %s\n", man->time_to_start_eat, man->id, EAT);
	sem_post(man->died);
	philo_wait(man, man->time_to_start_eat, man->time_to_eat);
	++man->eat_count;
	if (man->eat_count == man->num_of_times_each_philo_must_eat)
		sem_post(man->eat);
	sem_post(man->fork);
	sem_post(man->fork);
}

void	philo_sleep(t_man *man)
{
	long long	time_to_start_sleep;

	sem_wait(man->died);
	time_to_start_sleep = what_time();
	printf("%lld %d %s\n", time_to_start_sleep, man->id, SLEEP);
	sem_post(man->died);
	philo_wait(man, time_to_start_sleep, man->time_to_sleep);
}

void	*lunch(void *p)
{
	t_man	*man;

	man = p;
	man->time_to_start_eat = what_time();
	while (true)
	{
		philo_take_fork(man);
		philo_eat_spaghetti(man);
		philo_sleep(man);
		philo_print_status(man, THINK);
	}
}

void	lunch_alone(t_man *man)
{
	man->time_to_start_eat = what_time();
	sem_wait(man->fork);
	philo_print_status(man, TAKEFORK);
	philo_wait(man, man->time_to_start_eat, man->time_to_die);
}
