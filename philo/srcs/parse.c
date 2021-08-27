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

int	set_philo_data(int	*item, char *src)
{
	int *tmp;

	tmp = ft_atoi_ex(src);
	if (!tmp)
		return (-1);
	*item = *tmp;
	free_set((void **)&tmp, NULL);
	return (0);
}

bool	is_in_range(int value, int min, int max)
{
	if (value < min || max < value)
		return (false);
	return (true);
}

int	check_valid_philo_value(t_info *info)
{
	if (is_in_range(info->num_philo_and_fork, PHILOMIN, PHILOMAX) == false)
		return (-1);
	if ((is_in_range(info->time_to_die, MSECMIN, MSECMAX) == false) || (is_in_range(info->time_to_eat, MSECMIN, MSECMAX) == false) || (is_in_range(info->time_to_sleep, MSECMIN, MSECMAX) == false))
		return (-1);
	if ((info->flag_must_eat == true) && (is_in_range(info->num_times_must_eat, MUSTEATMIN, MUSTEATMAX) == false))
		return (-1);
	return (0);
}

int	parser(int ac, char **av, t_info *info)
{
	info->flag_must_eat = false;
	if (ac < 5 || 6 < ac)
		return (-1);
	else if (ac == 6)
		info->flag_must_eat = true;
	if (set_philo_data(&(info->num_philo_and_fork), av[1]) == -1)
		return (-1);
	if (set_philo_data(&(info->time_to_die), av[2]) == -1)
		return (-1);
	if (set_philo_data(&(info->time_to_eat), av[3]) == -1)
		return (-1);
	if (set_philo_data(&(info->time_to_sleep), av[4]) == -1)
		return (-1);
	if (info->flag_must_eat == true && set_philo_data(&(info->num_times_must_eat), av[5]) == -1)
		return (-1);
	if (check_valid_philo_value(info) == -1)
		return (-1);
	printf("num_philo_and_fork = %d\n", info->num_philo_and_fork);
	printf("time_to_die = %d\n", info->time_to_die);
	printf("time_to_eat = %d\n", info->time_to_eat);
	printf("time_to_sleep = %d\n", info->time_to_sleep);
	// printf("num_philo_and_fork = %d\n", info->num_philo_and_fork);
	return (0);
}
