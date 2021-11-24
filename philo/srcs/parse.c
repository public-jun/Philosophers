/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:02:37 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/27 14:32:33by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <define.h>

t_result set_philo_data(int *item, char *src)
{
	int *tmp;

	tmp = ft_atoi_ex(src);
	if (!tmp)
		return (FAILURE);
	*item = *tmp;
	free_set((void **)&tmp, NULL);
	return (SUCCESS);
}

bool is_in_range(int value, int min, int max)
{
	if (value < min || max < value)
		return (false);
	return (true);
}

int check_valid_philo_value(t_config *config)
{
	if (is_in_range(config->num_philo_and_fork, PHILOMIN, PHILOMAX) == false)
		return (-1);
	if ((is_in_range(config->time_to_die, MSECMIN, MSECMAX) == false) || (is_in_range(config->time_to_eat, MSECMIN, MSECMAX) == false) || (is_in_range(config->time_to_sleep, MSECMIN, MSECMAX) == false))
		return (-1);
	if ((config->flag_must_eat == true) && (is_in_range(config->num_times_must_eat,
														MUSTEATMIN, MUSTEATMAX) == false))
		return (-1);
	return (0);
}

t_result	parser(int ac, char **av, t_config *config)
{
	config->flag_must_eat = false;
	if (ac < 5 || 6 < ac)
		return (FAILURE);
	else if (ac == 6)
		config->flag_must_eat = true;
	if (!set_philo_data(&(config->num_philo_and_fork), av[1]))
		return (FAILURE);
	if (!set_philo_data(&(config->time_to_die), av[2]))
		return (FAILURE);
	if (!set_philo_data(&(config->time_to_eat), av[3]))
		return (FAILURE);
	if (!set_philo_data(&(config->time_to_sleep), av[4]))
		return (FAILURE);
	if (config->flag_must_eat == true && !set_philo_data(&(config->num_times_must_eat), av[5]))
		return (FAILURE);
	if (!check_valid_philo_value(config))
		return (FAILURE);
	return (SUCCESS);
}
