/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:30:01 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/10 21:59:09 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

extern bool				g_is_dead;
extern pthread_mutex_t	g_print;
extern pthread_mutex_t	g_dead;

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

#endif
