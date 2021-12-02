/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 15:12:15 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_take_fork(t_man *man)
{
	sem_wait(man->taking);
	sem_wait(man->fork);
	philo_print_status(man, TAKEFORK);
	sem_wait(man->fork);
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

pid_t	philo_take_seat(t_man *man)
{
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid == -1)
		return (c_pid);
	else if (c_pid == 0)
		lunch(man);
	return (c_pid);
}

void	kill_zombie(t_philo *philo, int last)
{
	int i;

	i = 0;
	while (i < last)
	{
		kill(philo->pids[i], SIGKILL);
		++i;
	}
}

t_result	err_philo_take_seat(t_philo *philo, int last)
{
	printf("errr philo take seat\n");
	kill_zombie(philo, last);
	close_philo_sem(philo);
	// sem_close(philo->fork);
	free_set((void **)philo->men, NULL);
	ft_err(ERRFORK);
	return (FAILURE);
}

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


t_result	philo_lunch(t_philo *philo)
{
	int	i;

	i = -1;
	// 哲学者が一人の時
	printf("create philo\n");
	while (++i < philo->num_philo_and_fork)
	{
		philo->pids[i] = philo_take_seat(&philo->men[i]);
		if (philo->pids[i] == -1)
			return(err_philo_take_seat(philo, i));
	}
	if (philo->is_must_eat)
		philo->eat_count_pid = create_eat_count_watcher(philo);
	wait_die(philo);
	close_philo_sem(philo);
	return (SUCCESS);
}
