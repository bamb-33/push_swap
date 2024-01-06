/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:34:49 by naadou            #+#    #+#             */
/*   Updated: 2024/01/06 20:44:21 by naadou           ###   ########.fr       */
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
}

t_data	init_bonus(int ac, char **av)
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
	char	*instructions;

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
	var = init_bonus(str_len(integers), integers);
	if (error(var, integers) == 0)
		error_exit();
	instructions = get_next_line(0);
	printf("%zu\n", ft_strlen(instructions));
	for(int i = 0; instructions[i]; i++)
		printf("%d\n", instructions[i]);
	while (instructions)
	{
		ft_call(instructions, &var);
		instructions = get_next_line(0);
	}
	if (is_sorted(&var) == 0)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
	exit(0);
}
