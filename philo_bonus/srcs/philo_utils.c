/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:55:45 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 19:48:19 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	kill_all_philo(t_philo *philo, pid_t except)
{
	int	i;

	i = 0;
	while (i < philo->num_philo_and_fork)
	{
		if (except != philo->pids[i])
			kill(philo->pids[i], SIGKILL);
		++i;
	}
}

void	philo_print_status(t_man *man, const char *msg)
{
	sem_wait(man->died);
	printf("%lld %d %s\n", what_time(), man->id, msg);
	sem_post(man->died);
}

void	only_one_philo(t_man *man)
{
	philo_print_status(man, TAKEFORK);
	man->time_to_start_eat = what_time();
	philo_wait(man, man->time_to_start_eat, man->time_to_die);
}

void	philo_wait(t_man *man, long long standard, int wait_time)
{
	while (true)
	{
		if (waiting(man, standard, wait_time))
			break ;
		usleep(500);
	}
}
