/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/01 21:58:21 by jnakahod         ###   ########.fr       */
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

	// philo status
	int				id;
	sem_t			*fork;
	sem_t			*taking;
	int				eat_count;
	long long		time_to_start_eat;
	sem_t			*died;
	// sem_t			*eat;
}	t_man;

typedef struct s_philo
{
	int				num_philo_and_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	bool			is_must_eat;

	// pthread_mutex_t	eat;
	int				least_philo_ate_count;
	t_man			*men;
	pid_t			pids[PIDMAX];
	sem_t			*fork; // == num philo
	// sem_t			*died; // == 1
	// sem_t			*eat;
	// bool			is_alive;
}	t_philo;

t_result	init_args(int ac, char **av, t_philo *philo);

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
// int			ft_err_and_free(t_philo *philo, const char *msg);

/*
** philo_init_eat.c
*/
t_result	philo_init_eat(t_philo *philo);

/*
** philo_init_man.c
*/
t_result	philo_init_man(t_philo *philo);

/*
** philo_init_sem.c
*/
t_result	philo_init_sem(t_philo *philo);

/*
** philo_lunch.c
*/
t_result	philo_lunch(t_philo *philo);

/*
** philo_utils.c
*/
void		philo_print_status(t_man *man, const char *msg);
void		only_one_philo(t_man *man);
void		philo_wait(t_man *man, long long standard, int wait_time);
void		philo_die(t_man *man);

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

#endif
