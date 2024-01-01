/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:09:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/01 20:21:13 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int	main(int ac, char *av[])
{
	int		i;
	t_data	var;

	i = 0;
	var.a = (int **) malloc (sizeof(int *) * (ac - 1));
	var.b = (int *) malloc (sizeof(int) * (ac - 1));
	while (i < (ac - 1))
	{
		var.(*a) = (int *) malloc (sizeof(int) * 2);
		var.(*b) = (int *) malloc (sizeof(int) * 2);
	}
	var.hm_a = (int *) malloc (sizeof(int) * (ac - 1));
	var.hm_b = (int *) malloc (sizeof(int) * (ac - 1));
	var.golden_hm = (int *) malloc (sizeof(int) * (ac - 1));
	while (i < (ac - 1))
	{
		var.a[i][0] = ft_atoi(av[i + 1]);
		var.a[i][1] = i;
		var.hm_a[i] = 1;
		var.hm_b[i] = 0;
		i++;
	}
	merge(var.stack_size, &var);
}
