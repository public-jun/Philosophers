/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/29 16:00:23 by jnakahod         ###   ########.fr       */
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

typedef enum e_result
{
	SUCCESS,
	FAILURE
}	t_result;

typedef struct s_man
{
	// Args info PART
	int				num_philo_and_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	bool			is_must_eat;

	// each Man status
	int				id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				eat_count;
	long long		time_to_start_eat;
	pthread_t		thread;

	// Share para PART
	pthread_mutex_t	*died;
	bool			*is_alive;
	// philo must eat PART
	pthread_mutex_t	*eat;
	int				*least_philo_ate_count;
}	t_man;

typedef struct s_philo
{
	// Args info PART
	int				num_philo_and_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	bool			is_must_eat;

	// philo must eat PART
	pthread_mutex_t	eat;
	int				least_philo_ate_count;

	// Shared para PART
	t_man			*men;
	pthread_mutex_t	*fork;
	pthread_mutex_t	died;
	bool			is_alive;
}	t_philo;

t_result	init_args(int ac, char **av, t_philo *philo);

/*
** free_all.c
*/
void		destroy_philo(t_philo *philo);
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
** philo_init_fork.c
*/
t_result	err_philo_init_fork(t_philo *philo, int last_index, char *msg);
t_result	philo_init_fork(t_philo *philo);

/*
** utils.c
*/
void		philo_die(t_man *man);
void		philo_lunch(t_philo *philo);

/*
** time.c
*/
long long	what_time(void);
int			waiting_time(t_man *man, long long standard, int work);

/*
** utils.c
*/
size_t		ft_strlen(const char *src);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_set(void **dst, void *src);

#endif
