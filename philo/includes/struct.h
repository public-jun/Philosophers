/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:30:01 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/26 18:51:47 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_info {
	int num_philo_and_fork;
	int time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int num_times_must_eat;
} t_info;

#endif
