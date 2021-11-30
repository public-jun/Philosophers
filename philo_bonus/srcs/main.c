/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:48:35 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/29 16:00:32 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	init_philo(t_philo *philo)
{
	philo->num_philo_and_fork = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->num_of_times_each_philo_must_eat = 0;
	philo->is_must_eat = false;
	philo->least_philo_ate_count = 0;
	philo->men = NULL;
	philo->fork = NULL;
	philo->is_alive = true;
}

int	main(int ac, char **av)
{
	t_philo	philo;

	init_philo(&philo);
	if (init_args(ac, av, &philo))
		return (ft_err(INVALIDARGS));
	if (philo_init_man(&philo))
		return (EXIT_FAILURE);
	if (philo_init_fork(&philo))
		return (EXIT_FAILURE);
	if (philo_init_eat(&philo))
		return (EXIT_FAILURE);
	philo_lunch(&philo);
	destroy_philo(&philo);
	free_all(&philo);
	return (0);
}
