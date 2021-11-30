/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:55:45 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/29 20:00:58 by jnakahod         ###   ########.fr       */
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

void	only_one_philo(t_man *man)
{
	philo_print_status(man, TAKEFORK);
	man->time_to_start_eat = what_time();
	philo_wait(man, man->time_to_start_eat, man->time_to_die);
}

void	philo_wait(t_man *man, long long standard, int wait_time)
{
	while (*man->is_alive)
	{
		if (waiting(man, standard, wait_time))
			break ;
		usleep(500);
	}
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
