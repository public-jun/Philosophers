/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:54:33 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 17:11:25 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_result	init_args(int ac, char **av, t_philo *philo)
{
	if (ac != 5 && ac != 6)
		return (FAILURE);
	(void)av;
	(void)philo;
	return (SUCCESS);
}
