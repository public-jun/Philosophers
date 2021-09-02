/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:48:35 by jnakahod          #+#    #+#             */
/*   Updated: 2021/09/02 21:26:29 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int ac, char **av)
{
	t_config	config;
	t_trunk		trunk;

	if (parser(ac, av, &config) != 0)
		return (print_err_message("Invalid argment\n"));
	trunk.config = config;
	// thread and mutex を作成
	if (init_thread_and_mutex(&trunk) != 0)
		return (print_err_message("error init\n"));
	printf("done\n");
	return (0);
}
