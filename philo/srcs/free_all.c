/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:03:51 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 23:31:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	free_all(t_philo *philo)
{
	free_set((void **)&philo->fork, NULL);
	free_set((void **)&philo->men, NULL);
	return(1);
}
