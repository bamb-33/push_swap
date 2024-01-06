/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:09:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/06 10:06:00 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void print_stack(t_data var)
{
	for (int i = var.stack_size - 1; i >= 0; i--)
	{
		printf("%d|  %d || %d|  %d\n", var.a[i][0], var.hm_a[i], var.b[i][0], var.hm_b[i]);
	}
	printf("---------------\n\n");
	// printf("pb\n");
    // printf("pb\n");
    // printf("sa\n");
    // printf("ra\n");
    // printf("rra\n");
    // printf("pa\n");
    // printf("rra\n");
    // printf("pa\n");
    // printf("rra\n");
}

t_data	init(int ac, char **av)
{
	int		i;
	t_data	var;

	i = 0;
	var.a = (int **) malloc (sizeof(int *) * ac);
	var.b = (int **) malloc (sizeof(int *) * ac);
	var.stack_size = ac;
	while (i < ac)
	{
		var.a[i] = (int *) malloc (sizeof(int) * 3);
		var.b[i] = (int *) malloc (sizeof(int) * 3);
		i++;
	}
	var.hm_a = (int *) malloc (sizeof(int) * ac);
	var.hm_b = (int *) malloc (sizeof(int) * ac);
	i = 0;
	while (ac > 0)
	{
		var.a[ac - 1][0] = ft_atoi(av[i]);
		var.hm_a[i] = 1;
		var.hm_b[i] = 0;
		ac--;
		i++;
	}
	return (var);
}

int	main(int ac, char *av[])
{
	int		i;
	char	*str;
	char	**integers;
	t_data	var;

	i = 1;
	str = 0;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		if (av[i][0] == 0)
			error_exit();
		str = ft_strjoin(str, av[i], ' ');
		i++;
	}
	integers = ft_split(str, ' ');
	var = init(str_len(integers), integers);
	if (error(var, integers) == 0)
		error_exit();
	if (stack_len(var.hm_a) <= 3)
		issorted(&var);
	else
	{
		pb(var.a, var.b, var.stack_size, &var);
		pb(var.a, var.b, var.stack_size, &var);
		algorithme(&var);
	}
	// print_stack(var);
	free_t_data(var);
	// system("leaks push_swap");
	return (0);
}
