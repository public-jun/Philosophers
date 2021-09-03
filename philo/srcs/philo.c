/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:59:19 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/03 23:36:37 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//出力してみる
void	*philosopher(void *v)
{
	t_trunk *trunk;

	trunk = (t_trunk *)v;
	pthread_mutex_lock(&g_print);
	printf("philo is now\n");
	pthread_mutex_unlock(&g_print);
	return (NULL);
}
