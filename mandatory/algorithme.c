/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:55:00 by naadou            #+#    #+#             */
/*   Updated: 2024/01/19 13:18:18 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	**stack_clone(t_data *var, int **x, int len)
{
	int	i;
	int	**s;

	i = 0;
	s = (int **) malloc (sizeof(int *) * len);
	if (!s)
	{
		free_t_data(var);
		exit(1);
	}
	while (i < len)
	{
		s[i] = (int *) malloc (sizeof(int ) * 2);
		if (!s[i])
		{
			free_stack_clone(s, i);
			free_t_data(var);
			exit(1);
		}
		s[i][0] = x[i][0];
		s[i][1] = i;
		i++;
	}
	s = bubble_sort(s, len);
	return (s);
}

void	final_move(int a, t_data *x)
{
	int	ud_a;

	ud_a = 0;
	if (a < (stack_len(x->hm_a) - 1) / 2)
		ud_a = 1;
	if (ud_a == 0)
	{
		while (a != (stack_len(x->hm_a) - 1))
		{
			ra(x->a, x, 1);
			a++;
		}
	}
	else
	{
		while (a != -1)
		{
			rra(x->a, x, 1);
			a--;
		}
	}
	pa(x->a, x->b, x->stack_size, x);
}

void	small_stack(t_data *x)
{
	int	i;
	int	**s;

	i = 0;
	while (stack_len(x->hm_b))
	{
		s = stack_clone(x, x->a, stack_len(x->hm_a));
		if (x->b[stack_len(x->hm_b) - 1][0] < s[i][0])
		{
			i = s[i][1];
			free_stack_clone(s, stack_len(x->hm_a));
			final_move(i, x);
			i = 0;
			continue ;
		}
		else if (i == stack_len(x->hm_a) - 1)
		{
			free_stack_clone(s, stack_len(x->hm_a));
			pa(x->a, x->b, x->stack_size, x);
			i = 0;
			continue ;
		}
		free_stack_clone(s, stack_len(x->hm_a));
		i++;
	}
}

int	finder(int index_a, t_data *x)
{
	int	index_b;
	int	len_b;
	int	**s;

	len_b = stack_len(x->hm_b);
	s = stack_clone(x, x->b, stack_len(x->hm_b));
	while (len_b > 0)
	{
		if (x->a[index_a][0] > s[len_b - 1][0])
		{
			x->a[index_a][1] = s[len_b - 1][1];
			index_b = s[len_b - 1][1];
			free_stack_clone(s, stack_len(x->hm_b));
			return (move(index_a, index_b, 0, x));
		}
		len_b--;
	}
	x->a[index_a][1] = s[stack_len(x->hm_b) - 1][1];
	index_b = s[stack_len(x->hm_b) - 1][1];
	free_stack_clone(s, stack_len(x->hm_b));
	return (move(index_a, index_b, 0, x));
}

void	algorithme(t_data *x)
{
	int	i;
	int	len_a;
	int	flag;

	if (stack_len(x->hm_a) <= 3)
	{
		sort(x);
		small_stack(x);
		sort(x);
		return ;
	}
	i = 0;
	len_a = stack_len(x->hm_a) - 1;
	flag = len_a;
	while (len_a >= 0)
	{
		x->a[len_a][2] = finder(len_a, x) + 1;
		if (x->a[flag][2] > x->a[len_a][2])
			flag = len_a;
		len_a--;
	}
	move(flag, x->a[flag][1], 1, x);
	algorithme(x);
}
