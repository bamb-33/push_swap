/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:29:01 by naadou            #+#    #+#             */
/*   Updated: 2024/01/04 18:41:37 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	sort(t_data *x)
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
	/*
		- sort both stacks (a ascending order, b descennding order).
		- put integers from stack b to b in so the stack will be sorted
	*/
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (stack_len(x->hm_b))
	{
		if (x->b[stack_len(x->hm_b) - 1][0] > x->a[i][0])
		{
			if (i - 1 < 0)
				i = stack_len(x->hm_a);
			final_move(i - 1, x);
			i = 0;
			continue ;
		}
		else if (i == stack_len(x->hm_a) - 1)
		{
			issorted(x);
			while (stack_len(x->hm_b))
				pa(x->a, x->b, x->stack_size, x);
			break ;
		}
		i++;
	}
}
