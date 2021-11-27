/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:56:41 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 23:08:39 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_err(t_philo *philo, const char *msg)
{
	printf("%s\n", msg);
	if (philo)
	{
		free_all(philo);
	}
	return (1);
}
