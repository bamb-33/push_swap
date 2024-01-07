/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:09:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/07 19:57:56 by naadou           ###   ########.fr       */
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

t_data	init(int ac, char **av)
{
	int		i;
	t_data	var;

	i = 0;
	//malloc protection
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

char	**ft_get_integers(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**integers;

	i = 1;
	tmp = NULL;
	str = NULL;
	while (i < ac)
	{
		if (str)
			free(str);
		if (av[i][0] == 0)
			error_exit();
		str = ft_strjoin(tmp, av[i], ' ');
		if (!str)
			exit(0);//not sure if this is the right way to do it
		if (tmp)
			free(tmp);
		tmp = ft_strdup(str);
		i++;
	}
	integers = ft_split(str, ' ');
	free_strings(str, tmp);
	return (integers);
}

int	main(int ac, char *av[])
{
	char	**integers;
	t_data	var;

	if (ac == 1)
		return (0);
	integers = ft_get_integers(ac, av);
	var = init(str_len(integers), integers);
	print_stack(var);
	rrb(var.b, &var, 1);
	print_stack(var);
	exit(0);
	if (error(var, integers) == 0)
		error_exit();
	if (stack_len(var.hm_a) <= 3)
		sort(&var);
	else
	{
		pb(var.a, var.b, var.stack_size, &var);
		pb(var.a, var.b, var.stack_size, &var);
		algorithme(&var);
	}
	free_t_data(var);
	// system("leaks push_swap");
	return (0);
}
