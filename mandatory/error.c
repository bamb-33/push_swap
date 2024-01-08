/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:48:46 by naadou            #+#    #+#             */
/*   Updated: 2024/01/08 18:40:45 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long long int	atoi_extra(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	check_duplicates(int i, t_data var)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (var.a[j][0] == var.a[i][0])
			return (0);
		j++;
	}
	return (1);
}

int	check_if_integer(t_data var, char **ns)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (i < var.stack_size)
	{
		sign = 0;
		j = 0;
		while (ns[i][j])
		{
			if (ns[i][j] == 45 || ns[i][j] == 43)
				sign++;
			else if (ns[i][j] < 48 || ns[i][j] > 57)
				return (0);
			if (sign > 1)
				return (0);
			j++;
		}
		i++;
	}
	if (sign == j)
		return (0);
	return (1);
}

int	error(t_data var, char **ns)
{
	int	i;

	i = 0;
	if (check_if_integer(var, ns) == 0)
		return (0);
	while (i < var.stack_size)
	{
		if (atoi_extra(ns[i]) > 2147483647 || atoi_extra(ns[i]) < -2147483648)
			return (0);
		if (check_duplicates(i, var) == 0)
			return (0);
		i++;
	}
	return (1);
}
