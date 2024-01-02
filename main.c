/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:09:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/02 19:28:13 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void print_stack(t_data var)
{
	// for (int i = var.stack_size - 1; i >= 0; i--)
	// {
	// 	printf("%d|  %d/%d || %d|  %d/%d\n", var.a[i][0], var.a[i][1], var.hm_a[i], var.b[i][0], var.b[i][1], var.hm_b[i]);
	// }
	// printf("---------------\n\n");
	// printf("pb\n");
    // printf("ra\n");
    // printf("rrb\n");
    // printf("pa\n");
    // printf("ra\n");
    // printf("pb\n");
    // printf("ra\n");
    // printf("ra\n");
    // printf("rrb\n");
    // printf("pa\n");
    // printf("ra\n");
	// write(1, "sa\n", 3);
	write(1, "pb\n", 3);
    write(1, "ra\n", 3);
    write(1, "rrb\n", 4);
    write(1, "pa\n", 3);
    write(1, "ra\n", 3);
    write(1, "pb\n", 3);
    write(1, "ra\n", 3);
    write(1, "ra\n", 3);
    write(1, "rrb\n", 4);
    write(1, "pa\n", 3);
    write(1, "ra\n", 3);
}

int	main(int ac, char *av[])
{
	int		i;
	t_data	var;

	i = 0;
	var.a = (int **) malloc (sizeof(int *) * (ac - 1));
	var.b = (int **) malloc (sizeof(int *) * (ac - 1));
	var.stack_size = ac - 1;
	while (i < (ac - 1))
	{
		var.a[i] = (int *) malloc (sizeof(int) * 2);
		var.b[i] = (int *) malloc (sizeof(int) * 2);
		i++;
	}
	var.hm_a = (int *) malloc (sizeof(int) * (ac - 1));
	var.hm_b = (int *) malloc (sizeof(int) * (ac - 1));
	i = 1;
	ac--;
	while (ac > 0)
	{
		var.a[ac - 1][0] = ft_atoi(av[i]);
		var.a[ac - 1][1] = i;
		var.hm_a[i - 1] = 1;
		var.hm_b[i - 1] = 0;
		ac--;
		i++;
	}
	// print_stack(var);
	// printf("--------\n");
	merge(var.stack_size, &var);
	// printf("--------\n\n");
	// print_stack(var);
	// print_stack(var);
}
