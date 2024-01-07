/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:33:28 by naadou            #+#    #+#             */
/*   Updated: 2024/01/07 21:01:34 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	**bubble_sort(int **stack, int len_b)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len_b)
	{
		j = i + 1;
		while (j < len_b)
		{
			if (stack[i][0] > stack[j][0])
			{
				tmp = stack[i][0];
				stack[i][0] = stack[j][0];
				stack[j][0] = tmp;
				tmp = stack[i][1];
				stack[i][1] = stack[j][1];
				stack[j][1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (stack);
}

void	b_sort(int b, t_data *x)
{
	int	ud;

	ud = 0;
	if (b < (stack_len(x->hm_b) - 1) / 2)
		ud = 1;
	if (b == stack_len(x->hm_b) - 1)
		return ;
	else if (ud == 0)
	{
		while (b != stack_len(x->hm_b) - 1)
		{
			rb(x->b, x, 1);
			b++;
		}
	}
	else
	{
		while (b != -1)
		{
			rrb(x->b, x, 1);
			b--;
		}
	}
}

void	a_sort(int a, t_data *x)
{
	int	ud;

	ud = 0;
	if (a < (stack_len(x->hm_a) - 1) / 2)
		ud = 1;
	if (a == stack_len(x->hm_a) - 1)
	{
		return ;
	}
	else if (ud == 0)
	{
		while (a != stack_len(x->hm_a) - 1)
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
}

int	is_a_sorted(t_data *x)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < stack_len(x->hm_a))
	{
		if (x->a[a][0] > x->a[i][0])
			a = i;
		i++;
	}
	a_sort(a, x);
	i = 0;
	while (i < stack_len(x->hm_a) - 1)
	{
		if (x->a[i][0] < x->a[i + 1][0])
			return (0);
		i++;
	}
	return (1);
}

void	sort(t_data *x)
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
	while (is_a_sorted(x) == 0)
		sa(x->a, x);
}
