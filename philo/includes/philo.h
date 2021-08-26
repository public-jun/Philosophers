/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:49:03 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/26 18:46:49 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*
** memset
*/
#include <string.h>

/*
** printf
*/
# include <stdio.h>

/*
** malloc free
*/
# include <stdlib.h>

/*
** write usleep
*/
# include <unistd.h>

/*
** gettimeofday
*/
# include <sys/time.h>

/*
** pthread_*
*/
# include <pthread.h>

# include <struct.h>

/*
** parse.c
*/
int	parser(int ac, char **av, t_info *info);

#endif
