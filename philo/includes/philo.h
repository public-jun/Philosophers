/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:49:03 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/03 20:48:24 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

/*
** memset
*/
#include <string.h>

/*
** printf
*/
#include <stdio.h>

/*
** malloc free
*/
#include <stdlib.h>

/*
** write usleep
*/
#include <unistd.h>

/*
** gettimeofday
*/
#include <sys/time.h>

/*
** pthread_*
*/
#include <pthread.h>

#include <struct.h>
#include <stdbool.h>


/*
** end.c
*/
void	end_process(t_trunk *trunk);

/*
** ft_atoi.c
*/
int *ft_atoi_ex(const char *str);

/*
** init_thread_and_mutex
*/
int	init_philo_and_fork(t_trunk *trunk);

/*
** monitor.c
*/
void	*monitor(void *v);


/*
** parse.c
*/
int parser(int ac, char **av, t_config *config);

/*
** philo.c
*/
void	*philosopher(void *v);

/*
** utils.c
*/
size_t ft_strlen(const char *src);
int ft_isdigit(int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void free_set(void **dst, void *src);

/*
** start.c
*/
int	thread_process(t_trunk *trunk, int num_philo);

/*
** print_err.c
*/
int	print_err_message(char *mess);

#endif
