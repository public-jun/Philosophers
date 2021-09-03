/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:48:35 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/03 23:45:53 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool			g_is_stop = false;
pthread_mutex_t	g_print;
pthread_mutex_t	g_stop;

int	main(int ac, char **av)
{
	t_config	config;
	t_trunk		trunk;

	if (parser(ac, av, &config) != 0)
		return (print_err_message("Invalid argment\n"));
	trunk.config = config;
	if (init_philo_and_fork(&trunk) != 0)
		return (print_err_message("error init\n"));
	if (thread_process(&trunk, config.num_philo_and_fork) != 0)
		return (print_err_message("error init\n"));
	printf("done\n");
	end_process(&trunk);
	return (0);
}
