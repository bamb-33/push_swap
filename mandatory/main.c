/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:09:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/08 18:24:16 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	allocation(t_data *var, int ac)
{
	int		i;

	i = 0;
	var->a = (int **) malloc (sizeof(int *) * ac);
	if (!var->a)
		exit(1);
	var->b = (int **) malloc (sizeof(int *) * ac);
	if (!var->b)
		free_previous(*var, 1);
	while (i < ac)
	{
		var->a[i] = (int *) malloc (sizeof(int) * 3);
		if (!var->a[i])
			free_previous(*var, 2);
		var->b[i] = (int *) malloc (sizeof(int) * 3);
		if (!var->b[i])
			free_previous(*var, 3);
		i++;
	}
	var->hm_a = (int *) malloc (sizeof(int) * ac);
	if (!var->hm_a)
		free_previous(*var, 4);
	var->hm_b = (int *) malloc (sizeof(int) * ac);
	if (!var->hm_b)
		free_previous(*var, 5);
}

t_data	init(int ac, char **av)
{
	int		i;
	t_data	var;

	allocation(&var, ac);
	var.stack_size = ac;
	i = 0;
	while (ac > 0)
	{
		var.a[ac - 1][0] = atoi_extra(av[i]);
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
			exit(1);
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
	return (0);
}
