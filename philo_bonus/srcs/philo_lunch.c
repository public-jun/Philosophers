/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/01 21:59:59 by jnakahod         ###   ########.fr       */
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
	// ++man->eat_count;
	// if (man->eat_count == man->num_of_times_each_philo_must_eat)
	// {
	// 	pthread_mutex_lock(man->eat);
	// 	++*man->least_philo_ate_count;
	// 	if (*man->least_philo_ate_count == man->num_philo_and_fork)
	// 	{
	// 		pthread_mutex_lock(man->died);
	// 		*man->is_alive = false;
	// 		pthread_mutex_unlock(man->died);
	// 	}
	// 	pthread_mutex_unlock(man->eat);
	// }
	sem_post(man->fork);
	sem_post(man->fork);
}

// void	philo_sleep(t_man *man)
// {
// 	long long	time_to_start_sleep;

// 	pthread_mutex_lock(man->died);
// 	time_to_start_sleep = what_time();
// 	if (*man->is_alive)
// 		printf("%lld %d %s\n", time_to_start_sleep, man->id, SLEEP);
// 	pthread_mutex_unlock(man->died);
// 	philo_wait(man, time_to_start_sleep, man->time_to_sleep);
// }

void	*lunch(void *p)
{
	t_man	*man;

	man = p;
	man->time_to_start_eat = what_time();
	while (true)
	{
		philo_take_fork(man);
		philo_eat_spaghetti(man);
		// philo_sleep(man);
		// philo_print_status(man, THINK);
	}
	exit(0);
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
	kill_zombie(philo, last);
	sem_close(philo->fork);
	free_set((void **)philo->men, NULL);
	ft_err(ERRFORK);
	return (FAILURE);
}

void	wait_die(t_philo *philo)
{
	pid_t	die_pid;
	int		status;
	int		i;

	i = -1;
	die_pid = waitpid(-1, &status, 0);
	// dieで誰かが死んだ場合
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		while (++i < philo->num_philo_and_fork)
		{
			if (die_pid != philo->pids[i])
				kill(philo->pids[i], SIGKILL);
		}
	}
}


t_result	philo_lunch(t_philo *philo)
{
	int	i;

	i = -1;
	// 哲学者が一人の時
	while (++i < philo->num_philo_and_fork)
	{
		philo->pids[i] = philo_take_seat(&philo->men[i]);
		if (philo->pids[i] == -1)
			return(err_philo_take_seat(philo, i));
	}
	// least must eat count watcher
	// wait die
	wait_die(philo);
	sem_close(philo->fork);
	return (SUCCESS);
}
