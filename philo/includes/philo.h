/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 17:10:24 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <define.h>

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>


typedef enum e_result
{
	SUCCESS,
	FAILURE
}	t_result;

typedef struct s_philo
{
	int	num_philo_and_fork;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int num_of_times_each_philo_must_eat;
}	t_philo;

int	ft_err(const char *msg);
t_result	init_args(int ac, char **av, t_philo *philo);

#endif
