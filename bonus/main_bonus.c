/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:34:49 by naadou            #+#    #+#             */
/*   Updated: 2024/01/19 14:09:15 by naadou           ###   ########.fr       */
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
		free_previous(var, 1);
	while (i < ac)
	{
		var->a[i] = (int *) malloc (sizeof(int) * 3);
		if (!var->a[i])
			free_previous(var, 2);
		var->b[i] = (int *) malloc (sizeof(int) * 3);
		if (!var->b[i])
			free_previous(var, 3);
		i++;
	}
	var->hm_a = (int *) malloc (sizeof(int) * ac);
	if (!var->hm_a)
		free_previous(var, 4);
	var->hm_b = (int *) malloc (sizeof(int) * ac);
	if (!var->hm_b)
		free_previous(var, 5);
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
		var.a[ac - 1][0] = ft_atoi(av[i]);
		var.hm_a[i] = 1;
		var.hm_b[i] = 0;
		ac--;
		i++;
	}
	return (var);
}

void	empty_string_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return ;
		i++;
	}
	write(2, "Error\n", 6);
	exit(1);
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
		str = ft_strjoin(tmp, av[i], ' ');
		if (tmp)
			free(tmp);
		if (!str)
			exit(1);
		empty_string_check(av[i]);
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
	if (!integers)
		exit(1);
	var = init(str_len(integers), integers);
	if (error(var, integers) == 0)
		error_exit(&var, integers);
	free_integers(integers, var.stack_size);
	read_instructions(&var);
	if (is_sorted(&var) == 0)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
	free_t_data(&var);
	return (0);
}
