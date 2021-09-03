/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:56:48 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/03 23:36:15 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*monitor(void *v)
{
	t_trunk *trunk;

	trunk = (t_trunk *)v;
	pthread_mutex_lock(&g_print);
	printf("monitor is now\n");
	pthread_mutex_unlock(&g_print);
	return (NULL);
}
