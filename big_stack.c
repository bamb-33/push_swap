/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:55:00 by naadou            #+#    #+#             */
/*   Updated: 2024/01/04 19:51:08 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	finder(int len, t_data *x)
{
	/*
		i am looking for the the biggest number that is smaller than this
		number (x->a[len][0]) in stack B.
	*/
	int	i;
	int	len_b;
	int	**s;

	i = 0;
	len_b = stack_len(x->hm_b);
	s = (int **) malloc (sizeof(int *) * len_b);
	while (i < len_b)
	{
		s[i] = (int *) malloc (sizeof(int ) * len_b);
		s[i][0] = x->b[i][0];
		s[i][1] = i;
		i++;
	}
	s = bubble_sort(s, len_b);
	while (len_b > 0)
	{
		if (x->a[len][0] > s[len_b - 1][0])
		{
			x->a[len][1] = s[len_b - 1][1];
			return (move(len, s[len_b - 1][1], 0, x));
		}
		len_b--;
	}
	x->a[len][1] = s[stack_len(x->hm_b) - 1][1];
	return (move(len, s[stack_len(x->hm_b) - 1][1], 0, x));
}

void	algo(t_data *x)
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
		return ;
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
	move(flag, x->a[flag][1],1 ,x);
	algo(x);
}
