/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:56:48 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/07 22:35:00 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*monitor(void *v)
{
	t_philo *philo;

	philo = (t_philo *)v;
	// pthread_mutex_lock(&g_print);
	// printf("monitor is now\n");
	// pthread_mutex_unlock(&g_print);
	return (NULL);
}
