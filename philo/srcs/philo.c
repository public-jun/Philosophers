/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:59:19 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/07 12:49:29 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//出力してみる
void	*philosopher(void *v)
{
	t_philo *philo;

	philo = (t_philo *)v;
	pthread_mutex_lock(&g_print);
	printf("id = %d\n", philo->id);
	printf("num %d\n", philo->config.num_philo_and_fork);
	printf("die %d\n", philo->config.time_to_die);
	printf("eat %d\n", philo->config.time_to_eat);
	printf("sleep %d\n", philo->config.time_to_sleep);
	pthread_mutex_unlock(&g_print);
	return (NULL);
}
