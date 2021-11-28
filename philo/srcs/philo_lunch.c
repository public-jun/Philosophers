/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:17:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/28 22:40:03 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_print_status(t_man *man, const char *msg)
{
	pthread_mutex_lock(man->died);
	if (!*man->is_fin)
		printf("%lld %d %s\n", what_time(), man->id, msg);
	pthread_mutex_unlock(man->died);
}

void	philo_take_fork(t_man *man)
{
	if (man->id % 2)
		pthread_mutex_lock(man->left);
	else
	{
		usleep(500);
		pthread_mutex_lock(man->right);
	}
	philo_print_status(man, TAKEFORK);
	if (man->id % 2)
	{
		usleep(500);
		pthread_mutex_lock(man->right);
	}
	else
		pthread_mutex_lock(man->left);
	philo_print_status(man, TAKEFORK);

	usleep(100000);
	pthread_mutex_unlock(man->left);
	pthread_mutex_unlock(man->right);
}
void *lunch(void *p)
{
	t_man *man;

	man = p;
	// printf("id: %d\n", man->id);
	// take fork
	philo_take_fork(man);
	philo_eat_spa(man);
	// eat
	// sleep
	// think
	return (NULL);
}

void	philo_lunch(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num_philo_and_fork)
	{
		pthread_create(&philo->men[i].thread, NULL, lunch, &philo->men[i]);
	}
	i = -1;
	while (++i < philo->num_philo_and_fork)
		pthread_join(philo->men[i].thread, NULL);
}
