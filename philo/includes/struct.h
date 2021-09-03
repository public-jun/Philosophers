/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:30:01 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/03 12:04:36 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct s_config
{
	int		num_philo_and_fork;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_must_eat;
	bool	flag_must_eat;
} t_config;

typedef struct s_share
{
	bool			is_stop;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_stop;
} t_share;

typedef struct s_fork
{
	bool			is_use;
	pthread_mutex_t	mutex_fork;
} t_fork;

typedef struct s_philo
{
	int				own_num;
	struct timeval	eat_start;
	int				eat_count;
	t_fork			*left;
	t_fork			*right;
	pthread_t		thread;
	pthread_t		death_monitor;
} t_philo;

typedef struct s_trunk
{
	t_config	config;
	t_share		share;
	t_fork		*fork;
	t_philo		*philo;
} t_trunk;

#endif
