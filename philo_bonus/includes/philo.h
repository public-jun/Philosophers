/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 20:12:51 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <define.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef enum e_result
{
	SUCCESS,
	FAILURE
}	t_result;

typedef struct s_man
{
	int				num_philo_and_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	bool			is_must_eat;
	int				id;
	int				eat_count;
	long long		time_to_start_eat;
	sem_t			*fork;
	sem_t			*taking;
	sem_t			*died;
	sem_t			*eat;
}	t_man;

typedef struct s_philo
{
	int				num_philo_and_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	bool			is_must_eat;
	t_man			*men;
	pid_t			pids[PIDMAX];
	pid_t			eat_count_pid;
	sem_t			*fork;
	sem_t			*died;
	sem_t			*eat;
}	t_philo;

/*
** free_all.c
*/
int			free_all(t_philo *philo);

/*
** ft_atoi.c
*/
int			*ft_atoi(const char *str);

/*
** ft_err.c
*/
t_result	ft_err(const char *msg);

/*
** init_args.c
*/
t_result	init_args(int ac, char **av, t_philo *philo);

/*
** lunch.c
*/
void		*lunch(void *p);
void		lunch_alone(t_man *man);

/*
** philo_init_man.c
*/
t_result	philo_init_man(t_philo *philo);

/*
** philo_init_sem.c
*/
void		close_philo_sem(t_philo *philo);
t_result	philo_init_sem(t_philo *philo);

/*
** philo_utils.c
*/
void		kill_all_philo(t_philo *philo, pid_t except);
void		philo_print_status(t_man *man, const char *msg);
void		only_one_philo(t_man *man);
void		philo_wait(t_man *man, long long standard, int wait_time);

/*
** take_seat.c
*/
t_result	philo_lunch(t_philo *philo);

/*
** time.c
*/
long long	what_time(void);
int			waiting(t_man *man, long long standard, int work);
bool		is_die(t_man *man, long long now);

/*
** utils.c
*/
size_t		ft_strlen(const char *src);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_set(void **dst, void *src);

/*
** watcher.c
*/
void		count_philo_must_ate_monitor(t_philo *philo);
t_result	create_eat_count_watcher(t_philo *philo);
void		wait_die(t_philo *philo);

#endif
