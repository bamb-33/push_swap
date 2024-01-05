/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:34:49 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 21:09:45 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "get-next-line/get_next_line.h"

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
	char	**instructions;

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
	instructions = ft_split(get_next_line(0), '\n');
	i = 0;
	while (instructions[i])
	{
		ft_call(instructions[i], &var);
		i++;
	}
	if (is_sorted(&var) == 0)
		write(2, "KO\n", 3);
	else
		write(2, "KO\n", 3);
}
