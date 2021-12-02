/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:43:54 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 20:05:38 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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

pid_t	create_eat_count_watcher(t_philo *philo)
{
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		return (c_pid);
	else if (c_pid == 0)
		count_philo_must_ate_monitor(philo);
	return (c_pid);
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
