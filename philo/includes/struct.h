/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:30:01 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/27 23:24:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct s_config
{
	int num_philo_and_fork;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_times_must_eat;
	bool flag_must_eat;
} t_config;

#endif
