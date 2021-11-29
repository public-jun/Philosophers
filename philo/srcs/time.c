/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:08:12 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/29 12:01:56 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	what_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// int	waiting_time(long long standard, int work)
// {
// 	if (what_time() - standard >= work)
// 		return (1);
// 	return (0);
// }

bool is_die(t_man *man, long long now)
{
	if (now - man->time_to_start_eat >= man->time_to_die)
	{
		philo_die(man);
		return (true);
	}
	return (false);
}

int	waiting_time(t_man *man, long long standard, int work)
{
	long long now;

	now = what_time();
	if (is_die(man, now))
		return (1);
	if (now - standard >= work)
		return (1);
	return (0);
}
