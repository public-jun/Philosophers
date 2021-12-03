/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:43:54 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 00:36:00 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*dead_monitor(void *p)
{
	t_man	*man;

	man = (t_man *)p;
	pthread_detach(man->dead_monitor);
	man->is_get_fork = false;
	while (!man->is_get_fork)
	{
		is_die(man, what_time());
		usleep(300);
	}
	return (NULL);
}

void	count_philo_must_ate_monitor(t_philo *philo)
{
	int	i;

	i = 0;
	while (true)
	{
		sem_wait(philo->eat);
		++i;
		if (i == philo->num_philo_and_fork)
		{
			sem_wait(philo->died);
			kill_all_philo(philo, -1);
			exit(1);
		}
	}
}

t_result	create_eat_count_watcher(t_philo *philo)
{
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		return (FAILURE);
	else if (c_pid == 0)
		count_philo_must_ate_monitor(philo);
	philo->eat_count_pid = c_pid;
	return (SUCCESS);
}

void	wait_die(t_philo *philo)
{
	pid_t	die_pid;
	int		status;
	int		i;

	i = -1;
	die_pid = waitpid(-1, &status, 0);
	if (philo->is_must_eat && WIFEXITED(status) && WEXITSTATUS(status) == 2)
		kill_all_philo(philo, -1);
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		kill_all_philo(philo, die_pid);
		if (philo->is_must_eat)
			kill(philo->eat_count_pid, SIGKILL);
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
}
