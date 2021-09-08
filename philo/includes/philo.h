/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:49:03 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/08 23:21:32 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** memset
*/
# include <string.h>

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
# include <stdbool.h>

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
int			parser(int ac, char **av, t_config *config);

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
