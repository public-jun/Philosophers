/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:54:33 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/27 18:03:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static t_result	set_philo_para(int *item, char *arg)
{
	int	*tmp;

	tmp = NULL;
	tmp = ft_atoi(arg);
	if (!tmp)
		return (FAILURE);
	*item = *tmp;
	free_set((void **)&tmp, NULL);
	return (SUCCESS);
}

t_result	init_args(int ac, char **av, t_philo *philo)
{
	if (ac != 5 && ac != 6)
		return (FAILURE);
	else if (ac == 6)
		philo->is_must_eat = true;
	if (set_philo_para(&philo->num_philo_and_fork, av[1])
		|| set_philo_para(&philo->time_to_die, av[2])
		|| set_philo_para(&philo->time_to_eat, av[3])
		|| set_philo_para(&philo->time_to_sleep, av[4]))
		return (FAILURE);
	if (philo->is_must_eat
		&& set_philo_para(&philo->num_of_times_each_philo_must_eat, av[5]))
		return (FAILURE);
	return (SUCCESS);
}
