/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_and_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:26:25 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/25 23:42:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result init_share(void)
{
	if (pthread_mutex_init(&g_print, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&g_dead, NULL) != 0)
	{
		pthread_mutex_destroy(&g_print);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_result	init_philo(t_trunk *trunk, int num_philos, t_config config)
{
	int		i;
	long	start;

	trunk->philo = (t_philo *)malloc(sizeof(t_philo) * num_philos);
	if (!trunk->philo)
		return (FAILURE);
	i = 0;
	start = what_time();
	while (i < num_philos)
	{
		trunk->philo[i].id = i + 1;
		trunk->philo[i].eat_start = start;
		trunk->philo[i].eat_count = 0;
		trunk->philo[i].config = config;
		trunk->philo[i].left = NULL;
		trunk->philo[i].right = NULL;
		i++;
	}
	return (SUCCESS);
}

t_result	init_fork(t_trunk *trunk, int num_forks)
{
	int i;
	t_fork *tmp_fork;

	trunk->fork = (t_fork *)malloc(sizeof(t_fork) * num_forks);
	if (!trunk->fork)
		return (FAILURE);
	i = 0;
	tmp_fork = &(trunk->fork[i]);
	while (i < num_forks)
	{
		if (pthread_mutex_init(&(tmp_fork->mutex_fork), NULL) != 0)
		{
			//エラー処理 free (trunk->philo, trunk->fork)
			return (FAILURE);
		}
		tmp_fork = &(trunk->fork[++i]);
	}
	return (SUCCESS);
}

void link_to_fork(t_trunk *trunk, int num_philo, t_fork *fork)
{
	int i;
	t_philo *tmp_philo;

	i = 0;
	tmp_philo = &(trunk->philo[i]);
	while (i < num_philo)
	{
		if (i == 0)
			tmp_philo->left = &fork[num_philo - 1];
		else
			tmp_philo->left = &fork[i - 1];
		tmp_philo->right = &fork[i];
		tmp_philo = &(trunk->philo[++i]);
	}
}

t_result	init_philo_and_fork(t_trunk *trunk, t_config config)
{
	int num_philo_and_fork;

	// thread を作る
	num_philo_and_fork = trunk->config.num_philo_and_fork;
	if (init_share() == FAILURE)
		return (FAILURE);
	if (init_philo(trunk, num_philo_and_fork, config) == FAILURE)
		return (FAILURE);
	if (init_fork(trunk, num_philo_and_fork) == FAILURE)
		return (FAILURE);
	link_to_fork(trunk, num_philo_and_fork, trunk->fork);
	// printf("philo[num]\t| eat_count | left | right\n");
	// for (int i = 0; i < num_philo_and_fork; i++)
	// {
	// 	printf("philo[%d]\t|\t%d\t|\n", i + 1, trunk->philo[i].eat_count);
	// }
	return (SUCCESS);
}
