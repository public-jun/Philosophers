/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:54:33 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/02 19:58:11 by jnakahod         ###   ########.fr       */
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

static bool	is_in_range(int value, int min, int max)
{
	if (min <= value && value <= max)
		return (true);
	else
		return (false);
}

static t_result	check_valid_philo_para(t_philo *philo)
{
	if (!is_in_range(philo->num_philo_and_fork, PHILOMIN, PHILOMAX)
		|| !is_in_range(philo->time_to_die, MSECMIN, MSECMAX)
		|| !is_in_range(philo->time_to_eat, MSECMIN, MSECMAX)
		|| !is_in_range(philo->time_to_sleep, MSECMIN, MSECMAX))
		return (FAILURE);
	if (philo->is_must_eat
		&& !is_in_range(philo->num_of_times_each_philo_must_eat,
			MUSTEATMIN, MUSTEATMAX))
		return (FAILURE);
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
	if (check_valid_philo_para(philo))
		return (FAILURE);
	return (SUCCESS);
}
