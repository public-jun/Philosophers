/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_seat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:52:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 20:05:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static pid_t	philo_take_seat(t_man *man, bool is_alone)
{
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid == -1)
		return (c_pid);
	else if (c_pid == 0)
	{
		if (is_alone)
			lunch_alone(man);
		else
			lunch(man);
	}
	return (c_pid);
}

static void	kill_zombie(t_philo *philo, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		kill(philo->pids[i], SIGKILL);
		++i;
	}
}

static t_result	err_philo_take_seat(t_philo *philo, int last)
{
	printf("errr philo take seat\n");
	kill_zombie(philo, last);
	ft_err(ERRFORK);
	return (FAILURE);
}

t_result	philo_lunch(t_philo *philo)
{
	int		i;
	bool	is_alone;

	i = -1;
	is_alone = false;
	if (philo->num_philo_and_fork == 1)
		is_alone = true;
	while (++i < philo->num_philo_and_fork)
	{
		philo->pids[i] = philo_take_seat(&philo->men[i], is_alone);
		if (philo->pids[i] == -1)
			return (err_philo_take_seat(philo, i));
	}
	if (philo->is_must_eat)
		philo->eat_count_pid = create_eat_count_watcher(philo);
	wait_die(philo);
	close_philo_sem(philo);
	return (SUCCESS);
}
