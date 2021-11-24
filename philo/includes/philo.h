/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:49:03 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/24 18:52:19 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

extern bool				g_is_dead;
extern pthread_mutex_t	g_print;
extern pthread_mutex_t	g_dead;

typedef enum e_result
{
	SUCCESS,
	FAILURE
} t_result;

typedef struct s_config
{
	int		num_philo_and_fork;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_must_eat;
	bool	flag_must_eat;
}	t_config;

typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			eat_start;
	int				eat_count;
	t_config		config;
	t_fork			*left;
	t_fork			*right;
	pthread_t		thread;
	pthread_t		death_monitor;
}	t_philo;

typedef struct s_trunk
{
	t_config	config;
	t_fork		*fork;
	t_philo		*philo;
}	t_trunk;

/*
** eat.c
*/
int			eat(t_philo *philo);

/*
** end.c
*/
void		end_process(t_trunk *trunk);

/*
** ft_atoi.c
*/
int			*ft_atoi_ex(const char *str);

/*
** init_thread_and_mutex
*/
int			init_philo_and_fork(t_trunk *trunk, t_config config);

/*
** monitor.c
*/
void		*monitor(void *v);

/*
** parse.c
*/
t_result	parser(int ac, char **av, t_config *config);

/*
** philo.c
*/
void		*philosopher(void *v);

/*
** utils.c
*/
size_t		ft_strlen(const char *src);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_set(void **dst, void *src);

/*
** thread.c
*/
int			thread_process(t_trunk *trunk, int num_philo);

/*
** time.c
*/
long		what_time(void);
int			waiting_time(long standard, int work);

/*
** print_err.c
*/
int			print_err_message(char *mess);

/*
** sleep.c
*/
int			sleeping(t_philo *philo);

#endif
