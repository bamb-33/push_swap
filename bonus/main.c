/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:34:49 by naadou            #+#    #+#             */
/*   Updated: 2024/01/08 14:06:40 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	allocation(t_data *var, int ac)
{
	int		i;

	i = 0;
	var->a = (int **) malloc (sizeof(int *) * ac);
	if (!var->a)
		free_two_d_int(var->a);
	var->b = (int **) malloc (sizeof(int *) * ac);
	if (!var->b)
		free_two_d_int(var->b);
	while (i < ac)
	{
		var->a[i] = (int *) malloc (sizeof(int) * 3);
		if (!var->a[i])
			free_int(var->a[i]);
		var->b[i] = (int *) malloc (sizeof(int) * 3);
		if (!var->b[i])
			free_int(var->b[i]);
		i++;
	}
	var->hm_a = (int *) malloc (sizeof(int) * ac);
	if (!var->hm_a)
		free_int(var->hm_a);
	var->hm_b = (int *) malloc (sizeof(int) * ac);
	if (!var->hm_b)
		free_int(var->hm_b);
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
	char	*instructions;

	if (ac == 1)
		return (0);
	integers = ft_get_integers(ac, av);
	var = init(str_len(integers), integers);
	if (error(var, integers) == 0)
		error_exit();
	instructions = get_next_line(0);
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
