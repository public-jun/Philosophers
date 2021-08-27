/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:14:29 by jnakahod          #+#    #+#             */
/*   Updated: 2021/08/27 13:55:09 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_int_overflow(int sign, const char *str)
{
	int	digit;

	digit =  0;
	while (ft_isdigit(str[digit]))
		digit++;
	if (digit > 10)
		return (-1);
	if ((sign == 1 && ft_strncmp(str, "2147483647", 19) > 0) && digit == 10)
		return (-1);
	if ((sign == -1 && ft_strncmp(str, "2147483648", 19) > 0) && digit == 10)
		return (-1);
	return (0);
}

static int	*make_int_value_in_heap(const char *str, int i, int sign)
{
	int	number;
	int	*res;

	number = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			number = number * 10;
			number += str[i] - '0';
			i++;
		}
		else
			return (NULL);
	}
	res = (int *)malloc(sizeof(int) * 1);
	if (!res)
		return (NULL);
	*res = number * sign;
	return (res);
}

int	*ft_atoi_ex(const char *str)
{
	int	*res;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (check_int_overflow(sign, str + i) != 0)
		return (NULL);
	if (!str[i])
		return (NULL);
	res = make_int_value_in_heap(str, i, sign);
	return (res);
}
