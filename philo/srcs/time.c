/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:08:12 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/07 22:54:03 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	what_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / 1000);
}

int	waiting_time(int standard, int work)
{
	struct timeval	now;
	int t;

	gettimeofday(&now, NULL);
	t = (now.tv_sec * 1000 + now.tv_usec / 1000) - standard;
	// printf("t = %d\n", t);
	// printf("work = %d\n", work);
	if (t >= work)
		return (1);
	return (0);
}
