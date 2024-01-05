/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:55:00 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 12:04:21 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	**stack_clone(t_data *x)
{
	int	i;
	int	len_b;
	int	**s;

	i = 0;
	len_b = stack_len(x->hm_b);
	s = (int **) malloc (sizeof(int *) * len_b);
	while (i < len_b)
	{
		s[i] = (int *) malloc (sizeof(int ) * 2);
		s[i][0] = x->b[i][0];
		s[i][1] = i;
		i++;
	}
	s = bubble_sort(s, len_b);
	return (s);
}

int	finder(int index_a, t_data *x)
{
	/*
		i am looking for the the biggest number that is smaller than this
		number (x->a[len][0]) in stack B.
	*/
	int	index_b;
	int	len_b;
	int	**s;

	len_b = stack_len(x->hm_b);
	s = stack_clone(x);
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
	/*
		- a way to know how many moves i ll need to move the number
		to its right place so i can choose the number w the lowest number of
		moves.
		- algorithme to actually put the number in its right position.
	*/
	int	i;
	int	len_a;
	int	flag;

	if (stack_len(x->hm_a) <= 3)
	{
		issorted(x);
		small_stack(x);
		issorted(x);
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
