/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:09:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/04 20:04:27 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	var.a = (int **) malloc (sizeof(int *) * (ac - 1));
	var.b = (int **) malloc (sizeof(int *) * (ac - 1));
	var.stack_size = ac - 1;
	while (i < (ac - 1))
	{
		var.a[i] = (int *) malloc (sizeof(int) * 3);
		var.b[i] = (int *) malloc (sizeof(int) * 3);
		i++;
	}
	var.hm_a = (int *) malloc (sizeof(int) * (ac - 1));
	var.hm_b = (int *) malloc (sizeof(int) * (ac - 1));
	i = 1;
	while (ac - 1 > 0)
	{
		var.a[ac - 2][0] = ft_atoi(av[i]);
		var.hm_a[i - 1] = 1;
		var.hm_b[i - 1] = 0;
		ac--;
		i++;
	}
	return (var);
}

void	issorted(t_data *x)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	if (i == stack_len(x->hm_b))
		b = stack_len(x->hm_b) - 1;
	while (i < stack_len(x->hm_b))
	{
		if (x->b[b][0] < x->b[i][0])
			b = i;
		i++;
	}
	b_sort(b, x);
	while (sort(x) == 0)
		sa(x->a, x);
}

int	main(int ac, char *av[])
{
	int		i;
	int		a;
	t_data	var;

	i = 0;
	var = init(ac, av);
	if (stack_len(var.hm_a) <= 3)
		issorted(&var);
	else
	{
		pb(var.a, var.b, var.stack_size, &var);
		pb(var.a, var.b, var.stack_size, &var);
		algo(&var);
		issorted(&var);
		small_stack(&var);
		while (i < stack_len(var.hm_a))
		{
			if (var.a[a][0] > var.a[i][0])
				a = i;
			i++;
		}
		a_sort(a, &var);
	}
	// print_stack(var);
	return (0);
}
