/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:48:46 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 17:58:17 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// long long int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	sign;
// 	long long int	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = (result * 10) + (str[i] - 48);
// 		i++;
// 	}
// 	return (result * sign);
// }

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

int	error(t_data var, char **av)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (i < var.stack_size)
	{
		sign = 0;
		j = 0;
		while (av[i][j])
		{
			if (sign > 1)
				return (0);
			if (av[i][j] == 45 || av[i][j] == 43)
				sign++;
			else if (av[i][j] < 48 || av[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < var.stack_size)
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (0);
		if (check_duplicates(i, var) == 0)
			return (0);
		i++;
	}
	return (1);
}
